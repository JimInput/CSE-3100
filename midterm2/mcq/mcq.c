#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <assert.h>

int main(void) {
    // Question 1:
    // int a = 0;
    // pid_t pid = fork();
    // if (pid == 0)
    //     a++;
    // a--;
    // if (pid) wait(NULL);
    // printf("a = %d\n", a);
    // return 0;
    // Question 2:
    // int count = 0;
    // if (fork()) {
    //     printf("%p\n", &count);
    //     wait(NULL);
    // }
    // else 
    // {
    //     printf("%p\n", &count);
    //     count++;
    // }

    // printf("%d\n", count);
    // return 0;
    // Question 3:
    // char *args[]={"ls", NULL};
    // execv(args[0], args);

    // printf("This is bad!\n");
    // return 0;
    // Question 4:
    // printf("first line\n");
    // int fd = open("dup2-output.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    // if (fd < 0) {
    //     printf("error opening file\n");
    //     return -1;
    // }
    // dup2(fd, 1);
    // close(fd);
    // printf("second line.\n");
    // return 0;

    // Question 5:
    // int pd[2];
    // assert(pipe(pd) != -1);
    // pid_t pid = fork();
    // if (pid == 0) {
    //     char *msg = "Hello, World!\n";
    //     close(pd[0]);
    //     for (int i = 0; i < strlen(msg); i++) {
    //         write(pd[1], &msg[i], sizeof(char));
    //     }
    //     close(pd[1]);
    // }
    // close(pd[1]);
    // char c;
    // do {
    //     read(pd[0], &c, sizeof(char));
    //     printf("%c", c);
    // } while (c!='\n');
    // close(pd[0]);
    // waitpid(pid, NULL, 0);
    // return 0;

    // Question 6:

    // int pd[2];
    // assert(pipe(pd) != -1);
    // pid_t pid = fork();
    // if (pid == 0) {
    //     for (int i = 0; i < 1000; i++) {
    //         write(pd[1], &i, sizeof(int));
    //     }
    //     close(pd[1]);
    //     return 0;
    // }
    // close(pd[1]);
    // waitpid(pid, NULL, 0);
    // int count = 0, k;
    // for (int i = 0; i < 1000; i ++)
    //     if (read(pd[0], &k, sizeof(int))) count++;
    // close(pd[0]);
    // printf("count = %d\n", count);
    // return 0;

    // Question 7:


    // Question 8:

    // Question 9:

    // int pd[2];
    // assert(pipe(pd) != -1);
    // pid_t pid = fork();
    // if (pid == 0) {
    //     close(pd[0]);
    //     char* msg = "Hello, World!\n Today is a great day!\n";
    //     write(pd[1], msg, strlen(msg));
    //     close(pd[1]);
    //     return 0;
    // }
    // close(pd[1]);
    // dup2(pd[0], 0);
    // close(pd[0]);
    // char s[1024];
    // while(fgets(s, sizeof(s), stdin)) printf("%s", s);
    // waitpid(pid, NULL, 0);
    // return 0;

    // Question 10:
    int pd[2];
    assert(pipe(pd) != -1);
    pid_t pid = fork();
    if (pid == 0) {
        close(pd[1]);
        dup2(pd[0], 0);
        close(pd[0]);
        char s[1024];
        while(fgets(s, sizeof(s), stdin)) printf("%s", s);
        return 0;
    }
    close(pd[0]);
    char* s = "Hello, World!\n Today is a great day!\n";
    write(pd[1], s, strlen(s));
    close(pd[1]);
    waitpid(pid, NULL, 0);
    return 0;
    
}