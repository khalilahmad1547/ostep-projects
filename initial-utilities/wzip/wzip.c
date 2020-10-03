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
                char pre_char[1];
                char next_char[1];
                int count[1];
                pre_char[0] = getc(read_from);
                next_char[0] = getc(read_from);
                count[0] = 1;
                int flage = 1;
                /*
                    flage = 1 we did't printied last calculated result
                    flage = 0 we have printed last calculated result
                */
                while (next_char[0] != EOF)
                {
                    if (pre_char[0] == next_char[0])
                    {
                        count[0]++;
                        flage = 1;
                    }
                    else
                    {
                        flage = 0;
                        fwrite(count, 4, 1, stdout);
                        fwrite(pre_char, 1, 1, stdout);
                        //printf("%d%c", count[0], pre_char[0]);
                        pre_char[0] = next_char[0];
                        count[0] = 1;
                    }

                    next_char[0] = getc(read_from);
                    // if (next_char[0] == EOF)
                    // {
                    //     flage = 1;
                    // }
                }
                if (flage == 1)
                {
                    fwrite(count, 4, 1, stdout);
                    fwrite(pre_char, 1, 1, stdout);
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
        printf("%s\n", "wzip: file1 [file2 ...]");
        exit(1);
    }

    exit(0);
}