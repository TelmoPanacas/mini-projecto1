#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#define MAX 256

/*
    Fazer lista ligada
*/
struct Bomba
{
    int tempo;
    int posicaoX;
    int posicaoY;
    struct Bomba *next;
};

typedef struct Bomba* node; /*Definir node como um pointer para tipo bomba*/

/*Criar um node*/
node createNode(){
    node temp; /*Declarar um node*/
    temp = (node)malloc(sizeof(struct Bomba));/*Alocar memória*/
    temp->next = NULL;/*Fazer com que temp fique como último da lista, pois o ultimo node aponta sempre para NULL*/
    return temp;
}

/*Adicionar o node à fila*/
node addNode(node head, int tempo, int posicaoX, int posicaoY){
    node temp, p;
    temp = createNode(); /*createNode vai retornar um node que aponta par NULL*/
    temp->tempo = tempo;            /*Vai adicionar os valores da bomba lida para o node*/
    temp->posicaoX = posicaoX;
    temp->posicaoY = posicaoY;
    
    if (head == NULL) /*Quando a lista está vazia*/
    {
        head = temp;
    }
    else{
        p = head;
        while (p->next != NULL)
        {
            p = p->next;/*Vai percorrer a lista toda encontrar o ultimo node*/
        }
        p->next = temp;/*Faz com que o último node da lista aponte para o temp fazendo com que temp seja o ultimo da lista agora*/
    }

    return head;
    
}

struct ListaLigada
{
    node head;
}lista;



void menu();
char ** lerFicheiro(char file_name[MAX], int *matrizX, int *matrizY, int* erro);
void triggerLog(int posicaoX, int posicaoY, char** matriz, int matrizX, int matrizY);
void triggerPropagate(int posicaoX, int posicaoY, char** matriz, int matrizX, int matrizY, int *timer);
void procurarBombasEExplodirHeadLog(char** matriz, int matrizX, int matrizY);
void procurarBombasEExplodirHeadPropagate(char** matriz, int matrizX, int matrizY, int *timer);
void apagarHead();
void show(char **matriz, int matrizX, int matrizY);

