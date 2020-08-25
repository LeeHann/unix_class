#include <stdio.h>

int main()
{
    int c, n = 0;
    while((c=getchar()) != 'Q')
        printf("char %3d is %d code %d\n", n++, c, c);
    return 0;
}

