#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc >= 1) // string is specified
    {
        if (argc >= 2) // file is specified
        {
            for (int i = 2; i < argc; i++)
            {
                char str[100];
                FILE *to_open = fopen(argv[i], "r");
                if (to_open == NULL) //file cannot open
                {
                    printf("%s\n", "wgrep: cannot open file");
                    exit(1);
                }
                else
                {
                    while (fgets(str, 100, to_open) != NULL)
                    {
                        printf("%s", str);
                    }
                }
                fclose(to_open);
            }
        }
        else
        {
            /*  
                No file is specified
                standerd input method
            */
        }
        }
    else
    {
        /* 
            zero command line arguments

         */
        printf("%s", "wgrep: searchterm [file ...]");
        exit(1);
    }
    exit(0);
}