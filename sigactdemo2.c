#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <pwd.h>

#define INPUTLEN 100

char *uid_to_name(uid_t uid){
    struct passwd *pw_ptr;
    static char numstr[10];
    if((pw_ptr = getpwuid(uid)) == NULL){
        sprintf(numstr, "%d", uid);
        return numstr;
    }
    else return pw_ptr->pw_name;
}

void inthandler(int sig, siginfo_t *siginfo, void *context)
{
    printf("Error value %d, Signal code %d\n", siginfo->si_errno, siginfo->si_code);
    printf("Sending UID %-8s\n", uid_to_name(siginfo->si_uid));
    printf("Received signal %d .. waiting\n", sig);
    sleep(2);
    printf("Leaving inthandler \n");
}


int main(){
    struct sigaction newhandler;
    sigset_t blocked;
    char x[INPUTLEN];

    newhandler.sa_sigaction = inthandler;
    newhandler.sa_flags = SA_RESETHAND | SA_RESTART | SA_SIGINFO;

    sigemptyset(&blocked);
    sigaddset(&blocked, SIGQUIT);

    newhandler.sa_mask = blocked;

    if(sigaction(SIGINT, &newhandler, NULL) == -1)
        perror("sigaction");
    else
    {
        while(1){
            fgets(x, INPUTLEN, stdin);
            printf("input: %s", x);
        }
    }
}
