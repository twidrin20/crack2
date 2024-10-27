#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"

const int PASS_LEN = 20;        // Maximum any password will be
const int HASH_LEN = 33;        // Length of MD5 hash strings


// Given a target plaintext word, use it to try to find a matching hash in the hash file.
char * tryWord(char * plaintext, char * hashFilename)
{
    // Hash the plaintext.
    char *hash = md5(plaintext, strlen(plaintext));

    // Open the hash file for reading.
    FILE *inRead1 = fopen(hashFilename, "r");

    // Declare an array that will hold a line in the hash file.
    char line[HASH_LEN];

    // Loop through the hash file, one line at a time.
    while (fgets(line, HASH_LEN, inRead1) != NULL)
    {
        // Trim the newline character from the end of the current line if it has one.
        char *nl2 = strchr(line, '\n');
        if (nl2)
        {
            *nl2 = '\0';
        }

        // If there is a match, return the hash.
        if (strcmp(line, hash) == 0)
        {
            return hash;
        }
    }

    // Close the hash file.
    fclose(inRead1);

    // Free the hash's memory.
    free(hash);

    // If no match was found, return null.
    return NULL;
}

int main(int argc, char *argv[])
{
    // If there are less than 3 arguments, display an error message and exit the program.
    if (argc < 3) 
    {
        fprintf(stderr, "Usage: %s hash_file dict_file\n", argv[0]);
        exit(1);
    }

    // Open the dictionary file for reading.
    FILE *inRead2 = fopen(argv[2], "r");

    // Declare an array that will hold a password in the dictionary file.
    char password[PASS_LEN];

    // Declare a pointer that will hold a potential match between a password and a hash.
    char *found;

    // Declare a counter that counts how many hashes are cracked.
    int counter;

    // Loop through the dictionary file, one line at a time.
    while (fgets(password, PASS_LEN, inRead2) != NULL)
    {
        // Trim the newline character from the end of the current line if it has one.
        char *nl1 = strchr(password, '\n');
        if (nl1)
        {
            *nl1 = '\0';
        }

        // Attempt to match the current password with all hashes in the hash file.
        found = tryWord(password, argv[1]);
        
        // If we got a match, display the hash and the password and increase the counter by 1.
        if (found != NULL)
        {
            printf("%s %s\n", found, password);
            counter++;
        }
    }

    // Close the dictionary file.
    fclose(inRead2);

    // Display the number of hashes that were cracked.
    printf("%d hashes cracked!\n", counter);

    // Free the match's memory.
    free(found);
}