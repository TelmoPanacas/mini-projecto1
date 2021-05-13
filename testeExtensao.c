#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#define MAX 256
#define txt 4


int verFicheiroTexto(char file_name[MAX]);

void main() 
{
    int teste = 0;
    char nomeFicheiro[MAX];
    char tipoFicheiro[MAX] = "";
    scanf(" %s", nomeFicheiro);

    teste = verFicheiroTexto(nomeFicheiro);
    if (teste == 0)
    {
        puts("É extensão texto");
    } else {
        puts("Não é extensão texto");
    }
    



    /*
    for (int i = strlen(nomeFicheiro)-4; nomeFicheiro[i] != '\0'; i++)
    {
        strncat(tipoFicheiro, &nomeFicheiro[i], 1);
    }
    puts(tipoFicheiro);
    */

}

int verFicheiroTexto(char file_name[MAX]){
    int i;
    char tipoFicheiro[MAX] = "";
    for (i = strlen(file_name)-4; file_name[i] != '\0'; i++)
    {
        strncat(tipoFicheiro, &file_name[i], 1);
    }
    if (strcmp(tipoFicheiro, ".txt") == 0)
    {
        return 0;
    }else {
        return 1;
    }
    
}