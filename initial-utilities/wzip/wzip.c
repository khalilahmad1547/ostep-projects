#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc >= 2)
    {
        /*
            File is specified.
        */
        for (int i = 1; i < argc; i++)
        {
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