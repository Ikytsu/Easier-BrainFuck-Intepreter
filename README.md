# Easier-BrainFuck

Easier-BrainFuck is an interpreted adaptation of the BrainFuck programming language aimed at simplifying its usage while retaining its core concepts. The interpreter is based on my interpreter for brainfuck: https://github.com/Ikytsu/BrainFuck-Interpreter-in-C

## Prerequisites
- If you are on windows or linux you can simply install the compiled project, but you can compile it yourself as well (the .exe of the 1.0 was retired bcs antivirus false positive it, so we change of compiler to distribute our binary (clang to gcc))
- main.c is a little bit different depending if you are on linux or windows, make sure to choose the correct one
- Ensure `gcc` or `clang` and `make` (optional) are installed and added to your system's PATH (if you are not on linux)
- Alternatively (only for make, you still need to have gcc) , download the provided folder (choose the correct os) move the corresponding Makefile to the main folder.

## Compilation

- **First Way (don't works with clang)**: Run `make` in the directory after following the second
- **Prerequisites**. If you want to clear the file of compilation you can run `make clear`, note that it works only if you have gcc in your path
- **Second Way**: Compile with `gcc` or `clang`. For gcc it's `gcc -o EasierBrainfuck "main (os)" brainfuck.c`

## Usage

To execute a BrainFuck program, use the following command in the terminal:

EasierBrainfuck.exe program_name.bf
or if it don't work
.\EasierBrainfuck.exe program_name.bf

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
