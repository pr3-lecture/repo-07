#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    input[strlen(input) - 1] = '\0';

    char output[BUFSIZ];
    int cryptResult;
    if(strcmp(argv[0], "encrypt") == 0) {
        cryptResult = encrypt(key, input, output);
        if(cryptResult != 0) {
            fprintf(stderr, "Encrypt failed with error %i!", cryptResult);
            return EXIT_FAILURE;
        } else {
            printf("%s\n", output);
            return EXIT_SUCCESS;
        }
    } else if (strcmp(argv[0], "decrypt") == 0) {
        cryptResult = decrypt(key, input, output);
        if(cryptResult != 0) {
            fprintf(stderr, "Decrypt failed with error %i!", cryptResult);
            return EXIT_FAILURE;
        } else {
            printf("%s\n", output);
            return EXIT_SUCCESS;
        }
    } else {
        fprintf(stderr, "Ah ah ah, you didn't say the magic word!");
        return EXIT_FAILURE;
    }
}
