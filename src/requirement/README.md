# C Programming Lab Assignment

## Objective
The objective of this lab is to practice basic C programming concepts, passing arguments and using make files for more optimized builds.

## Instructions

You are required to write a `file_handler` that expose some functionality depending on the passed flags/options:
- `-r`: Prints the entire content of a file.
- `-r -l <line_number>`: Prints a specific line from a file. 
    - Bonus: raise a `Line out of bounds` exception if this line doesn't exist in the file.
- `-w <string> -l <line_number> [-o <output_file>]`: Overwrite some line with the provided string. 
    - Output file is an optional option, if it is specified don't modify the input file, only write to the output file. Otherwise, modify the input file itself.
    - Bonus: raise a `Line out of bounds` exception if this line doesn't exist in the file.
- `-a <string> [-o <output_file>]`: Appends a given string to the end of a file.
    - Output file is an optional option, if it is specified don't modify the input file, only write to the output file. Otherwise, modify the input file itself.

- `-h <n>`: Reads the first `n` lines of a file.
    - Bonus: raise a `File limit exceeded` exception if n is larger than the file line count.
- `-t <n>`: Reads the last `n` lines of a file.
    - Bonus: raise a `File limit exceeded` exception if n is larger than the file line count.


### Example Usage
```sh
./file_handler myfile.txt -r # prints to stdout the contents of the file
./file_handler myfile.txt -r -l 3 # prints to stdout the 3rd line
./file_handler myfile.txt -h 3 # prints to stdout the first 3 lines
./file_handler myfile.txt -t 3 # prints to stdout the last 3 lines
./file_handler myfile.txt -w "This line will overwrite the existing line" -l 3 #
./file_handler myfile.txt -a "This is a new line." -o outfile.txt # append the string to myfile.txt and write it to outfile.txt
```

### Requirements
1. Create a header file `file_handler.h` with the function declarations.
2. Implement the functions in `file_handler.c`.
3. Write a `main.c` that handles command-line arguments and calls the appropriate function.
4. Use `make` to compile your program.


## Grading Criteria
- Correctness: The program meets all specified requirements.
- Code Quality: The code is well-organized, commented, and follows good programming practices.