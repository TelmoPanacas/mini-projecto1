#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#define MAX 256

void menu();

int main(void) {
    char input = '>';
    char opcao[MAX], file_name[MAX];
    FILE *ficheiroOriginal, *ficheiroExport;
    int counterLinha =0, linhaDimensoes = 0, counterIgnoradas = 0;
    
    /*Primeiro menu*/
    menu();
    char linhaCopiada[MAX], file_name_export[MAX];
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
            scanf(" %s", file_name_export);
            

            ficheiroOriginal = fopen(file_name, "r");

            if (ficheiroOriginal == NULL)
            {
                puts("Error opening file");
                exit(EXIT_FAILURE);
            }
            

            ficheiroExport = fopen(file_name_export, "w");
            if (ficheiroExport == NULL)
            {
                fclose(ficheiroOriginal);
                puts("Error opening file");
                exit(EXIT_FAILURE);
            }
            while (fgets(linhaCopiada, sizeof(linhaCopiada), ficheiroOriginal))
            {
                if (linhaCopiada[0] == '#')
                {
                    continue;
                }else{
                fputs(linhaCopiada, ficheiroExport);
                }
            }
            
            fclose(ficheiroOriginal);
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
                printf("O ficheiro %s foi lido corretamente\n", file_name);
               
               while (fgets(linhaCopiada, sizeof(linhaCopiada), ficheiroOriginal))
                {
                    /*COMO FAZER QUE A PRIMEIRA LINHA LIDA QUE 
                    NAO SEJA UM COMENTÁRIO SEJA A DAS DIMENSÕES DA MATRIZ*/
                    counterLinha++;
                    if (linhaCopiada[0] == '#')
                    {
                        counterIgnoradas++;
                        continue;
                    }
                    if (counterLinha == 1 && counterIgnoradas == 0)
                    {
                        printf("A linha das dimensões da matriz é a linha 0\n");
                    }
                    
                    
                }
                
                
                /*Dar print no mapa*/
            }
            fclose(ficheiroOriginal);
            
        }else {
            puts("There is no such option, returning to menu");
            menu();
        }

    }
    return 0;
}

void menu(){
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
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 54 ; j++)
        {
            printf("%c", menu[i][j]);
        }
        putchar('\n');
        
    }
    


}
