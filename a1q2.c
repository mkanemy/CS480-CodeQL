#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
    
#define BUFSIZE 256
    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }
    
    // Dont use command line to get file size
    struct stat fileStat;
    if (stat(argv[1], &fileStat) != 0) {
        fprintf(stderr, "Invalid input.\n");
        return -1;
    }

    printf("%lld\n", fileStat.st_size);
}
