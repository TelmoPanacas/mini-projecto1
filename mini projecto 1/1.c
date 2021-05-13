#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#define MAX 256

void menu();
void preencherMatriz(char matrizMapa[25][25]);
void limparMapa(char matrizMapa[25][25]);
int verFicheiroTexto(char file_name[MAX]);


int main(void) {
    
    char opcao[MAX], file_name[MAX], linhaExport[MAX],xExport[MAX], yExport[MAX],cExport[MAX];
    FILE *ficheiroOriginal, *ficheiroExport;
    int podesLerDimensoes = 0,triggerX = -1, triggerY = -1, plantX = -1, plantY = -1;
    
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
                fclose(ficheiroOriginal);
                puts("Error opening file");
                exit(EXIT_FAILURE);
            }
            for (k = 0; k < 25; k++)
            {
                int u;
                for (u = 0; u < 25; u++)
                {
                    /*NAO ESTÁ A COPIAR BEM O CARACTER*/
                    sprintf(xExport, " %d", k);
                    sprintf(yExport, " %d", u);
                    cExport[0] = matrizMapa[k][u];
                    
                    /*
                    printf("%s\n", cExport);
                    puts(xExport);
                    puts(yExport);
                    */
                    strcpy(linhaExport,cExport);
                    strcat(linhaExport, " ");
                    strcat(linhaExport,xExport);
                    strcat(linhaExport, " ");
                    strcat(linhaExport, yExport);
                    
                    
                    fputs(linhaExport, ficheiroExport);
                    fputc('\n',ficheiroExport);
                    
                }
                
            }
            
            fclose(ficheiroExport);
            
        }else if(strncmp(opcao, "read", 4) == 0)
        {    
            int n,k,linha,coluna;
            char tipoBomba;
            n = sscanf(opcao,"%*s %s", file_name);
            if (n != 1)
            {
                puts("Invalid command!");
                continue;
            }
            
            ficheiroOriginal = fopen(file_name, "r");
            if (ficheiroOriginal == NULL)
            {                
                puts("Error openning file");
                exit(EXIT_FAILURE);
            } else if (verFicheiroTexto(file_name) == 1)
            {
                                    /*ACHO QUE ISTO TRATA TO ERRO 34*/
                puts("Error openning file");
                exit(EXIT_FAILURE);
            } else {

                /*Ler até ser lido as dimensões do ficheiro*/
                /*PERGUNTAR AO STOR, NAO ESTÁ A IGNORAR LINHAS BRANCAS*/
                while (podesLerDimensoes == 0 && fgets(linhaCopiada, sizeof(linhaCopiada), ficheiroOriginal))
                {
                    
<<<<<<< HEAD
                    if (linhaCopiada[0] == '#' || linhaCopiada[0] == '\0' || linhaCopiada[0] == '\n' || linhaCopiada[0] == '\r')
=======
                    if (linhaCopiada[0] == '#' || linhaCopiada[0] == '\n')
>>>>>>> 980f068ec447ec9fdb1cc3ed32f699dd480ec279
                    {
                        continue;                        
                    }
                    
                
                    podesLerDimensoes++;
                }
                         
                
                /*Aqui é lido o resto e adicionado a matriz*/
                while (fgets(linhaCopiada, sizeof(linhaCopiada), ficheiroOriginal))
                {

                    /*PORQUE É QUE NÃO ESTÁ A IGNORAR AS LINHAS BRANCAS?*/

<<<<<<< HEAD
                    if (linhaCopiada[0] == '#' || linhaCopiada[0] == '\0' || linhaCopiada[0] == '\n' || linhaCopiada[0] == '\r')
=======
                    if (linhaCopiada[0] == '#' || linhaCopiada[0] == '\n')
>>>>>>> 980f068ec447ec9fdb1cc3ed32f699dd480ec279
                    {
                        continue;                        
                    }
                        
                        /*Separar as informações*/
                        k = sscanf(linhaCopiada, " %c %d %d", &tipoBomba, &linha, &coluna);
                        if (k != 3)
                        {
                            puts("File is corrupted");
                            limparMapa(matrizMapa);
                            fclose(ficheiroOriginal);
                        }else{
                    
                            if ((linha < 0 || linha > 24) && (coluna < 0 || coluna > 24))
                            {
                                puts("File is corrupted");
                                limparMapa(matrizMapa);
                                fclose(ficheiroOriginal);
                            }else {
                                matrizMapa[linha][coluna] = tipoBomba;
                            }
                        }
                     
                    
                }               
                
            }
            fclose(ficheiroOriginal);           
            preencherMatriz(matrizMapa);
        }else if(strncmp(opcao, "show", 4) == 0)
        {
            int linhas;
            preencherMatriz(matrizMapa);
            
            for (linhas = 0; linhas < 25; linhas++)
            {
                int colunas;
                for (colunas = 0; colunas < 25; colunas++)
                {
                    printf("%c", matrizMapa[linhas][colunas]);
                }
                putchar('\n');
            }
        }else if(strncmp(opcao, "trigger", 7) == 0)
        {
            int n;
            n = sscanf(opcao,"%*s %d %d", &triggerX, &triggerY);
            if (n != 2)
            {
                puts("Invalid coordinate");
                continue;
            }
            
            if (triggerX > 24 || triggerY >24 || triggerX < 0 || triggerY < 0)
            {
                puts("Invalid coordinate");
            }else {
        
                if (matrizMapa[triggerX][triggerY] == '.')
                {
                    matrizMapa[triggerX][triggerY] = '*';
                }

                if (matrizMapa[triggerX][triggerY] != '.' && matrizMapa[triggerX][triggerY] != '*')
                {
                    puts("No mine at specified coordinate");
                }
            }
            
        }else if (strncmp(opcao, "plant",5) == 0)
        {
            int n;
            preencherMatriz(matrizMapa);
            n = sscanf(opcao, "%*s %d %d", &plantX, &plantY);
            if (n != 2)
            {
                puts("Invalid coordinate");
                continue;
            }

            if (plantX > 24 || plantY >24 || plantX < 0 || plantY < 0 )
            {
                puts("Invalid coordinate");
            }else{
                if (matrizMapa[plantX][plantY] == '*')
                {
                    matrizMapa[plantX][plantY] = '.';
                }
                if (matrizMapa[plantX][plantY] == '_')
                {
                    matrizMapa[plantX][plantY] = '.';
                }
                
            }
            
        }else {
            puts("Invalid command!");        
        }

    }
    return 0;
}

void menu(){
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

int verFicheiroTexto(char file_name[MAX]){
    int i;
    char tipoFicheiro[MAX] = "";
    for (i = strlen(file_name)-4; file_name[i] != '\0'; i++)
    {
        strncat(tipoFicheiro, &file_name[i], 1);
    }
    if (strcmp(tipoFicheiro, ".txt") == 0 || strcmp(tipoFicheiro, ".ini") == 0)
    {
        return 0;
    }else {
        return 1;
    }
    
}
