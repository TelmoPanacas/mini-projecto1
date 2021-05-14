#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#define MAX 256

void menu();
void preencherMatriz(char matrizMapa[25][25]);
void limparMapa(char matrizMapa[25][25]);



int main(void) {
    
    char opcao[MAX], file_name[MAX];
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
                fclose(ficheiroOriginal);
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
            
        }else if(strncmp(opcao, "read", 4) == 0)
        {    
            int n,k,linha,coluna,matrizX,matrizY,j;
            char tipoBomba;
            n = sscanf(opcao,"%*s %s", file_name);
            podesLerDimensoes = 0;
            limparMapa(matrizMapa);
            if (n != 1)
            {
                puts("Invalid command!");
                continue;
            }
            
            ficheiroOriginal = fopen(file_name, "r");
            if (ficheiroOriginal == NULL)
            {                
                puts("Error opening file");
                continue;
            }
            else {

                /*Ler até ser lido as dimensões do ficheiro*/
                while (podesLerDimensoes == 0 && fgets(linhaCopiada, sizeof(linhaCopiada), ficheiroOriginal))
                {
                    
                    if (linhaCopiada[0] == '#' || linhaCopiada[0] == '\0' || linhaCopiada[0] == '\n' || linhaCopiada[0] == '\r')
                    {
                        continue;                        
                    }
                    j = sscanf(linhaCopiada, " %d %d", &matrizX, &matrizY);
                    if ((j != 2))
                    {
                        puts("File is corrupted");
                        limparMapa(matrizMapa);
                        fclose(ficheiroOriginal);

                    }else if ((matrizX != 25 || matrizY != 25))
                    {
                        puts("File is corrupted");
                        limparMapa(matrizMapa);
                        fclose(ficheiroOriginal);
                    }
                    
                    
                    podesLerDimensoes++;
                }
                         
                
                /*Aqui é lido o resto e adicionado a matriz*/
                while (fgets(linhaCopiada, sizeof(linhaCopiada), ficheiroOriginal))
                {

                    /*PORQUE É QUE NÃO ESTÁ A IGNORAR AS LINHAS BRANCAS?*/

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
                        fclose(ficheiroOriginal);
                    }
                    else if (linha < 0 || linha > 24 || coluna < 0 || coluna > 24)
                    {              
                        puts("File is corrupted");
                        limparMapa(matrizMapa);
                        fclose(ficheiroOriginal);
                    }else if (tipoBomba != '*' && tipoBomba != '.')
                    {
                        puts("File is corrupted");
                        limparMapa(matrizMapa);
                        fclose(ficheiroOriginal);
                    }
                    
                    else {
                        matrizMapa[linha][coluna] = tipoBomba;
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

