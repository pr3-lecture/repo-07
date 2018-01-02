#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypto.h"

int tests_run = 0;

#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; \
                                 if (message) return message; } while (0)

static char* testEncrypt();
static char* testDecrypt();
static char* testKeyTooShort();
static char* testKeyIllegalChar();
static char* testMessageIllegalChar();
static char* testCypherIllegalChar();

static char* allTests();


int main(int argc, char* argv[]) {
    char *result = allTests();

    if (result != 0) printf("%s\n", result);
    else             printf("ALL TESTS PASSED\n");

    printf("Tests run: %d\n", tests_run);

    return result != 0;
}


static char* allTests() {
    mu_run_test(testEncrypt);
    mu_run_test(testDecrypt);
    mu_run_test(testKeyTooShort);
    mu_run_test(testKeyIllegalChar);
    mu_run_test(testMessageIllegalChar);
    mu_run_test(testCypherIllegalChar);
    return 0;
}


static char* testEncrypt() {
	KEY key = { 1, "TPERULES" };
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char output[BUFSIZ];
    
    int result = encrypt(key, input, output);
    mu_assert("testEncrypt() failed!", strcmp(output, "URFVPJB[]ZN^XBJCEBVF@ZRKMJ") == 0);
    return 0;
}


static char* testDecrypt() {
	KEY key = { 1, "TPERULES" };
	char input[] = "URFVPJB[]ZN^XBJCEBVF@ZRKMJ";
    char output[BUFSIZ];

    int result = decrypt(key, input, output);
    mu_assert("testDecrypt() failed!", strcmp(output, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") == 0);
    return 0;
}


static char* testKeyTooShort() {
	KEY key = { 1, "" };
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char output[BUFSIZ];
    
    int result = encrypt(key, input, output);
    mu_assert("testKeyTooShort() failed!", result == E_KEY_TOO_SHORT);
    return 0;
}


static char* testKeyIllegalChar() {
	KEY key = { 1, "TPERULEs" };
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char output[BUFSIZ];
    
    int result = encrypt(key, input, output);
    mu_assert("testKeyIllegalChar() failed!", result == E_KEY_ILLEGAL_CHAR);
    return 0;
}


static char* testMessageIllegalChar() {
	KEY key = { 1, "TPERULES" };
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYz";
    char output[BUFSIZ];
    
    int result = encrypt(key, input, output);
    mu_assert("testMessageIllegalChar() failed!", result == E_MESSAGE_ILLEGAL_CHAR);
    return 0;
}


static char* testCypherIllegalChar() {
	KEY key = { 1, "TPERULES" };
	char input[] = "URFVPJB[]ZN^XBJCEBVF@ZRKMj";
    char output[BUFSIZ];
    
    int result = decrypt(key, input, output);
    mu_assert("testCypherIllegalChar() failed!", result == E_CYPHER_ILLEGAL_CHAR);
    return 0;
}

