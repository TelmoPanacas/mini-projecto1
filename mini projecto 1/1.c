#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#define MAX 256

void menu();
void preencherMatriz(char matrizMapa[25][25]);
void limparMapa(char matrizMapa[25][25]);

/*ERROS:
        ERRO 2 - Ja mudei de bomb para mine, mas está a escrever o nome do fichero
        ERRO 4 - Devia de dar invalid coordinate, mas não dá, pede para escrever denovo 
        EERO 5 - Nao sei, quando tento plantar e mostrar o mapa sem ler o ficheiro é preciso alguma mensagem de rro?
        ERRO 6 - Nao leu o ficheiro, e nao deu trigger a bomba
        ERRO 7 - Simplesmente inputs
        ERRO 10 - Nao sei, escreve o nome do ficheiro??
        ERRO 13 - Erro 10
        ERRO 14 - Erro 10 e diz que está corrompido
        ERRO 15 - Erro 14
        ERRO 16 - Erro 10
        ERRO 17 - Erro 10
        ERRO 18 - Devia de ser corrompido , mas Erro 10 e faz o mapa
        ERRO 19 - Erro 7
        ERRO 20 - Erro 18
        ERRO 21 - Erro 7
        ERRO 22 - Erro 18
        ERRO 23 - Erro 7
        ERRO 24 - Erro 10
        ERRO 25 - Erro 7
        ERRO 26 - Erro 10

        ERRO 37 - Inouts
        ERRO 39 - Não substituiu os \0 por _
        ERRO 40 - RESOLVIDO



*/

