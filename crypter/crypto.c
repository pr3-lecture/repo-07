#include <stdio.h>
#include <stdlib.h>
#include "crypto.h"

int main(int argc, char* argv[]) {
    if(!(argc >= 2 && argc <= 3)) {
        fprintf(stderr, "Wrong number of parameters!");
        return EXIT_FAILURE;
    }
    
    KEY key = { 1, argv[1] };

    FILE* inputSource;
    if (argc == 2) {
       inputSource = stdin;
    } else {
        inputSource = fopen(argv[2], "r");
        if(!inputSource) {
            fprintf(stderr, "Open file failed!");
            return EXIT_FAILURE;
        }
    }

    char input[BUFSIZ];
    fgets(input, sizeof(input), inputSource);    
    printf("input: %s\n", input);

    if(strcmp(argv[0], "encrypt") == 0) {
        printf("encrypt...");
        return EXIT_SUCCESS;
    } else if (strcmp(argv[0], "decrypt") == 0) {
        printf("decrypt...");
        return EXIT_SUCCESS;
    } else {
        fprintf(stderr, "Ah ah ah, you didn't say the magic word!");
        return EXIT_FAILURE;
    }
}


int encrypt(KEY key, const char* input, char* output) {
	
}

int decrypt(KEY key, const char* cypherText, char* output) {
	
}
