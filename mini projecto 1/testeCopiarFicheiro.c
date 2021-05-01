#include <stdio.h>
#include <stdlib.h>
#define MAX 64

void main(void)
{
    char letra, ficheiroOriginal[MAX], ficheiroCopia[MAX];
    FILE *original, *copia;

    printf("Nome do ficheiro a copiar\n");
    scanf(" %s", ficheiroOriginal);

    original = fopen(ficheiroOriginal, "r");

    if (original == NULL)
    {
        printf("%s não existe\n", ficheiroOriginal);
        exit(EXIT_FAILURE);
    }

    printf("Nome do ficheiro copiado\n");
    scanf(" %s", ficheiroCopia);

    copia = fopen(ficheiroCopia, "w");

    if (copia == NULL)
    {
        fclose(original);
        printf("Erro\n");
        exit(EXIT_FAILURE);
    }

    /* Está a ler letra a letra*/
    
    while ((letra = fgetc(original)) != EOF)
    {
        fputc(letra, copia);
    }
    printf("Ficheiro %s copiado com sucesso para %s\n", ficheiroOriginal, ficheiroCopia);
    fclose(original);
    fclose(copia);
     

}