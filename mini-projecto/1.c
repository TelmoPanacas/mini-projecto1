#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "messages.h"
#define MAX 256

void menu();
void preencherMatriz(char matrizMapa[25][25]);
void limparMapa(char matrizMapa[25][25]);
void lerFicheiro(char file_name[MAX], char matrizMapa[25][25]);


int main(int argc, char* argv[]) {
    
    char opcao[MAX], file_name[MAX];
    FILE *ficheiroExport;
    int triggerX = -1, triggerY = -1, plantX = -1, plantY = -1;

    
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
    

    if (argc != 2)
    {
        puts(MSG_FNAME);
        return 0;
    }else {
        strcpy(file_name, argv[1]);
        lerFicheiro(file_name, matrizMapa);
    }
    
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
            char dimensoes[MAX] = "25 25";
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

            fputs(dimensoes,ficheiroExport);
            fputc('\n',ficheiroExport);
            for (k = 0; k < 25; k++)
            {
                int u;
                for (u = 0; u < 25; u++)
                {
                    
                    
                    if (matrizMapa[k][u] == '.' || matrizMapa[k][u] == '*')
                    {
                        fprintf(ficheiroExport, "%c %d %d\n",matrizMapa[k][u],k, u);
                    }
                    
                    
                    
                }
                
            }
            
            fclose(ficheiroExport);
            
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

void lerFicheiro(char file_name[MAX], char matrizMapa[25][25])
{
    FILE *ficheiroPtr;
    int k, linha,coluna,matrizX,matrizY,j;
    char tipoBomba;
    char linhaCopiada[MAX];
    int podesLerDimensoes = 0;
    limparMapa(matrizMapa);
    
    ficheiroPtr = fopen(file_name, "r");
    if (ficheiroPtr == NULL)
    {
        puts(MSG_FNAME);
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
                puts(MSG_FILE_CRP);
                limparMapa(matrizMapa);
                fclose(ficheiroPtr);
            } else if (matrizX < 0 || matrizY < 0)
            {
                puts(MSG_FILE_CRP);
                limparMapa(matrizMapa);
                fclose(ficheiroPtr);
            }

            podesLerDimensoes++; 
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
                    puts("File is corrupted");
                    limparMapa(matrizMapa);
                    fclose(ficheiroPtr);
                }
                else if (linha < 0 || linha > 24 || coluna < 0 || coluna > 24)
                {              
                    puts("File is corrupted");
                    limparMapa(matrizMapa);
                    fclose(ficheiroPtr);
                }else if (tipoBomba != '*' && tipoBomba != '.')
                {
                    puts("File is corrupted");
                    limparMapa(matrizMapa);
                    fclose(ficheiroPtr);
                }
                else {
                    matrizMapa[linha][coluna] = tipoBomba;
                }
            }               
                
        }
        fclose(ficheiroPtr);           
        preencherMatriz(matrizMapa);
        
}