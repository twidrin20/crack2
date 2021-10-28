#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"

const int PASS_LEN = 20;        // Maximum any password will be
const int HASH_LEN = 33;        // Length of MD5 hash strings

// Given a target hash, crack it. Return the matching
// password.
char * crackHash(char * targetHash, char * dictionaryFilename)
{
    // Open the dictionary file

    // Loop through the dictionary file, one line
    // at a time.

    // Hash each password. Compare to the target hash.
    // If they match, return the corresponding password.
    
    // Close the dictionary file. Free up memory?

    return NULL;
}


int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        fprintf(stderr, "Usage: %s hash_file dict_file\n", argv[0]);
        exit(1);
    }

    // Open the hash file for reading.
    

    // For each hash, crack it by passing it to crackHash
    
    // Display the hash along with the cracked password:
    //   5d41402abc4b2a76b9719d911017c592 hello
    
    // Close the hash file
    
    // Free up any malloc'd memory?
}
