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

    child = fork();

    if (child < -1) {
        perror("fork()");
        exit(1);
    } else if (child == 0) {
        execlp(argv[1], argv[1], argv[2], NULL);
        perror("execlp()");
        exit(1);
    } else {
        waitpid(child, &exitStatus, 0);
        printf("exited=%d exitstatus=%d\n", WIFEXITED(exitStatus), WEXITSTATUS(exitStatus));
        char* argvs[argc-1];
        for (int i = 0; i < argc-3; i++) {
            argvs[i] = argv[i+3];
        }
        argvs[argc-3] = NULL;

        child = fork();
        if (child < -1) {
            perror("fork()");
            exit(1);
        } else if (child == 0) {
            execvp(argvs[0], argvs);
            perror("execvp()");
            exit(1);
        } else {
            waitpid(child, &exitStatus, 0);
            printf("exited=%d exitstatus=%d\n", WIFEXITED(exitStatus), WEXITSTATUS(exitStatus));
        }
        
    }

    
    return 0;
}
