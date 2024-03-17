# Easier-BrainFuck
BrainFuck the programming language that's fucked your brain, was adapted to more complex programs by me. I was fascinated how brainfuck works, so I wanted a sort of brainfuck that you can use easily. The concept still the same :).

**Prerequistes:**
Must have gcc in PATH and make in PATH, if you are lazy to move it in path, just change the Makefile

**Compilation:**
First way: To compile the program you must download the tar.gz and extract it. When you are done move the Makefile corresponding to your OS on the main folder.
Just type make in the directory when you are done.
Second way: Compile with gcc :)

**Use:**
To use the program, you only need to type on the terminal:
./brainfuck.exe program_name.bf

**Specificities:**
The interpreter give you the choice between -2 147 483 648 and 2 147 483 647 values, so if you have a problem of performance you can change that.
It's in default bcs that gives more choices.
For cursor of pointer it must be between 0 and 30000 included, but you can change also if you need.

**Make:**
You can also Make clear to clear the files you compiled.

**Features:**
All features of brainfuck works in it, it's based on the interpreter i did https://github.com/Ikytsu/BrainFuck-Interpreter-in-C, the objective of the programming language is to keep the concept of brainfuck, not many instructions but add some to facilitate programming.

**$** change the output type, by default it's ascii value but if you change you can print the value

**#c** # with the caracter permit to assign to the actual pointer the ascii value of the character you set, note that you must put the caracter just after that, specials caracters are not supporter, if you want to put space just space after the # and if you want to put a \n just jump a line after the #

*****

**()**

**/**

**Credits:**
If you want to edit the code and republish it, leave credits to me
