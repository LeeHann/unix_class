#include <stdio.h>
#include <unistd.h>

int main(){
    printf("my pid is %d\n", getpid());
    fork();
    printf("q5\n");
    fork();
    fork();
    printf("my pid is %d\n", getpid());
    printf("g5\n");
    return 0;
}

