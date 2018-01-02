#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypto.h"

int xor(KEY key, const char* input, char* output);
int hasIllegalChar(const char* input, char* allowedChars);


int encrypt(KEY key, const char* input, char* output) {
    if(hasIllegalChar(input, MESSAGE_CHARACTERS)) {
        return E_MESSAGE_ILLEGAL_CHAR;
    }
    
    return xor(key, input, output);
}


int decrypt(KEY key, const char* cypherText, char* output) {
    if(hasIllegalChar(cypherText, CYPHER_CHARACTERS)) {
        return E_CYPHER_ILLEGAL_CHAR;
    }
    
    return xor(key, cypherText, output);
}


int hasIllegalChar(const char* input, char* allowedChars) {
    int i, j;
    for(i = 0; i < strlen(input); i++) {
        int foundChar = 0;
        for(j = 0; j < strlen(allowedChars); j++) {
            if(input[i] == allowedChars[j]) {
                foundChar = 1;
            }
        }
        
        if(!foundChar) {
            return 1;
        }
    }
    return 0;
}


int xor(KEY key, const char* input, char* output) {
    int keyLength = strlen(key.chars);
    if(keyLength == 0) {
        return E_KEY_TOO_SHORT;
    }
    
    if(hasIllegalChar(key.chars, KEY_CHARACTERS)) {
        return E_KEY_ILLEGAL_CHAR;
    }

    int i;
    for(i = 0; i < strlen(input); i++) {
        char inputChar = input[i] - 'A' + 1;
        char keyChar = key.chars[i % keyLength] - 'A' + 1;
        char outputChar = inputChar ^ keyChar;
        output[i] = outputChar + 'A' - 1;
    }
    output[i] = '\0';
    
    return 0;
}

