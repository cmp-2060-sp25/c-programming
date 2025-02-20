#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read and print the entire file
void printFile(const char *filename);

// Function to read and print a specific line from a file
void printLine(const char *filename, int n);

// Function to overwrite a specific line in a file
void writeLine(const char *filename, char *text, int n, const char *output_file);

// Function to append a line to the file
void appendLine(const char *filename, char *text, const char *output_file);

// Function to print the first `n` lines of a file
void printBeginning(const char *filename, int n);

// Function to print the last `n` lines of a file
void printEnd(const char *filename, int n);

#endif
