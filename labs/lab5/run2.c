#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char ** argv)
{
    pid_t child;
    int exitStatus;

    // at least, there should be 3 arguments
    // 2 for the first command, and the rest for the second command
    if (argc < 4) {
        fprintf(stderr, "Usage: %s cmd1 cmd1_arg cmd2 [cmd2_args ..]\n", argv[0]);
        return 1;
    }

    char* arg_1_list[3];
    arg_1_list[0] = argv[1];
    arg_1_list[1] = argv[2];
    arg_1_list[2] = NULL;

    char* arg_2_list[argc-2];
    char* arg_2_cmd = argv[3];

    for (int i = 3; i < argc; ++i) {
        arg_2_list[i-3] = argv[i];
    }

    arg_2_list[argc-3] = NULL;

    child = fork();
    if (child < 0) {
        perror("fork()");
        exit(1);
    } else if (child == 0) {
       execlp(arg_1_list[0], arg_1_list[0], arg_1_list[1], arg_1_list[2]);
       perror("execlp()");
       exit(1);
    } else {
        waitpid(child, &exitStatus, 0);
        printf("exited=%d exitstatus=%d\n", WIFEXITED(exitStatus), WEXITSTATUS(exitStatus));

        child = fork();
        if (child < 0) {
            perror("fork()");
            exit(1);
        } else if (child == 0) {
            execvp(arg_2_cmd, arg_2_list);
            perror("execvp()");
            exit(1);

        } else {
            waitpid(child, &exitStatus, 0);
            printf("exited=%d exitstatus=%d\n", WIFEXITED(exitStatus), WEXITSTATUS(exitStatus));
        }
    }

    



    
    

    return 0;
}