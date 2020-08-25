#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define oops(m,x) {perror(m); exit(x);}

int main(){
    int pipefd[2], len, read_len;
    char buf[BUFSIZ];
    FILE *fp, *fd;

    fp = popen("who", "r");
 
    pipe(pipefd);
    switch(fork()){
        case -1 :
            oops("cannot fork", 2);
        case 0 :
            dup2(pipefd[0], 0);
            close(pipefd[0]);
        default :
            wait(NULL);
            dup2(pipefd[1], 1);
            close(pipefd[1]);
            while(fgets(buf, 100, fp) != NULL)
                write(1, buf, BUFSIZ); 
    }
    pclose(fp);
    return 0;
}
            


