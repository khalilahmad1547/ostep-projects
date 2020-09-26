#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc > 1) // files is specified
    {
        for (int i = 1; i < argc; i++)
        {
            FILE *to_open = fopen(argv[i], "r");
            if (to_open == NULL)
            {
                printf("%s\n", "wcat: cannot open file");
                exit(1);
            }
            else
            {
                char ch = getc(to_open);
                while (ch != EOF)
                {
                    printf("%c", ch);
                    ch = getc(to_open);
                }

                fclose(to_open);
            }
        }
    }
    else // file not specified
    {
        exit(0);
    }
}