#include <stdio.h>
#include <time.h>

int main(){ 
    time_t test = 0;
    char *cp = ctime(&test);
    printf("%s", cp);
    return 0;
}
