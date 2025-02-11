#include <stdlib.h>
#include <stdio.h>
#include <string.h>
    
#define BUFSIZE 256
    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }
    char cmd[BUFSIZE] = "wc -c < ";
    // Check to make sure string length is always valid
    strncat(cmd, argv[1], BUFSIZE - strlen(cmd) - 1);

    // Use popen instead of system
    int fileSize;
    FILE *fp = popen(cmd, "r");
    if (fp == NULL || fscanf(fp, "%d", &fileSize) != 1) {
        pclose(fp);
        return -1;
    }

    pclose(fp);

    printf("%d\n", fileSize);
}
