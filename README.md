# c-programming
Since the Linux kernel is written in C, our labs will rely heavily on it.

In order to run C on your machine, you need a compiler. The most famous compiler is [gcc](https://gcc.gnu.org/). 

## Installation
```bash
sudo apt-get update
sudo apt install build-essential
# verify your installation
gcc --version
# gcc (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0
# Copyright (C) 2023 Free Software Foundation, Inc.
# This is free software; see the source for copying conditions.  There is NO
# warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```
## Compilation & Execution
```bash
# Create an executable
gcc hello.c -o hello.out
# Run the executable
./hello
# Compile and execute the output file
gcc hello.c -o hello.out && ./hello.out
```
**Passing Arguments**

It's possible to read arguments into your program
```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Number of arguments passed: %d\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    return 0;
}
```
`argc` will have the count of arguments passed to your main, while `argv` is an array of character arrays holding the passed arguments. `argv[0]` will have the name of the program being executed.

Be careful that arguments are always considered `char*`, even if you pass integers, they will be considered as characters.

**Compiling multiple files**
```bash
g++ main.cpp hello.cpp factorial.cpp -o hello
```
**What if we only changed one file, do we need to build everything?!**

### Make Build
Compiling your source code files can be tedious, specially when you want to include several source files and have to type the compiling command every time you want to do
it.
Makefiles are special format files that together with the make utility will help you to automatically build and manage your projects.

**The `make` utility**

If you run `make` this program will look for a file named makefile in your directory, and then execute it.
If you have several makefiles, then you can execute them with the command:
```bash
make -f MyMakefile
```
There are several other switches to the make utility. For more info, `man make`.

**Build Process**
1. Compiler takes the source files and outputs object files
2. Linker takes the object files and creates an executable

The basic makefile is composed of:
```make
target: dependencies
[tab] system command
```
This syntax applied to our example would look like:
```make
all:
    gcc main.c hello.c factorial.c -o hello
```
To run this makefile on your files, type:
```bash
make -f Makefile-1
```
- On this first example we see that our target is called `all`. This is the default target for makefiles. 
- The make utility will execute this target if no other one is specified.
- We also see that there are no dependencies for target `all`, so make safely executes the system commands specified.
- Finally, make compiles the program according to the command line we gave it.

**Using dependencies**

Sometimes is useful to use different targets. This is because if you modify a
single file in your project, you don't have to recompile everything, only what
you modified.
```make
all: hello

hello: main.o factorial.o hello.o
	gcc main.o factorial.o hello.o -o hello

# The -c flag tells the compiler to generate an object file (e.g., myprogram.o) without linking it into an executable.
main.o: main.c
	gcc -c main.c

factorial.o: factorial.c
	gcc -c factorial.c

hello.o: hello.c
	gcc -c hello.c

clean:
	rm -rf *o hello
```
- Now we see that the target `all` has only dependencies, but no system commands.In order for make to execute correctly, it has to meet all the dependencies of thecalled target (in this case `all`).
- Each of the dependencies are searched through all the targets available and executed if found.
- In this example we see a target called `clean`. It is useful to have such target if you want to have a fast way to get rid of all the object files and executables.
```bash
make -f Makefile-2 clean
```

**Using variables and comments**
You can also use variables when writing Makefiles. It comes in handy in situations where you want to change the compiler, or the compiler options.
```make
# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=gcc
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
# The -Wall flag in gcc (GNU Compiler Collection) stands for "Warn All". It is used to enable a broad range of compiler warnings that help identify potential issues in your C or C++ code.

CFLAGS=-c -Wall

all: hello

hello: main.o factorial.o hello.o
	$(CC) main.o factorial.o hello.o -o hello

main.o: main.c
	$(CC) $(CFLAGS) main.c

factorial.o: factorial.c
	$(CC) $(CFLAGS) factorial.c

hello.o: hello.c
	$(CC) $(CFLAGS) hello.c

clean:
	rm -rf *o hello
```
As you can see, variables can be very useful sometimes. To use them, just assign a value to a variable before you start to write your targets. After that,
you can just use them with the dereference operator `$(VAR)`.

With this brief introduction to Makefiles, you can create some very
sophisticated mechanism for compiling your projects.
```make
# C Compiler
CC=gcc

# CFLAGS is a commonly used variable in Makefiles to specify flags for the C compiler
CFLAGS=-c -Wall

# LDFLAGS is typically used with the linker invocation in Makefile rules
LDFLAGS=

# SOURCES is expected to be a list of .c source files, for example:
SOURCES=main.c hello.c factorial.c

# $(SOURCES:.c=.o) is a Makefile substitution reference, it replaces all .c extensions in the SOURCES list with .o.
OBJECTS=$(SOURCES:.c=.o)
# result OBJECTS = file1.o file2.o file3.o

EXECUTABLE=hello

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

# .c.o is a generic suffix rule in a Makefile that specifies how to compile .c files into .o (object) files.
# This defines a rule for how to transform a .c file into a .o file.
# It’s a pattern rule, meaning any .c file can be automatically compiled into an object file (.o) using the specified command.
# $< Represents the first prerequisite (the .c source file) in the rule.
# $@ Represents the target (the object file being built).

.c.o:
	$(CC) $(CFLAGS) $< -o $@
```
You could adapt it to your own personal projects changing only 2 lines, no
matter how many additional files you have.

## Debugging

For debugging your application, [`gdb`](https://sourceware.org/gdb/) is a very powerful tool in hand.
```bash
# compile your C program with the -g flag to include debugging information
gcc -g -o myprogram myprogram.c

# Run the Program
# Launch your gdb program
gdb ./myprogram

# Run the Program
# Start the program
(gdb) run
# Short for r
(gdb) r
# Start the program with arguments
(gdb) run arg1 arg2

# Set Breakpoints
# Set a breakpoint at a specific line
(gdb) break 10
# Short for b
(gdb) b
# Set a breakpoint at a function
(gdb) break my_function
# Show info about your breakpoints
(gdb) info break
# To remove a specific breakpoint (e.g., breakpoint number 1):
(gdb) delete 1
# To remove all breakpoints at once:
(gdb) delete

# Continue Execution
# Resume the program until the next breakpoint or end:
(gdb) continue
# Short for c
(gdb) c

# Step Execution 
# step: Execute the next line of code and step into functions if applicable.
(gdb) step
# Short for s
(gdb) s
# next: Execute the next line but do not step into functions.
(gdb) next
# Short for n
(gdb) n
# The finish command resumes execution until the current function returns. Once the function is complete, it will pause at the line following the function call.
(gdb) finish

# Print Variables
# Print the value of a variable:
(gdb) print var_name
# Short for p var_name
(gdb) p var_name
# Assign a Value to a Variable
(gdb) set var variable_name = new_value

# Backtrace
# Display the call stack (useful for identifying where a crash occurred):
(gdb) backtrace
(gdb) where
# You can use the frame command to display the current function and line:
(gdb) frame


# Watch Variables
# Automatically stop execution when a variable’s value changes:
(gdb) watch var_name
# Show info about your watched variables
(gdb) info watch

# List Source Code
# Display a portion of the source code:
(gdb) list
# Short for l
(gdb) l
# Show code for a specific function
(gdb) l main

# Quit gdb
# Exit the debugger:
(gdb) quit
# Short for q
(gdb) q
```