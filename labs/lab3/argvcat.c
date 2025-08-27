#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* print out an error message and exit */
void my_error(char *s)
{
    perror(s);
    exit(1);
}

/* Concatnate two strings.
 * Dynamically allocate space for the result.
 * Return the address of the result.
 */
char *my_strcat(char *s1, char *s2)
{
    int n1 = strlen(s1);
    int n2 = strlen(s2);

    char* s = (char *) malloc(n1+n2);
    
    if (s == NULL) {
        my_error("malloc error");
    }

    strcpy(s,s1);
    strcat(s,s2);

    return s;
}

int main(int argc, char *argv[])
{
    char *s;

    s = my_strcat("", argv[0]);

    for (int i = 1; i < argc; i ++) {
        char *temp = s;
        s = my_strcat(s, argv[i]);
        free(temp);
    }

    printf("%s\n", s);

    free(s);

    return 0;
}