# C Programming Lab Assignment

## Objective
The objective of this lab is to practice basic C programming concepts, passing arguments and using make files for more optimized builds.

## Instructions

You are required to write a `file_handler` in pure c (don't use `strings`, `cout` or any cpp library) that expose some functionality depending on the passed flags/options:
- `-r`: Prints the entire content of a file. [2]
- `-r -l <line_number>`: Prints a specific line from a file.  [2]
    - Bonus: raise a `Line out of bounds` exception if this line doesn't exist in the file. [0.5]
- `-w <string> -l <line_number> [-o <output_file>]`: Overwrite some line with the provided string. [3]
    - Output file is an optional option, if it is specified don't modify the input file, only write to the output file. Otherwise, modify the input file itself.
    - Bonus: raise a `Line out of bounds` exception if this line doesn't exist in the file. [0.5]
- `-a <string> [-o <output_file>]`: Appends a given string to the end of a file. [3]
    - Output file is an optional option, if it is specified don't modify the input file, only write to the output file. Otherwise, modify the input file itself.

- `-h <n>`: Reads the first `n` lines of a file. [1]
    - Bonus: raise a `File limit exceeded` exception if n is larger than the file line count. [0.5]
- `-t <n>`: Reads the last `n` lines of a file. [1]
    - Bonus: raise a `File limit exceeded` exception if n is larger than the file line count. [0.5]
- Bonus: raise a `File does not exist` exception if the input file doesn't exist. [1]

### Example Usage
```sh
./file_handler myfile.txt -r # prints to stdout the contents of the file
./file_handler myfile.txt -r -l 3 # prints to stdout the 3rd line
./file_handler myfile.txt -h 3 # prints to stdout the first 3 lines
./file_handler myfile.txt -t 3 # prints to stdout the last 3 lines
./file_handler myfile.txt -w "This line will overwrite the existing line" -l 3 # Overwrites the 3rd line in myfile.txt
./file_handler myfile.txt -a "This is a new line." -o outfile.txt # append the string to myfile.txt and write it to outfile.txt without modifying myfile.txt
```

### Requirements
1. Create a header file `file_handler.h` with the function declarations.
2. Implement the functions in `file_handler.c`.
3. Write a `main.c` that handles command-line arguments and calls the appropriate function.
4. Use `make` to compile your program. [3]


## Grading Criteria
- Correctness: The program meets all specified requirements.
- Code Quality: The code is well-organized, commented, and follows good programming practices.