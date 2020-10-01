#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        /*
            File is specified.
        */
        for (int i = 1; i < argc; i++)
        {
            FILE *read_from = fopen(argv[i], "r");
            char pre_char = getc(read_from);
            char next_char = getc(read_from);
            int count = 0;
            while (next_char != EOF)
            {
                if (pre_char == next_char)
                {
                    count++;
                }
                else
                {
                    printf("%d%c", count, pre_char);
                    count = 0;
                }
                pre_char = next_char;
                next_char = getc(read_from);
            }
            fclose(read_from);
            printf("\n");
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