# Easier-BrainFuck

Easier-BrainFuck is an interpreted adaptation of the BrainFuck programming language aimed at simplifying its usage while retaining its core concepts. The interpreter is based on my interpreter for brainfuck: https://github.com/Ikytsu/BrainFuck-Interpreter-in-C

## Prerequisites

- Ensure `gcc` and `make` are installed and added to your system's PATH.
- Alternatively (only for make, you still need to have gcc) , download the provided folder (choose the correct os) move the corresponding Makefile to the main folder.

## Compilation

- **First Way**: Run `make` in the directory after following the second **Prerequisites**. If you want to clear the file of compilation you can run `make clear`
- **Second Way**: Compile with `gcc`.

## Usage

To execute a BrainFuck program, use the following command in the terminal:

./brainfuck.exe program_name.bf

## Specificities

- The interpreter allows values between -2,147,483,648 and 2,147,483,647.
- The default behavior permits a wide range of choices.
- Pointer cursor values must be between 0 and 30000.
  
## Features

- **$**: Switch between ASCII value and printed value.
- **#**: Assign ASCII value to the current pointer. Use space for a space character and press enter like you wanted to create a line just after the # for '\n'.
- **\\**: Create (of 9 length) or extend a table (by 9) of pointers in the pointer, if you extend it the old values will be moved by 9 (i am gonna fix it later).
- **()**: Open a table of pointers within the current pointer, you can create many child as you want like \\(\\()) etc. You are automaticaly set to the first element when you do (), but when you exit the table of pointers so after that ) you come back on the actual element.
- **/**: Delete the table of pointers in the pointer and all of his child.

## Credits

If you modify and republish the code, please provide proper credits to me, more informations in the **LICENSE** file.
