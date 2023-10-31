
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){

    if(argc =! 2){
        printf("Usage: %s [filename]\n", argv[0]);
        return EXIT_FAILURE;
    }


    char *fileName = argv[1];

    FILE *fp = fopen(fileName, "rb");
    if (fp == NULL){
        perror("fopen");
        printf("Sorry, could not open file(%s)\n", fileName);
        return EXIT_FAILURE;    
    }
    // Declaration variable
    const int MAGIC_NUM_BYTES = 3;
    char magicNumber[3];
    char expectedMagicNumber[3]= {0xff, 0xD8, 0xFF};
    
    // Read file
    int numRead = fread(magicNumber, 1, 3, fp); // DEST/1 BYTE/NUMBER BYTE/SOURCE
    if(numRead =! 3){
        printf("Couldn't read the first 3 bytes!\n");
        return EXIT_FAILURE;
    }

    if (memcmp(magicNumber, expectedMagicNumber, 3) == 0){
        printf("Yes !\n");
    }else{
        printf("No!\n");
    }
    ;
}