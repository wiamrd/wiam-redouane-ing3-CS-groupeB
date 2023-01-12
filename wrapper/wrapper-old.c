#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SHELLCODE_LEN 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <shellcode>\n", argv[0]);
        return 1;
    }

    int len = strlen(argv[1]);
    if (len % 2 != 0) {
        printf("Error: shellcode length must be multiple of 2\n");
        return 1;
    }

    unsigned char shellcode[MAX_SHELLCODE_LEN];
    memset(shellcode, 0x90, MAX_SHELLCODE_LEN);
    for (int i = 0; i < len; i += 2) {
        char byte[3];
        byte[0] = argv[1][i];
        byte[1] = argv[1][i + 1];
        byte[2] = '\0';
        shellcode[i / 2] = (unsigned char)strtol(byte, NULL, 16);
    }

    int (*ret)() = (int(*)())shellcode;
    ret();
    return 0;
}
