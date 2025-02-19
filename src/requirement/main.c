#include <stdio.h>
#include <string.h>
#include "file_handler.h"

int main(int argc, char *argv[]) {
    char *file = argv[1];
    printf("File: %s\n", file);

    if(strcmp(argv[2], "-r") == 0) {
        if(argc < 4) {
            printFile(file);
        } else if(strcmp(argv[3], "-l") == 0) {
            printLine(file, atoi(argv[4]));
        }
    } else if(strcmp(argv[2], "-w") == 0) {
        if(argc < 7) {
            // write in the same file
            writeLine(file, argv[3], atoi(argv[5]), "");
        } else if(strcmp(argv[6], "-o") == 0) {
            // write in the output file
            writeLine(file, argv[3], atoi(argv[5]), argv[7]);
        }
    } else if(strcmp(argv[2], "-a") == 0) {
        if(argc < 5) {
            // append to the same file
            appendLine(file, argv[3], "");
        } else {
            // append to the output file
            appendLine(file, argv[3], argv[5]);
        }
    } else if(strcmp(argv[2], "-h") == 0) {
        printBeginning(file, atoi(argv[3]));
    } else if(strcmp(argv[2], "-t") == 0) {
        printEnd(file, atoi(argv[3]));
    }
    
    return 0;
}
