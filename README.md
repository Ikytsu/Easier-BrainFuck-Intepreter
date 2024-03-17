# Easier-BrainFuck

Easier-BrainFuck is an adaptation of the BrainFuck programming language aimed at simplifying its usage while retaining its core concepts.

## Prerequisites

- Ensure `gcc` and `make` are installed and added to your system's PATH.
- Alternatively (only for make, you still need to have gcc) , download the provided tar.gz file, extract it, and move the corresponding Makefile to the main folder.

## Compilation

- **First Way**: Download and extract the provided folder, then move the appropriate Makefile to the main folder. Run `make` in the directory.
- **Second Way**: Compile with `gcc`.

## Usage

To execute a BrainFuck program, use the following command in the terminal:

./brainfuck.exe program_name.bf

## Specificities

- The interpreter allows values between -2,147,483,648 and 2,147,483,647.
- The default behavior permits a wide range of choices.
- Pointer cursor values must be between 0 and 30000.
  
## Features

- **Change Output Type**: Switch between ASCII value and printed value.
- **#**: Assign ASCII value to the current pointer. Use space for a space character and press enter like you wanted to create a line just after the # for '\n'.
- **\***: Create (of 9 length) or extend a table (by 9) of pointers in the pointer, if you extend it the old values will be moved by 9 (i am gonna fix it later).
- **()**: Open a table of pointers within the current pointer, you can create many child as you want like \(\()) etc.
- **/**: Delete the table of pointers in the pointer and all of his child.

## Credits

If you modify and republish the code, please provide proper credits to me, more informations on the license file.
