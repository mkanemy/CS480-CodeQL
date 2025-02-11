#include <stdio.h>
#include <stdlib.h>

#define BUFFSIZE 256
    
int read_file(const char *filename) {
    FILE* ptr = fopen(filename, "r");
    
    if (ptr == NULL) {
        printf("File cannot be opened.\n");
        return(-1);
    }
    
    char buff[BUFFSIZE];
    
    while (fgets(buff, BUFFSIZE, ptr) != NULL) {
        printf("%s", buff);
    }
        
    return 0; 
}
