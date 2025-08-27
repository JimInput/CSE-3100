#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <assert.h>
#include <sys/wait.h>

#define MAX 10240
#define MAX_WORD_COUNT 60000                //we have less than 60000 words
#define MAX_WORD_LENGTH 80                //each word is less than 80 letters

//Using these two global variables can be justified :)
char words[MAX_WORD_COUNT][MAX_WORD_LENGTH];        //2-d array to hold all the words
int word_count = 0;                    //number of words, initilized to 0

//Note the words in the dictionary file are sorted
//This fact could be useful
void read_file_to_array(char *filename)
{
    FILE *fp;

    //open the file for reading
    fp = fopen(filename, "r");
    if(fp==NULL)
    {
        printf("Cannot open file %s.\n", filename);
        exit(-1);
    }
    //make sure when each word is saved in the array words,
    //it does not ends with a '\n'
    //see how this is done using fscanf 
    while(!feof(fp))
        fscanf(fp, "%s\n", words[word_count++]);
    fclose(fp);
}

//TODO
//Test wether a string word is in the dictionary
//Return 1 if word is in the dictionary
//Return 0 otherwise
//Be efficient in implementing this function
//Efficiency is needed to pass test cases in limited time
int in_dict(char *word)
{
    int n = strlen(word);
    if (n == 0) return 0;
    int left = 0, right = n;
    while (left < right) {
        int med = (left + right) / 2;
        int comp = strcmp(word, words[med]);

        if (comp < 0) {
            right = med;
        } else if (comp > 0) {
            left = med;
        } else {
            return 1;
        }
    }

    return 0;
}

//TODO
//Use key and shift to decrypt the encrypted message
//len is the length of the encrypted message
//Note the encrypted message is stored as an array of integers (not chars)
//The result is in decrypted

void decryption(unsigned char key, unsigned char shift, const int *encrypted, int len, char *decrypted)
{
    //decrypted[i] = (encrypted[i] ^ key) >> shift;

	for(int i = 0; i<len; i++)
		decrypted[i] = (char) ((encrypted[i] ^ key) >> shift);

}

//TODO
//calculate a score for a message msg
//the score is used to determine whether msg is the original message
int message_score(const char *msg)
{
    int score = 0;
    int rep[33] = {0};
    int letter_values[33] = {82, 15, 28, 43, 127, 22, 20, 61, 70, 1, 7, 40, 24, 67, 75, 19, 0, 60, 63, 91, 28, 9, 24, 1, 2, 13, 0, 20, 10, 5, 10, 15, 10};

    for (int i = 0; msg[i] != '\0'; ++i) {
        char ch = msg[i];
        ch = tolower(ch);
        if (ch >= 'a' && ch <= 'z') { 
            int index = ch - 'a';
            score += letter_values[index];
            rep[index]++; 
        }

        else if (ch == '.') {
            score += letter_values[26];
            rep[26]++;
        }
        else if (ch == ',') {
            score += letter_values[27];
            rep[27]++;
        }
        else if (ch == '!') {
            score += letter_values[28];
            rep[28]++;
        }
        else if (ch == '?') {
            score += letter_values[29]; 
            rep[29]++;
        }
        else if (ch == ' ') {
            score += letter_values[30];
            rep[30]++;
        }
        else if (ch == '"') {
            score += letter_values[31];
            rep[31]++;
        }
        else if (ch == ':') {
            score += letter_values[32];
            rep[32]++;
        }
    }

    for (int i = 0; i < 33; ++i) {
        if (rep[i] > strlen(msg)/4) {
            score = 0;
            break;
        }

    }

    return score;
    
}

//search using all the (key, shift) combinations
//to find the original message
//result is saved in message
void search(const int *encrypted, int len, char *message)
{
	char decrypted[MAX];

    int max_score = 0;
    strcpy(message, "");
    for(unsigned char k = 0; k < 255; k++)
    {
        for(unsigned char shift = 0; shift <= 24; shift++)
        {
            decryption(k, shift, encrypted, len, decrypted);
			int score = message_score(decrypted);
			if(score > max_score)
			{	
				max_score = score;
				strcpy(message, decrypted);
			}
        }
    }
}

//TODO
//read the encrypted message from the file to encrypted
//return number of bytes read
int read_encrypted(char *filename, int *encrypted)
{
    FILE* encrypted_file = fopen(filename, "r+");
    if (encrypted_file == NULL) {
        printf("fopen()\n");
        exit(-1);
    }
    
    fseek(encrypted_file, 0, SEEK_END);
    long file_size = ftell(encrypted_file);
    fseek(encrypted_file, 0, SEEK_SET);

    int bytes_read = fread(encrypted, sizeof(int), file_size / sizeof(int), encrypted_file);

    fclose(encrypted_file);

    return bytes_read;

}

//Do not change the main() function
int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("%s encrypted-message [args]\n", argv[0]);
		return 0;
	}

	read_file_to_array("dict.txt");

    for (int i = 1; i < argc; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            printf("fork()");
            exit(-1);
        } else if (pid == 0) {
            int encrypted[MAX];
            int len = read_encrypted(argv[i], encrypted);
            
            char message[MAX];
            strcpy(message, "");
            search(encrypted, len, message);
            printf("%s\n", message);

            return 0;
        }

    }

    while(wait(NULL) > 0);

	
	return 0;
}