#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"

const int PASS_LEN = 20;        // Maximum any password will be
const int HASH_LEN = 33;        // Length of MD5 hash strings

// Given a target plaintext word, use it to try to find
// a matching hash in the hashFile.
char * useWord(char * plaintext, char * hashFilename)
{
    // Hash the plaintext

    // Open the hash file

    // Loop through the hash file, one line at a time.

    // Attempt to match the hash from the file to the
    // hash of the plaintext.

    // If there is a match, you'll return the hash.

    // Before returning, do any needed cleanup:
    //   Close files?
    //   Free memory?

    // Change this next line to return the hash
    // that was found.
    return NULL;
}


int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        fprintf(stderr, "Usage: %s hash_file dict_file\n", argv[0]);
        exit(1);
    }

    // Open the dictionary file for reading.
    

    // For each dictionary word, pass it to useWord, which
    // will attempt to match it against the hashes in the hash_file.
    
    // If we got a match, display the hash and the word:
    //   5d41402abc4b2a76b9719d911017c592 hello
    
    // Close the dictionary file.
    
    // Free up any malloc'd memory?
}
