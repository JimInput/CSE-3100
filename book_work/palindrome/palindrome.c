#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <fcntl.h> 
#include <ctype.h> 
#include <sys/stat.h>

int _isPalindrome(char*, int, int);
int isPalindrome(char*);

int isPalindrome(char* word) {
    return _isPalindrome(word, 0, strlen(word)-1);
}

int _isPalindrome(char* word, int left_index, int right_index) {
    // Returns 1 if true, 0 if false.
    if (right_index <= left_index) return 1;

    if (word[left_index] == word[right_index]) return _isPalindrome(word, left_index+1, right_index-1);
    
    return 0;

}

void toUppercase(char word[], int n) {
    for (int i = 0; i < n; ++i) {
        word[i] = toupper(word[i]);
    }
}


int main(int argc, char** argv) {
    if (argc < 2) {
        printf("%s palindrome [str_arg]\n", argv[0]);
        return -1;
    }

    char* word = argv[1];

    if (isPalindrome(word)) {
        printf("%s is a palindrome.\n", word);
    } else {
        printf("%s is not a palindrome.\n", word);
    }
    


    return 0;
}