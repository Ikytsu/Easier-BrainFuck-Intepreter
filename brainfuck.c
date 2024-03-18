#include "brainfuck.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdbool.h"

//struct to aliment our tables of pointers thing iterative
typedef struct TablesElements TablesElements;

struct TablesElements
{
    int value;
    int pointer_table_size;
    TablesElements *pointer_table;
    TablesElements *parent;
};

//recursive liberation of memory to prevent tables of pointers in pointers staying
void freeallmemory(TablesElements* Table_of_pointers, int size)
{
    int i = 0;
    for(; i < size; i++)
    {
        if(Table_of_pointers[i].pointer_table != NULL)
        {
            freeallmemory(Table_of_pointers[i].pointer_table, Table_of_pointers[i].pointer_table_size);
        }
    }
    free(Table_of_pointers);
}

void execute(char * code)
{
    //detect if all loops and access to table of pointers are correctly closed
    int openloop_count = 0;
    int closeloop_count = 0;
    int openpointer_count = 0;
    int closepointer_count = 0;
    char * code2 = code;
    while(*code2) 
    {
        if(*code2 == '[') 
        {
            openloop_count++;
        } 
        else if(*code2 == ']') 
        {
            closeloop_count++;
        }
        else if(*code2 == '(')
        {
            openpointer_count += 1;
        }
        else if(*code2 == ')')
        {
            closepointer_count += 1;
        }
        code2++;
    }
    //if all ( and [ are closed
    if(openloop_count == closeloop_count && openpointer_count == closepointer_count)
    {
        //allocate memory to our table of pointer
        TablesElements * pointer_table = (TablesElements*) malloc(30000 * sizeof(TablesElements));
        //define cursor place
        TablesElements *cursor_place = &pointer_table[0];
        //initialise values
        size_t i = 0;
        for(; i < 30000 ; i++)
        {
            pointer_table[i].value = 0;
            pointer_table[i].pointer_table = NULL;
            pointer_table[i].pointer_table_size = 0;
            pointer_table[i].parent = pointer_table;
        }
        //size of code to check it and i for iterations    
        size_t size_of_code = strlen(code);
        i = 0;
        //mode d'affichage
        bool ascii = true;
        //execute the code line per line
        for(; i < size_of_code ; i++)
        {
            //give value to the pointer (character)
            if(code[i] == '#')
            {
                (*cursor_place).value = code[i + 1];
                i++;
            }
            //change mod of output, ascii or int
            if(code[i] == '$')
            {
                if(ascii == true)
                {
                    ascii = false;
                }
                else
                {
                    ascii = true;
                }
            }
            if(code[i] == '<')
            {
                if(cursor_place == pointer_table || cursor_place == cursor_place->parent->pointer_table)
                {
                    fputs("Can't reduce cursor at 0", stderr);
                    break;
                }
                else
                {
                    cursor_place--;
                }
            }
            else if(code[i] == '>')
            {
                if(cursor_place == pointer_table + 30000)
                {
                    fputs("Can't increase cursor at 30000 or max you set", stderr);
                    break;
                }
                else
                {
                    TablesElements * pointer_table2 = cursor_place->parent->pointer_table;
                    int Numberadded = cursor_place->parent->pointer_table_size;
                    if(cursor_place == pointer_table2 + Numberadded - 1)
                    {
                        fputs("Can't increase cursor at 30000 or max you set", stderr);
                        break;
                    }
                    else
                    {
                        cursor_place++;
                    }
                }
            }
            else if(code[i] == '+')
            {
                (*cursor_place).value++;
            }
            else if(code[i] == '-')
            {
                (*cursor_place).value--;
            }
            //create table of pointer
            else if(code[i] == '\\')
            {
                if((*cursor_place).pointer_table == NULL)
                {
                    int i2 = 0;
                    (*cursor_place).pointer_table_size += 10;
                    (*cursor_place).pointer_table = (TablesElements*) malloc((*cursor_place).pointer_table_size * sizeof(TablesElements));
                    TablesElements* local_pointer_table = (*cursor_place).pointer_table;
                    for(; i2 < 10; i2++)
                    {
                        local_pointer_table[i2].value = 0;
                        local_pointer_table[i2].pointer_table = NULL;
                        local_pointer_table[i2].pointer_table_size = 0;
                        local_pointer_table[i2].parent = cursor_place;
                    }
                }
                else
                {
                    int i2 = (*cursor_place).pointer_table_size;
                    (*cursor_place).pointer_table_size += 10;
                    (*cursor_place).pointer_table = (TablesElements*) realloc((*cursor_place).pointer_table, (*cursor_place).pointer_table_size * sizeof(TablesElements));
                    TablesElements* local_pointer_table = (*cursor_place).pointer_table;
                    for(; i2 < (*cursor_place).pointer_table_size; i2++)
                    {
                        local_pointer_table[i2].value = 0;
                        local_pointer_table[i2].pointer_table = NULL;
                        local_pointer_table[i2].pointer_table_size = 0;
                        local_pointer_table[i2].parent = cursor_place;
                    }
                }
            }
            //delete all pointers tables in the pointers
            else if(code[i] == '/')
            {
                if((*cursor_place).pointer_table != NULL)
                {
                    freeallmemory((*cursor_place).pointer_table, (*cursor_place).pointer_table_size);
                    (*cursor_place).pointer_table = NULL;
                    (*cursor_place).pointer_table_size = 0;
                }
                else
                {
                    fputs("\ncan't delete none table of pointers" , stderr);
                }
            }
            else if(code[i] == '.')
            {
                if(ascii == true)
                {
                    putchar((*cursor_place).value);
                }
                else
                {
                    printf("%d", (*cursor_place).value);
                }
            }
            else if(code[i] == ',')
            {
                (*cursor_place).value = getchar();
            }
            else if(code[i] == '[')
            {
                if((*cursor_place).value == 0)
                {
                    size_t i2 = i + 1;
                    size_t closing_loop; //pos of the closing loop
                    int stackloop = -1; //stack thing to detect if the other [ is not of another loop in loop
                    for(; i2 < size_of_code ; i2++)
                    {
                        //printf("%c", code[i2]);
                        if(stackloop != 0)
                        {
                            if(code[i2] == '[')
                            {
                                stackloop--;
                            }
                            else if(code[i2] == ']')
                            {
                                stackloop++;
                            }
                        }
                        else
                        {
                            closing_loop = i2 - 1;
                            break;
                        }
                    }
                    i = closing_loop;
                }
            }
            else if(code[i] == ']')
            {
                if((*cursor_place).value != 0)
                {
                    size_t i2 = i - 1;
                    size_t opening_loop; //pos of the opening loop
                    int stackloop = 1; //stack thing to detect if the other [ is not of another loop in loop
                    for(; i2 > 0 ; i2--)
                    {
                        //printf("%c", code[i2]);
                        if(stackloop != 0)
                        {
                            if(code[i2] == '[')
                            {
                                stackloop--;
                            }
                            else if(code[i2] == ']')
                            {
                                stackloop++;
                            }
                        }
                        else
                        {
                            opening_loop = i2 + 1;
                            break;
                        }
                    }
                    i = opening_loop;
                }
            }
            //enter in child table
            else if(code[i] == '(')
            {
                if((*cursor_place).pointer_table == NULL)
                {
                    fputs("not valid", stderr);
                    break;
                }
                else
                {
                    cursor_place = (*cursor_place).pointer_table;
                }
            }
            //enter in parent table
            else if(code[i] == ')')
            {
                cursor_place = (*cursor_place).parent;
            }
        }
        //desalocate memory to our table of pointer
        freeallmemory(pointer_table, 30000);
    }
    else
    {
        fputs("close any declaractions like () or []", stderr);
    }
}
