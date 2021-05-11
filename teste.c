#include <stdio.h>
#include <string.h>

void main()
{
    char teste[20] = "vazio";
    fgets(teste,260,stdin);

    if (teste[0] == '\n')
    {
        puts("asdasd");
    }
    
}