#include <stdio.h>
#include <ctype.h>

int main()
{
    int c;
    while((c=getchar()) != EOF){
        if(c=='x')
            c='a';
        else if(islower(c))
            c++;
        putchar(c);
    }
    return 0;
}

