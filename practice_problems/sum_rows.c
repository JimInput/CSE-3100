#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define N 3

int main(void) {
    int matrix[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int pd[2];

    if (pipe(pd) == -1) {
        printf("pipe()");
        exit(-1);
    }

    for (int i = 0; i < N; ++i) {
        pid_t pid = fork();
        if (pid == -1) {
            printf("fork()\n");
            exit(-1);
        }

        if (pid == 0) {
            close(pd[0]);

            int row_sum = 0;
            for (int j = 0; j < N; ++j) {
                row_sum += matrix[i][j];
            }
            if (write(pd[1], &row_sum, sizeof(int)) == -1) {
                printf("write()\n");
                exit(-1);
            }
            exit(1);
        }
    }

    close(pd[1]);

    while(wait(NULL) > 0);

    int sum = 0;
    for (int i = 0; i < N; ++i) {
        int curr_row_val;
        if (read(pd[0], &curr_row_val, sizeof(int)) == -1) {
            printf("read()\n");
            exit(-1);
        } 
        sum += curr_row_val;
    }

    printf("The sum of all entries in the matrix is: %d\n", sum);

    close(pd[0]);

    while(wait(NULL) > 0);


    return 0;
}