int main(void) {
    
    char opcao[MAX], file_name[MAX], linhaExport[MAX],xExport[MAX], yExport[MAX],cExport[MAX];
    FILE *ficheiroOriginal, *ficheiroExport;
    int podesLerDimensoes = 0, xLinha, xColuna,
        triggerX = 0, triggerY = 0, plantX = 0, plantY = 0;
    
    char linhaCopiada[MAX];
    char file_name_export[MAX];

    
    
    char matrizMapa[25][25] = {
        {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
        {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
        {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
        {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
        {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
        {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
        {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
        {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
        {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
        {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
        {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
        {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
        {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
        {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
        {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
        {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
        {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
        {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
        {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
        {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
        {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
        {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
        {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
        {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
        {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'}};
    
    /*Primeiro menu*/
    menu();
    
    while (1)
    {        
        putchar('>');
        scanf(" %s", opcao);
        
        if (strcmp(opcao, "quit") == 0)
        {

            return 0;

        }else if(strcmp(opcao, "sos") == 0){
            
            menu();

        }else if (strcmp(opcao, "export") == 0)
        {
            int k;
            scanf(" %s", file_name_export);
            ficheiroExport = fopen(file_name_export, "w");
            if (ficheiroExport == NULL)
            {
                fclose(ficheiroOriginal);
                puts("Error opening file");
                exit(EXIT_FAILURE);
            }
            for (k = 0; k < 1; k++)
            {
                int u;
                for (u = 0; u < 3; u++)
                {
                    /*NAO ESTÁ A COPIAR BEM O CARACTER*/
                    sprintf(xExport, " %d", k);
                    sprintf(yExport, " %d", u);
                    cExport[0] = matrizMapa[k][u];
                    
                    puts(yExport);
                    cExport[0] = '\0';
                    strcat(cExport, xExport);
                    strcat(cExport, yExport);
                    strcpy(linhaExport, cExport);
                    fputs(linhaExport, ficheiroExport);
                    
                }
                
            }
            
            fclose(ficheiroExport);
            puts("O ficheiro foi exportado com sucesso");
            
        }else if(strcmp(opcao, "read") == 0)
        {
            scanf(" %s", file_name);
            puts(file_name);
            ficheiroOriginal = fopen(file_name, "r");
            if (ficheiroOriginal == NULL)
            {
                puts("Error openning file");
                exit(EXIT_FAILURE);
            } else {

                /*Ler até ser lido as dimensões do ficheiro*/
                while (podesLerDimensoes == 0 && fgets(linhaCopiada, sizeof(linhaCopiada), ficheiroOriginal))
                {
                    
                    if (linhaCopiada[0] == '#')
                    {
                        continue;                        
                    }
                    
                
                    podesLerDimensoes++;
                }
                         
                
                /*Aqui é lido o resto e adicionado a matriz*/
                while (fgets(linhaCopiada, sizeof(linhaCopiada), ficheiroOriginal))
                {
                    if (linhaCopiada[0] == '#')
                    {
                        continue;                        
                    }else{
                        /*Separar as informações*/
                        char *tipoBomba = strtok(linhaCopiada, " ");
                        char *linha = strtok(NULL, " ");
                        char *coluna = strtok(NULL, " ");
                    
                        if (coluna == NULL || linha == NULL)
                        {
                            puts("\nFile is corrupted");
                            limparMapa(matrizMapa);
                            fclose(ficheiroOriginal);
                        }else{
                    
                        xLinha = atoi(linha);
                        xColuna = atoi(coluna);
                        if (xLinha < 0 || xColuna < 0 || xLinha > 25 || xColuna > 25)
                        {
                            puts("\nFile is corrupted");
                            limparMapa(matrizMapa);
                            fclose(ficheiroOriginal);
                        }
                    
                        matrizMapa[xLinha][xColuna] = tipoBomba[0];
                        }
                    }  
                }               
              
            }
            fclose(ficheiroOriginal);           
            preencherMatriz(matrizMapa);
        }else if(strcmp(opcao, "show") == 0)
        {
            int linhas;
            for (linhas = 0; linhas < 25; linhas++)
            {
                int colunas;
                for (colunas = 0; colunas < 25; colunas++)
                {
                    printf("%c", matrizMapa[linhas][colunas]);
                }
                putchar('\n');
            }
        }else if(strcmp(opcao, "trigger") == 0)
        {
            scanf(" %d", &triggerX);
            scanf(" %d", &triggerY);
            
            if (triggerX > 25 || triggerY >25 || triggerX < 0 || triggerY < 0)
            {
                puts("Invalid coordinate");
            }else {
            
                if (matrizMapa[triggerX][triggerY] == '.')
                {
                    matrizMapa[triggerX][triggerY] = '*';
                }

                if (matrizMapa[triggerX][triggerY] != '.' && matrizMapa[triggerX][triggerY] != '*')
                {
                    puts("No mine at the specified coordinate");
                }
            }
        }else if (strcmp(opcao, "plant") == 0)
        {
            scanf(" %d", &plantX);
            scanf(" %d", &plantY);

                if (plantX > 25 || plantY >25 || plantX < 0 || plantY < 0)
                {
                    puts("Invalid coordinate");
                }else{

                    if (matrizMapa[plantX][plantY] == '*')
                    {
                        matrizMapa[plantX][plantY] = '.';
                    }
                }
            
            }else {
                puts("No such option, returning to menu");
                menu();
            }

    }
    return 0;
}

void menu(){
    /*int i;
    char menu[9][54]={
        {'+','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
        {'r','e','a','d',' ','<','f','i','l','e','n','a','m','e','>',' ',' ',' ',' ',' ','-',' ','r','e','a','d',' ','i','n','p','u','t',' ','f','i','l','e'},
        {'s','h','o','w',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','-',' ','s','h','o','w',' ','t','h','e',' ','m','i','n','e',' ','m','a','p'},
        {'t','r','i','g','g','e','r',' ','<','x','>',' ','<','y','>',' ',' ',' ',' ',' ','-',' ','t','r','i','g','g','e','r',' ','m','i','n','e',' ','a','t',' ','<','x','>',' ','<','y','>'},
        {'p','l','a','n','t',' ','<','x','>',' ','<','y','>',' ',' ',' ',' ',' ',' ',' ','-',' ','p','l','a','c','e',' ','a','r','m','e','d',' ','m','i','n','e',' ','a','t',' ','<','x','>',' ','<','y','>'},
        {'e','x','p','o','r','t',' ','<','f','i','l','e','n','a','m','e','>',' ',' ',' ','-',' ','s','a','v','e',' ','f','i','l','e',' ','w','i','t','h',' ','c','u','r','r','e','n','t',' ','m','a','p'},
        {'q','u','i','t',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','-',' ','e','x','i','t',' ','p','r','o','g','r','a','m'},
        {'s','o','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','-','s','h','o','w',' ','m','e','n','u'},
        {'+','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'}};

    putchar('\n');
    
    for (i = 0; i < 9; i++)
    {
        int j;
        for (j = 0; j < 54 ; j++)
        {
            printf("%c", menu[i][j]);
        }
        putchar('\n');
    }
    */
   puts("+-----------------------------------------------------");
   puts("read <filename>     - read input file");
   puts("show                - show the mine map");
   puts("trigger <x> <y>     - trigger mine at <x> <y>");
   puts("plant <x> <y>       - place armed mine at <x> <y>");
   puts("export <filename>   - save file with current map");
   puts("quit                - exit program");
   puts("sos                 - show menu");
   puts("+-----------------------------------------------------");
}

void preencherMatriz(char matrizMapa[25][25])
{
    int linhas;
    for (linhas = 0; linhas < 25; linhas++)
    {
        int colunas;
        for (colunas = 0; colunas < 25; colunas++)
        {
            if (matrizMapa[linhas][colunas] == '\0')
            {
                matrizMapa[linhas][colunas] = '_';
            }            
        }        
    }
}

void limparMapa(char matrizMapa[25][25])
{
    int i;
    for (i = 0; i < 25; i++)
    {
        int j;
        for (j = 0; j < 25; j++)
        {
            matrizMapa[i][j] = '\0';
        }
        
    }
    
}
