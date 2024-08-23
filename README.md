# Simple Shell

## Introduction

This project is a simple command-line shell written in C. It allows users to execute basic commands like `ls`, `pwd`, `cd`, and `exit`.

## Features

- **Prompt Display**: Shows a prompt (`$`) where users can enter commands.
- **Command Execution**: Runs system commands such as `ls`, `pwd`, and `cd`.
- **Directory Navigation**: The `cd` command changes the current directory.
- **Current Directory Display**: The `pwd` command shows the current directory.
- **File Listing**: The `ls` command lists files in the current directory.
- **Exit**: The `exit` command closes the shell.

## Files

- `simple_shell.h`: Contains function declarations and includes necessary headers.
- `main.c`: The main program that runs the shell loop and handles user input.
- `execute_command.c`: Handles running user commands.
- `execute_cd.c`: Implements the `cd` command.
- `execute_ls.c`: Implements the `ls` command.
- `execute_pwd.c`: Implements the `pwd` command.

## Compilation

To compile the Simple Shell, run:

~~~~
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell
~~~~

This creates an executable named simple_shell.

## Interactive Mode
Open a terminal.

Navigate to the directory with the simple_shell executable.

Run the shell:



~~~~
./simple_shell
~~~~
Enter commands at the $ prompt. For example:


~~~~
$ pwd
$ ls
$ cd ..
$ exit
~~~~
The shell continuously displays a prompt, waits for user input, and executes the command. If the user types exit, the shell terminates; otherwise, it loops back to display the prompt again.

## Non-Interactive Mode
Run a single command:


~~~~
echo "pwd" | ./simple_shell
~~~~
Run multiple commands from a script:

Create a commands.sh file with commands:

~~~~bash
pwd
ls
cd ..
pwd
~~~~
Run the script with:

~~~~bash
./simple_shell < commands.sh
~~~~
The shell reads commands from an input source (like a script or pipe), executes them sequentially, and exits when all commands are processed or when it encounters exit.
## Screenshots
![alt text](image.png)

## How the Project Was Built
**Plan the Shell**: Decide on the basic commands and structure.

**Create Header File**: Define functions and include necessary libraries in simple_shell.h.

**Implement Main Loop**: Write the main loop in main.c to handle user input and run commands.

**Implement Commands**: Write functions in execute_command.c, execute_cd.c, execute_ls.c, and execute_pwd.c to handle different commands.

**Test the Shell**: Run the shell in both interactive and non-interactive modes to ensure it works correctly.
