#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    signal(SIGINT, SIG_IGN);
    printf("yuo can't stop me!~~\n");
    printf("try Ctrl+C?\n");
    while(1){
        sleep(1);
        printf("haha!\n");
    }
}
