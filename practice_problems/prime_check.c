#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define N 10

/*
Problem 1: Multi-Process Prime Number Checker Using Pipes
Description:

Write a C program that creates N child processes, where each child process checks whether a given number in an array is prime. The parent process should:

    Distribute numbers to child processes using a pipe.
    Each child reads a number, determines if it is prime, and writes the result back to the parent through another pipe.
    The parent collects and prints results after all children finish.

Requirements:

    Use two pipes (one for parent → child, one for child → parent).
    The parent must ensure proper synchronization to prevent writing or reading conflicts.
    Each child should process only one number.
    Properly handle closing unused pipe ends.
    Use wait() to ensure all children terminate before the parent exits.

Hints:

    Consider using fork() within a loop.
    Each child reads its number, processes it, and writes the result back.
    The parent waits for all children before printing the results.
*/

// returns the number if it is prime 0 if not.
int prime_check(int num) {
    if (num <= 1) {
        return 0;
    }
    if (num == 2 || num == 3) {
        return num;
    }
    for (int i = 2; i*i <= num; ++i) {
        if (num % i == 0) {
            return 0;
        }
    }
    return num;
}

int main(void) {
    int nums[N] = {1, 5, 2, 3, 7, 19, 97, 91, 101, 0};

    int pd_in[2];
    int pd_out[2];

    if (pipe(pd_in) == -1) {
        printf("pipe()\n");
        exit(-1);
    }

    if (pipe(pd_out) == -1) {
        printf("pipe()\n");
        exit(-1);
    }

    for (int i = 0; i < N; ++i) {
        pid_t pid = fork();
        if (pid == -1) {
            printf("fork()\n");
            exit(-1);
        } else if (pid == 0) {
            close(pd_out[0]);
            close(pd_in[1]);

            int num;

            if(read(pd_in[0], &num, sizeof(int)) == -1) {
                printf("read()\n");
                exit(-1);
            }

            

            if (prime_check(num)) {
                if (write(pd_out[1], &num, sizeof(int)) == -1) {
                    printf("write()\n");
                    exit(-1);
                }
            }

            close(pd_in[0]);
            close(pd_out[1]);
            return 0;
        }
    }

    close(pd_in[0]);
    close(pd_out[1]);

    // parents writes array to pipe in
    for (int i = 0; i < N; ++i) {
        write(pd_in[1], &nums[i], sizeof(int));
    }

    close(pd_in[1]);

    while(wait(NULL) > 0);
    int val;

    while(read(pd_out[0], &val, sizeof(int)) > 0) {
        printf("%d is prime.\n", val);
    }

    close(pd_out[0]);
}