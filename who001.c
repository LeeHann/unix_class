#include <stdio.h>
#include <stdlib.h>
#include <utmp.h>
#include <unistd.h>
#include <fcntl.h>

void show_info(struct utmp *);
int main(){
    struct utmp current_record;
    int utmpfd;
    int reclen = sizeof(current_record);

    if((utmpfd = open(UTMP_FILE, O_RDONLY)) == -1){
        perror(UTMP_FILE);
        exit(1);
    }

    while(read(utmpfd, &current_record, reclen) == reclen)
        show_info(&current_record);

    close(utmpfd);
    return 0;
}

void show_info(struct utmp * u)
{
    printf("%-8.8s", u->ut_user);
    printf(" ");
    printf("%-8.8s", u->ut_line);
    printf(" ");
    printf("%10d", u->ut_time);
    printf(" ");
    printf("%-8s", u->ut_host);
    printf("\n");
}
