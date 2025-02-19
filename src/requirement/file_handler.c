#include "file_handler.h"

// Function to read and print the entire file
void printFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        fprintf(stderr, "Error: File does not exist\n");
        exit(EXIT_FAILURE);
    }

    char str[100];
    while(fgets(str, 100, file)) {
        printf("%s", str);
    }
    fclose(file);
}

// Function to read and print a specific line from a file
void printLine(const char *filename, int n) {
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        fprintf(stderr, "Error: File does not exist\n");
        exit(EXIT_FAILURE);
    }

    char str[100];
    for(int i = 0; i < n; i++) {
        if(fgets(str, 100, file)) {
            continue;
        } else {
            fprintf(stderr, "Error: Line out of bounds\n");
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }
    printf("%s\n", str);
    fclose(file);
}

// Function to overwrite a specific line in a file
void writeLine(const char *filename, char *text, int n, const char *output_file) {
    strcat(text, "\n");
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        fprintf(stderr, "Error: File does not exist\n");
        exit(EXIT_FAILURE);
    }

    FILE *temp = fopen("temp.txt", "a");
    char str[100];
    int i = 1;
    while(fgets(str, 100, file)) {
        if(i == n) {
            fputs(text, temp);
        } else {
            fputs(str, temp);
        }
        i++;
    }
    if(i < n) {
        // raise an exception
        fprintf(stderr, "Error: Line out of bounds\n");
        fclose(file);
        fclose(temp);
        remove("temp.txt");
        exit(EXIT_FAILURE);
    }
    fclose(file);
    if(strcmp(output_file, "") == 0) {
        remove(filename);
        rename("temp.txt", filename);
    } else {
        rename("temp.txt", output_file);
    }
}

// Function to append a line to the file
void appendLine(const char *filename, char *text, const char *output_file) {
    strcat(text, "\n");
    FILE *file = fopen(filename, "a");
    if(file == NULL) {
        fprintf(stderr, "Error: File does not exist\n");
        exit(EXIT_FAILURE);
    }

    if(strcmp(output_file, "") == 0) {
        fputs(text, file);
    } else {
        char str[100];
        FILE *output = fopen(output_file, "a");
        while(fgets(str, 100, file)) {
            fputs(str, output);
        }
        fputs(text, output);
        fclose(output);
    }
    fclose(file);
}

// Function to print the first `n` lines of a file
void printBeginning(const char *filename, int n) {
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        fprintf(stderr, "Error: File does not exist\n");
        exit(EXIT_FAILURE);
    }

    int lines = 0;
    char str[100];
    while (fgets(str, 100, file)) {
        lines++;
    }
    if(n > lines) {
        // raise an exception
        fprintf(stderr, "Error: File limit exceeded\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    
    fseek(file, 0, SEEK_SET);
    
    int i = 0;
    while (fgets(str, 100, file) && i < n) {
        printf("%s", str);
        i++;
    }
    fclose(file);
}

// Function to print the last `n` lines of a file
void printEnd(const char *filename, int n) {
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        fprintf(stderr, "Error: File does not exist\n");
        exit(EXIT_FAILURE);
    }

    int lines = 0;
    char str[100];
    while (fgets(str, 100, file)) {
        lines++;
    }
    if(n > lines) {
        // raise an exception
        fprintf(stderr, "Error: File limit exceeded\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_SET);

    int skip_lines = lines - n;
    int current_line = 0;
    while (current_line < skip_lines && fgets(str, 100, file)) {
        current_line++;
    }
    
    while (fgets(str, 100, file)) {
        printf("%s", str);
    }

    fclose(file);
}
