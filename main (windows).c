#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "brainfuck.h"
#include "io.h"

int main(int argc, char * argv[])
{
    //verify if argument exists
    if(argv[1] != NULL)
    {
        //verify if file exists
        if(_access(argv[1], 0) == 0)
        {
            //detect if it's the correct extension
            char *extension = strchr(argv[1], '.');
            if(extension != NULL && strcmp(extension, ".bf") == 0)
            {
                FILE *fp;
                long lSize;
                char *buffer;
        
                //if error occur in reading the file
                if(fopen_s(&fp, argv[1], "rb") != 0)
                {
                    fclose(fp);
                    perror("\nERROR FOR READING THE FILE\n");
                    return 1;
                }
                //if no error in reading the file
                else
                {
                    //take size of file
                    fseek(fp , 0L , SEEK_END);
                    lSize = ftell(fp);
                    rewind(fp);

                    // allocate memory for entire content
                    buffer = calloc( 1, lSize+1 );
                    if(!buffer)
                    {
                        fclose(fp);
                        fputs("\nmemory alloc fails\n", stderr);
                        exit(1);
                    }

                    // copy the file into the buffer
                    if( 1!=fread( buffer , lSize, 1 , fp) )
                    {
                        fclose(fp);
                        free(buffer);
                        fputs("\nentire read fails\n",stderr);
                        exit(1);
                    }

                    // close file and execute brainfuck code
                    fclose(fp);
                    execute(buffer);
                    free(buffer);
                }
            }
            else
            {
                fputs("\nThe file you provided doesn't have the correct extension (.bf)\n", stderr);
            }
            
        }
        else
        {
            perror("\nPlease enter a valid file\n");
            return 1;
        }
    }
    else
    {
        fputs("\nPlease enter a file name\n", stderr);
        return 1;
    }
    return 0;
}
