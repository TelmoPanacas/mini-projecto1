#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

int main(void)
{
    char linha[MAX], file_name[MAX];
    FILE *fp;

    printf("Nome do ficheiro: \n");
    scanf(" %s", file_name);
    char array_Nomes [MAX][MAX];
    int array_Notas[MAX];
    int posicao = 0, nota = 0, i, notaMaior=0;
    double nPessoas=0, totalNotas=0, media;

    if(file_name[0] == '\0')
    {
        puts("Falta especificar o nome do ficheiro\n");
        return 0;
    }

    fp = fopen(file_name, "r");

    if (fp == NULL)
    {
        printf("%s não existe.\n", file_name);
        exit(EXIT_FAILURE);
    } 

    while (fgets(linha, sizeof(linha), fp))
    {
        if (linha[0] == '\n' || linha[0] == '#')
        {
            continue;
        } else{
            char *parte = strtok(linha, " ");
            strcpy(array_Nomes[posicao], parte);
            parte = strtok(NULL, " ");
            nota = atoi(parte);
            array_Notas[posicao] = nota;
            posicao++;
            nPessoas++;
        }
        
        
    }
    /*printf("%s  %d\n", array_Nomes[5], array_Notas[6]);*/
    printf("\n");
    puts("Nome\t\tClass.");
    int size_a = sizeof(array_Notas) / sizeof(int);
    char nome[MAX];
    for (i = 0; i < size_a; i++)
    {
        
        if (array_Notas[i] > 9)
        {
            printf("%s\t\t%d\n",array_Nomes[i], array_Notas[i]);
        }

        totalNotas += array_Notas[i];

        if (array_Notas[i] >= notaMaior)
        {
            notaMaior = array_Notas[i];
            strcpy(nome, array_Nomes[i]);
        }
        
        
    }
    media = totalNotas / nPessoas;
    printf("\nA média da turma é: %.2f\n", media);
    printf("\nA pessoa com maior nota da turma é: %s com %d\n",nome, notaMaior);
    
    
    fclose(fp);
    
    
    
    return 0;

}