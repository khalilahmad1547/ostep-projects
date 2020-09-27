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
                    int t_lines = 0;
                    int c_in_line = 0;
                    char ch = getc(to_open);
                    while (ch != EOF)
                    {
                        if (ch == '\n')
                        {
                            t_lines++;
                        }
                        else
                        {
                            c_in_line++;
                        }
                        ch = getc(to_open);
                    }

                    printf("\n Total Char:%d Total lines:%d\n", c_in_line, t_lines);

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