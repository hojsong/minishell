# Minishell

[한국어 버전](README.md.kr)

## Overview
`Minishell` is a project aimed at replicating the core functionalities of a Unix shell, such as `bash` or `zsh`. It provides a simplified shell experience, focusing on understanding system calls, process management, and basic command-line utilities.

- **Objective:** Build a minimal shell that interprets and executes commands in a manner similar to existing Unix shells.
- **Key Features:**
  - Execution of basic commands (`ls`, `echo`, etc.).
  - Redirections (`>`, `>>`, `<`).
  - Pipes (`|`).
  - Environment variable handling (`$VARIABLE`).
  - Support for built-in commands.

## Features
### Built-in Commands
- `echo`: Display a line of text.
- `cd`: Change the current directory.
- `pwd`: Display the current directory.
- `export`: Set environment variables.
- `unset`: Remove environment variables.
- `env`: List all environment variables.
- `exit`: Exit the shell.

### Additional Features
- Command execution using `execve`.
- Signal handling for `Ctrl+C`, `Ctrl+D`, and `Ctrl+\`.
- Support for multiple commands using pipes.
- Input and output redirection.

## Requirements
- **Operating System:** Linux or macOS.
- **Dependencies:** None (standard C libraries and POSIX system calls used).

## Installation and Execution
### Clone the Repository
```bash
git clone [repository URL]
cd minishell
```

### Build
```bash
make
```

### Run
```bash
./minishell
```

### Exit the Shell
```bash
exit
```

### File Structure
- `srcs/`: Source code for core functionalities.
- `includes/`: Header files for the project.

### How It Works
- Minishell emulates a Unix shell by:

### Reading user input.
- Parsing the input into commands and arguments.
- Handling environment variables and redirections.
- Creating child processes to execute commands using fork and execve.

### Example Usage
```bash
minishell> echo Hello, World!
Hello, World!
minishell> export VAR=42
minishell> echo $VAR
42
minishell> ls | grep minishell
minishell.c
minishell> exit
``` 
### References
- GNU Bash Documentation
- POSIX System Calls
