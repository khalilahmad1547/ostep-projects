#include <stdio.h>
#include <stdlib.h>
#define TO_DEBUG 0
void D_log(char *msg, int to_print);
int main(int argc, char *argv[])
{
    if (argc >= 2)
    {
        D_log("intside if (argc >= 2)", TO_DEBUG);
        /*
            File is specified.
        */
        for (int i = 1; i < argc; i++)
        {
            D_log("intside for (int i = 1; i < argc; i++)", TO_DEBUG);
            FILE *read_from = fopen(argv[i], "r");
            if (read_from == NULL)
            {
                exit(1);
            }
            else
            {
                char pre_char = getc(read_from);
                char next_char = getc(read_from);
                int count = 1;
                while (next_char != EOF)
                {
                    D_log("intside while (next_char != EOF)", TO_DEBUG);
                    if (pre_char == next_char)
                    {
                        count++;
                    }
                    else
                    {
                        printf("%d%c", count, pre_char);
                        pre_char = next_char;
                        next_char = getc(read_from);
                        count = 1;
                    }
                    next_char = getc(read_from);
                }
                fclose(read_from);
                printf("\n");
            }
        }
    }
    else
    {
        /*
            No file is specified.
        */
        printf("%s\n", "wzip: file1 [file2 ...]");
        exit(1);
    }

    exit(0);
}

void D_log(char *msg, int to_print)
{
    if (to_print == 1)
    {
        printf("%s\n", msg);
    }
}