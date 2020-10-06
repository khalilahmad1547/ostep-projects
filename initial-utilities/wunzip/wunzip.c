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
                int count[1];
                char char_to_print[1];

                while (!feof(read_from))
                {
                    fread(count, 4, 1, read_from);
                    fread(char_to_print, 1, 1, read_from);
                    for (int i = 0; i < count[0]; i++)
                    {
                        printf("%s", char_to_print);
                    }
                }
                fclose(read_from);
                //fwrite("\n", 1, 1, stdout);
            }
        }
    }
    else
    {
        /*
            No file is specified.
        */
        printf("%s\n", "wunzip: file1 [file2 ...]");
        exit(1);
    }

    exit(0);
}