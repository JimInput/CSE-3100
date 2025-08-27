#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <sys/wait.h>

/*
             parent process
            /           \
        child A         child B
            \
              child C
*/

int main(void) {
    // pid_t value; // parent has value != 0 child has value == 0
    // value = fork();
    // if (value != 0) { // still in parent process
    //     value = fork();
    //     if (value != 0) { // still in parent process
    //         printf("In the parent process.\n");
    //     } else {
    //         printf("In child process B.\n");
    //     }
    // } else if (value == 0) { // now in child process A
    //     value = fork();
    //     if (value != 0) { // still in child process A
    //         printf("In the child process A.\n");
    //     } else { // now in child process C
    //         printf("In the child process C.\n");
    //     }
    // }

    

    char *cmd1 = "./adder";
    pid_t child = fork();
    if (child == 0) {
        printf("In child!\n");
        execl(cmd1, cmd1, "1", "2", "3", NULL);
        printf("Oops.... something went really wrong!\n");
        perror(cmd1);
        return -1;
    } else {
        printf("In parent!");
        execl(cmd1, cmd1, "2", "4", "6", NULL);
        printf("Oops.... something went really wrong!\n");
        perror(cmd1);
        return -1;
    }

    // if # of arguments not known at compile-time
    // use execv(const char *path, char *const argv[]);

    // exit(0) terminates the child process

    // unix has lower-level APIs for file handling    
    return 0;
}