int main(int argc, char* argv[]) {
    char **matriz = NULL;
    char opcao[MAX], file_name[MAX];
    FILE *ficheiroExport;
    int plantX = -1, plantY = -1, matrizX, matrizY, erro, timer = 0;


    char file_name_export[MAX];

    if (argc != 2)
    {
        puts("Error: missing file name");
        return 0;
    }else {
        strcpy(file_name, argv[1]);
        matriz = lerFicheiro(file_name, &matrizX, &matrizY, &erro);
    }

    if (erro == 1)
    {
        return 0;
    }
    
    /*Primeiro menu*/
    menu();
    
    /*
    lista.head = addNode(lista.head, 0, matriz[0][3], 0, 3);
    printf("Tipo de bomba = %c , Tempo de explosão = %d , CoordX = %d , CoordY = %d\n", lista.head->tipoBomba,lista.head->tempo,lista.head->posicaoX,lista.head->posicaoY);
    lista.head = addNode(lista.head, 16, matriz[0][4], 0, 4);
    puts("Bomba a seguir");
    printf("Tipo de bomba = %c , Tempo de explosão = %d , CoordX = %d , CoordY = %d\n", lista.head->next->tipoBomba,lista.head->next->tempo,lista.head->next->posicaoX,lista.head->next->posicaoY);
    */


    while (1)
    {        
        putchar('>');
        fgets(opcao,128,stdin);
        
        if (strncmp(opcao, "quit", 4) == 0)
        {

            return 0;

        }else if(strncmp(opcao, "sos", 3) == 0){
            
            menu();

        }else if (strncmp(opcao, "export", 6) == 0)
        {
            int k,n;
            n = sscanf(opcao,"%*s %s", file_name_export);
            if (n != 1)
            {
                puts("Invalid command!");
                continue;
            }
            
            ficheiroExport = fopen(file_name_export, "w");
            if (ficheiroExport == NULL)
            {
                puts("Error opening file");
                exit(EXIT_FAILURE);
            }

            fprintf(ficheiroExport, "%d %d\n",matrizX, matrizY);
            for (k = 0; k < matrizX; k++)
            {
                int u;
                for (u = 0; u < matrizY; u++)
                {
                    
                    
                    if (matriz[k][u] == '.' || matriz[k][u] == '*')
                    {
                        fprintf(ficheiroExport, "%c %d %d\n",matriz[k][u],k, u);
                    }                    
                }
                
            }
            
            fclose(ficheiroExport);
            
        }else if(strncmp(opcao, "show", 4) == 0)
        {
            show(matriz, matrizX, matrizY);
   
        }else if (strncmp(opcao, "plant",5) == 0)
        {
            int n;
            n = sscanf(opcao, "%*s %d %d", &plantX, &plantY);
            if (n != 2)
            {
                puts("Error: invalid coordinate");
                continue;
            }

            if (plantX > matrizX-1 || plantY >matrizY-1 || plantX < 0 || plantY < 0 )
            {
                puts("Error: invalid coordinate");
            }else{
                if (matriz[plantX][plantY] == '*')
                {
                    matriz[plantX][plantY] = '.';
                }
                if (matriz[plantX][plantY] == '_')
                {
                    matriz[plantX][plantY] = '.';
                }
                
            }
            
        }else if(strncmp(opcao, "log",3) == 0){
            int n, logX, logY;
            n = sscanf(opcao, "%*s %d %d", &logX, &logY);
            if (n != 2)
            {
                puts("Error: invalid coordinate");
                continue;
            }
            if (logX > matrizX-1 || logY > matrizY-1 || logX < 0 || logY < 0 )
            {
                puts("Error: invalid coordinate");
            }else {
                if (matriz[logX][logY] == '_')
                {
                    puts("Error: no bomb at specified coordinate");
                    continue;
                }
                triggerLog(logX, logY, matriz, matrizX, matrizY);
            }
            
            
        }else if (strncmp(opcao, "propagate", 9) == 0)
        {
            int n, logX, logY;
            n = sscanf(opcao, "%*s %d %d", &logX, &logY);
            if (n != 2)
            {
                puts("Error: invalid coordinate");
                continue;
            }
            if (logX > matrizX-1 || logY > matrizY-1 || logX < 0 || logY < 0 )
            {
                puts("Error: invalid coordinate");
            }else {
                if (matriz[logX][logY] == '_')
                {
                    puts("Error: no bomb at specified coordinate");
                    continue;
                }
                triggerPropagate(logX, logY, matriz, matrizX, matrizY, &timer);
            }
        }
        
        else {
            puts("Invalid command!");        
        }

    }
    return 0;
}

void menu(){
   puts("+-----------------------------------------------------+");
   puts("show                - show the mine map");
   puts("propagate <x> <y>   - explode bomb at <x> <y>");
   puts("log <x> <y>         - explode bomb at <x> <y>");
   puts("plant <x> <y>       - place bomb at <x> <y>");
   puts("export <filename>   - save file with current map");
   puts("quit                - exit program");
   puts("sos                 - show menu");
   puts("+-----------------------------------------------------+");
}


char ** lerFicheiro(char file_name[MAX], int* enderecoMatrizX, int* enderecoMatrizY, int* erro)
{
    char ** mapa;
    FILE *ficheiroPtr;
    int u,i,k, linha,coluna,matrizX = 0,matrizY = 0,j;
    char tipoBomba;
    char linhaCopiada[MAX];
    int podesLerDimensoes = 0;
    
    ficheiroPtr = fopen(file_name, "r");
    if (ficheiroPtr == NULL)
    {
        puts("Error: could not open file");
        exit(0);
    }
    else{

        while (podesLerDimensoes == 0 && fgets(linhaCopiada, sizeof(linhaCopiada), ficheiroPtr))
        {
            if (linhaCopiada[0] == '#' || linhaCopiada == '\0' || linhaCopiada[0] == '\n' || linhaCopiada[0] == '\r')
            {
                continue;
            }
            j = sscanf(linhaCopiada, " %d %d", &matrizX, &matrizY);
            if (j != 2)
            {
                puts("Error: invalid map dimensions");
                *erro = 1;
                fclose(ficheiroPtr);
                exit(0);
            } else if (matrizX < 1 || matrizY < 1)
            {
                puts("Error: invalid map dimensions");
                *erro = 1;
                fclose(ficheiroPtr);
                exit(0);
            }else {
                podesLerDimensoes++; 
            }
        
            
        }
        *enderecoMatrizX = matrizX;
        *enderecoMatrizY = matrizY;


        mapa = (char **) malloc(matrizX  *sizeof(char*));
            for (i = 0; i < matrizX; i++)
            {
                mapa[i] = (char *) malloc(matrizY * sizeof(char));
                for (u = 0; u < matrizY; u++)
                {
                    mapa[i][u] = '_';
                }
                
            }

        while (fgets(linhaCopiada, sizeof(linhaCopiada), ficheiroPtr))
            {
                if (linhaCopiada[0] == '#' || linhaCopiada[0] == '\0' || linhaCopiada[0] == '\n' || linhaCopiada[0] == '\r')
                {
                    continue;                        
                }
                        
                /*Separar as informações*/
                k = sscanf(linhaCopiada, " %c %d %d", &tipoBomba, &linha, &coluna);
                if (k != 3)
                {
                    puts("Error: file is corrupted");
                    *erro = 1;
                    fclose(ficheiroPtr);
                }
                else if (linha < 0 || linha > matrizX-1 || coluna < 0 || coluna > matrizY-1)
                {              
                    puts("Error: file is corrupted");
                    *erro = 1;
                    fclose(ficheiroPtr);
                }else if (tipoBomba != '*' && tipoBomba != '.')
                {
                    puts("Error: file is corrupted");
                    *erro = 1;
                    fclose(ficheiroPtr);
                }
                else {
                    mapa[linha][coluna] = tipoBomba;
                }
            }               
                
        }
    fclose(ficheiroPtr);           
    return mapa;
}


