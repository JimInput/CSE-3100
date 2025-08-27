#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define N 3

int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("%s [string-args]\n", argv[0]);
        return 0;
    }

    int str_pd[2];
    int len_pd[2];

    if (pipe(str_pd) < 0) {
        printf("pipe()");
        exit(EXIT_FAILURE);
    }

    if (pipe(len_pd) < 0) {
        printf("pipe()");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; ++i) {
        pid_t pid = fork();
        if (pid < 0) {
            printf("fork()");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            close(str_pd[0]);
            close(len_pd[0]);

            if (write(str_pd[1], argv[i], sizeof(argv[i]) == -1)) {
                printf("write()");
                exit(EXIT_FAILURE);
            }

            if (write(len_pd[1], strlen(argv[i]), sizeof(int) == -1)) {
                printf("write()");
                exit(EXIT_FAILURE);
            }

            close(str_pd[1]);
            close(str_pd[1]);
            return 0;
        }
    }

    close(str_pd[1]);
    close(len_pd[1]);

    while(wait(NULL) > 0);
    
    

    char* words[argc-1];
    int lens[argc-1];

    // for (int i = 0; i < argc-1; ++i) {
    //     if (read(str_pd[0], words+i))
    // }





    return 0;
}