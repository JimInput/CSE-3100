#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#define MAX_LINE_LENGTH 1000

int main(int argc, char* argv[]) {
    int fd = open("sort.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    dup2(fd, 1);
    printf("what\n");

    char line[MAX_LINE_LENGTH];


    FILE* mem = fopen("memory.c", "r+");
    

    while(fgets(line, MAX_LINE_LENGTH, mem)) {
        printf("%s\n", line);
    }


    close(fd);

    return 0;
}