void triggerLog(int posicaoX, int posicaoY, char** matriz, int matrizX, int matrizY){
    lista.head = addNode(lista.head, 0, posicaoX, posicaoY);
    while (lista.head != NULL)
    {
        procurarBombasEExplodirHeadLog(matriz, matrizX, matrizY);
    }
    
}

void procurarBombasEExplodirHeadLog(char **matriz, int matrizX, int matrizY){
    int coordHeadX = lista.head->posicaoX;
    int coordHeadY = lista.head->posicaoY;
    
    /*Posicao em Cima*/
    if (coordHeadX > 0)
    {    
        if (matriz[coordHeadX-1][coordHeadY]=='.')
        {
            lista.head = addNode(lista.head, lista.head->tempo+10,coordHeadX-1, coordHeadY);
        }
    }
    /*Posicao Diagonal Superior Esquerda*/
    if (coordHeadX > 0 && coordHeadY > 0)
    {   
        if (matriz[coordHeadX-1][coordHeadY-1]=='.')
        {
            lista.head = addNode(lista.head, lista.head->tempo+11,coordHeadX-1, coordHeadY-1);
        }
    }
    /*Posicao Esquerda*/
    if (coordHeadY > 0)
    {
        if (matriz[coordHeadX][coordHeadY-1]=='.')
        {
            lista.head = addNode(lista.head, lista.head->tempo+12,coordHeadX, coordHeadY-1);
        }
    }
    /*Posicao Diagonal Inferior Esquerda*/
    if (coordHeadY > 0 && coordHeadX < matrizX){
        if (matriz[coordHeadX+1][coordHeadY-1]=='.')
        {
            lista.head = addNode(lista.head, lista.head->tempo+13,coordHeadX+1, coordHeadY-1);
        }
    }
    /*Posicao em Baixo*/
    if (coordHeadX < matrizX)
    {    
        if (matriz[coordHeadX+1][coordHeadY]=='.')
        {
            lista.head = addNode(lista.head, lista.head->tempo+14,coordHeadX+1, coordHeadY);
        } 
    }
    /*Posicao Diagonal Inferior Direita*/
    if (coordHeadX < matrizX && coordHeadY < matrizY)
    {       
        if (matriz[coordHeadX+1][coordHeadY+1]=='.')
        {
            lista.head = addNode(lista.head, lista.head->tempo+15,coordHeadX+1, coordHeadY+1);
        }
    }
    /*Posicao Direita*/
    if (coordHeadY< matrizY)
    {    
        if (matriz[coordHeadX][coordHeadY+1]=='.')
        {
            lista.head = addNode(lista.head, lista.head->tempo+16,coordHeadX, coordHeadY+1);
        }
    }
    /*Posicao Diagonal Superior Direita*/
    if (coordHeadY < matrizY && coordHeadX > 0)
    {
        if (matriz[coordHeadX-1][coordHeadY+1]=='.')
        {
            lista.head = addNode(lista.head, lista.head->tempo+17,coordHeadX-1, coordHeadY+1);
        }
    }
    if (matriz[coordHeadX][coordHeadY] != '*')
    {
        matriz[coordHeadX][coordHeadY] = '*';
        printf("%d [%d, %d]\n",lista.head->tempo, lista.head->posicaoX, lista.head->posicaoY);
    }
    apagarHead();
}
void apagarHead(){
    node temp = createNode();
    temp = lista.head;
    lista.head = temp->next;
    free(temp);

}
void show(char **matriz, int matrizX, int matrizY){
    int linhas;
            for (linhas = 0; linhas < matrizX; linhas++)
            {
                int colunas;
                for (colunas = 0; colunas < matrizY; colunas++)
                {
                    printf("%c", matriz[linhas][colunas]);
                }
                putchar('\n');
            }
}
void triggerPropagate(int posicaoX, int posicaoY, char** matriz, int matrizX, int matrizY, int *timer){
    lista.head = addNode(lista.head, *timer, posicaoX, posicaoY);
    while (lista.head != NULL)
    {
        procurarBombasEExplodirHeadPropagate(matriz, matrizX, matrizY, timer);
    }
}
void procurarBombasEExplodirHeadPropagate(char** matriz, int matrizX, int matrizY, int *timer){
     int coordHeadX = lista.head->posicaoX;
    int coordHeadY = lista.head->posicaoY;
    
    /*Posicao em Cima*/
    if (coordHeadX > 0)
    {    
        if (matriz[coordHeadX-1][coordHeadY]=='.')
        {
            lista.head = addNode(lista.head, lista.head->tempo+10,coordHeadX-1, coordHeadY);
        }
    }
    /*Posicao Diagonal Superior Esquerda*/
    if (coordHeadX > 0 && coordHeadY > 0)
    {   
        if (matriz[coordHeadX-1][coordHeadY-1]=='.')
        {
            lista.head = addNode(lista.head, lista.head->tempo+11,coordHeadX-1, coordHeadY-1);
        }
    }
    /*Posicao Esquerda*/
    if (coordHeadY > 0)
    {
        if (matriz[coordHeadX][coordHeadY-1]=='.')
        {
            lista.head = addNode(lista.head, lista.head->tempo+12,coordHeadX, coordHeadY-1);
        }
    }
    /*Posicao Diagonal Inferior Esquerda*/
    if (coordHeadY > 0 && coordHeadX < matrizX){
        if (matriz[coordHeadX+1][coordHeadY-1]=='.')
        {
            lista.head = addNode(lista.head, lista.head->tempo+13,coordHeadX+1, coordHeadY-1);
        }
    }
    /*Posicao em Baixo*/
    if (coordHeadX < matrizX)
    {    
        if (matriz[coordHeadX+1][coordHeadY]=='.')
        {
            lista.head = addNode(lista.head, lista.head->tempo+14,coordHeadX+1, coordHeadY);
        } 
    }
    /*Posicao Diagonal Inferior Direita*/
    if (coordHeadX < matrizX && coordHeadY < matrizY)
    {       
        if (matriz[coordHeadX+1][coordHeadY+1]=='.')
        {
            lista.head = addNode(lista.head, lista.head->tempo+15,coordHeadX+1, coordHeadY+1);
        }
    }
    /*Posicao Direita*/
    if (coordHeadY< matrizY)
    {    
        if (matriz[coordHeadX][coordHeadY+1]=='.')
        {
            lista.head = addNode(lista.head, lista.head->tempo+16,coordHeadX, coordHeadY+1);
        }
    }
    /*Posicao Diagonal Superior Direita*/
    if (coordHeadY < matrizY && coordHeadX > 0)
    {
        if (matriz[coordHeadX-1][coordHeadY+1]=='.')
        {
            lista.head = addNode(lista.head, lista.head->tempo+17,coordHeadX-1, coordHeadY+1);
        }
    }
    if (matriz[coordHeadX][coordHeadY] != '*')
    {
        matriz[coordHeadX][coordHeadY] = '*';
        show(matriz, matrizX,matrizY);
        printf("%d [%d, %d]\n",lista.head->tempo, lista.head->posicaoX, lista.head->posicaoY);
        puts("\n");
    }
    apagarHead();
    *timer = lista.head->tempo;
    
}