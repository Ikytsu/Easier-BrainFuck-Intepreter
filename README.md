# Will be discontinued soon
# Easier-BrainFuck

Easier-BrainFuck is an interpreted adaptation of the BrainFuck programming language aimed at simplifying its usage while retaining its core concepts, easier because of more possibility not more simplicity, abstraction is needed! The interpreter is based on my interpreter for brainfuck: https://github.com/Ikytsu/BrainFuck-Interpreter-in-C

## Prerequisites
- If you are on windows or linux you can simply install in the release, continue if you want to compile it
- main.c is a little bit different depending if you are on linux or windows, make sure to choose the correct one and change it to main.c
- Ensure to have `gcc` or `clang` and if you want to compile it faster just download make (and gcc if you are lazy to change the Makefile) from linux or windows wsl.

## Compilation

- **First Way (only work with gcc)**: Run `make` in the directory
- **Prerequisites**. If you want to clear the file of compilation you can run `make clear`
- **Second Way**: Compile with `gcc` or `clang` manually, if you are on windows or you just want to compile it manually. For gcc it's `gcc -o ebf "main (os)" brainfuck.c`

## Usage

To execute a EasierBrainFuck program, use the following command in the terminal:

Linux:
./ebf.exe program_name.bf
Windows:
.\ebf.exe program_name.bf

## Specificities

- The interpreter allows values between -2,147,483,648 and 2,147,483,647.
- The default behavior permits a wide range of choices.
- Pointer cursor values must be between 0 and 30000.
- The interpreter is made to be already compatible with your normal brainfuck program, just make sure to don't have in commentary the instructions listed here
  
## Features

- **$**: Switch between ASCII value and printed value.
- **#**: Assign ASCII value to the current pointer. Use space for a space character and press enter like you wanted to create a line just after the # for '\n'.
- **\\**: Create (of 9 length) or extend a table (by 10) of pointers in the pointer, if you extend it the old values will be moved by 9 (i am gonna fix it later).

`Deprecated, works only with 1.0, changed by * and &, to permit better loop manipulation`

`- **()**: Open a table of pointers within the current pointer, you can create many child as you want like \\(\\()) etc. You are automaticaly set to the first element when you do (), but when you exit the table of pointers so after that ) you 
come back on the actual element.`
- **\***: Enter in the child table of pointer
- **&**: Enter in the parent table of pointer
- **/**: Delete the table of pointers in the pointer and all of his child.

## Credits

If you publish a code modification, republish it or inspire you of this idea, please provide proper credits to me, more informations in the **LICENSE** file.
