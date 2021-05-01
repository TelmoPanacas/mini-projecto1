#include <stdio.h>
#include <stdlib.h>
#define MAX 64
int main()
{
   char linha[MAX], file_name[MAX];
   FILE *fp;

   printf("Nome do ficheiro:\n");
   scanf("%s", file_name);

   if (file_name[0] == '\0')
   {
       puts("Falta especificar o nome do ficheiro");
       return 0;
   }
   

   fp = fopen(file_name, "r"); // read mode

   if (fp == NULL)
   {
      printf("%s não existe.\n", file_name);
      exit(EXIT_FAILURE);
   } else {
      printf("%s existe e foi corretamente aberto\n", file_name);
      
   }

   /* Para para dar print do texto*/
   printf("The contents of %s file are:\n", file_name);

   while(fgets(linha, sizeof(linha), fp))
   {
      printf("%s", linha);
   }
   fclose(fp);
   return 0;
}