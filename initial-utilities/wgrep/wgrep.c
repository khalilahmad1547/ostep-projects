#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc > 1) // string is specified
    {
        if (argc > 2) // file is specified
        {

            for (int i = 2; i < argc; i++)
            {
                FILE *to_open = fopen(argv[i], "r");
                if (to_open == NULL) //file cannot open
                {
                    printf("%s\n", "wgrep: cannot open file");
                    exit(1);
                }
                else
                {
                    char ch = getc(to_open);
                    while ((ch != EOF || ch == '\n'))
                    {
                        printf("%c", ch);
                        ch = getc(to_open);
                    }

                    fclose(to_open);
                }
            }
        }
        else
        {
        }
    }
    else // string for seaarch is not specified
    {
        printf("%s\n", "wgrep: searchterm [file ...]");
        exit(0);
    }
    exit(0);
}