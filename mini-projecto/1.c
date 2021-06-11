#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "messages.h"
#define MAX 256

void menu();
char ** lerFicheiro(char file_name[MAX], int *matrizX, int *matrizY);

typedef struct {
        char tipoDeBomba;
        int coordX;
        int coordY;
        Bomba * next;
}Bomba;

int main(int argc, char* argv[]) {
    char **matriz = NULL;
    char opcao[MAX], file_name[MAX];
    FILE *ficheiroExport;
    int triggerX = -1, triggerY = -1, plantX = -1, plantY = -1, matrizX, matrizY;

    char file_name_export[MAX];

    if (argc != 2)
    {
        puts(MSG_FNAME);
        return 0;
    }else {
        strcpy(file_name, argv[1]);
        matriz = lerFicheiro(file_name, &matrizX, &matrizY);
    }
    printf("MatrizY = %d\t\t MatrizX = %d\n", matrizY, matrizX);
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
        }else if(strncmp(opcao, "trigger", 7) == 0)
        {
            int n;
            n = sscanf(opcao,"%*s %d %d", &triggerX, &triggerY);
            if (n != 2)
            {
                puts("Invalid coordinate");
                continue;
            }
            
            if (triggerX > matrizX-1 || triggerY >matrizY-1 || triggerX < 0 || triggerY < 0)
            {
                puts("Invalid coordinate");
            }else {
        
                if (matriz[triggerX][triggerY] == '.')
                {
                    matriz[triggerX][triggerY] = '*';
                }

                if (matriz[triggerX][triggerY] != '.' && matriz[triggerX][triggerY] != '*')
                {
                    puts("No mine at specified coordinate");
                }
            }
            
        }else if (strncmp(opcao, "plant",5) == 0)
        {
            int n;
            n = sscanf(opcao, "%*s %d %d", &plantX, &plantY);
            if (n != 2)
            {
                puts("Invalid coordinate");
                continue;
            }

            if (plantX > matrizX-1 || plantY >matrizY-1 || plantX < 0 || plantY < 0 )
            {
                puts("Invalid coordinate");
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
            
        }else {
            puts("Invalid command!");        
        }

    }
    return 0;
}

void menu(){
   puts("+-----------------------------------------------------");
   puts("show                - show the mine map");
   puts("propagate <x> <y>   - explode bomb at <x> <y>");
   puts("log <x> <y>	    - explode bomb at <x> <y>");
   puts("plant <x> <y>       - place armed mine at <x> <y>");
   puts("export <filename>   - save file with current map");
   puts("quit                - exit program");
   puts("sos                 - show menu");
   puts("+-----------------------------------------------------");
}


char ** lerFicheiro(char file_name[MAX], int* enderecoMatrizX, int* enderecoMatrizY)
{
    char ** mapa;
    FILE *ficheiroPtr;
    int u,i,k, linha,coluna,matrizX = 0,matrizY = 0,j;
    char tipoBomba;
    char linhaCopiada[MAX];
    int podesLerDimensoes = 0;
    
    Bomba teste;
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
                fclose(ficheiroPtr);
                exit(0);
            } else if (matrizX < 0 || matrizY < 0)
            {
                puts(MSG_FILE_CRP);
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
                    puts("File is corrupted");
                    fclose(ficheiroPtr);
                }
                else if (linha < 0 || linha > matrizX || coluna < 0 || coluna > matrizY)
                {              
                    puts("File is corrupted");
                    fclose(ficheiroPtr);
                }else if (tipoBomba != '*' && tipoBomba != '.')
                {
                    puts("File is corrupted");
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


