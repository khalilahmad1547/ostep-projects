#include <stdio.h>

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        FILE *to_open = fopen(argv[i + 1], "r");
        char ch = getc(to_open);
        while (ch != EOF)
        {
            printf("%c", ch);
            ch = getc(to_open);
        }

        fclose(to_open);
    }
}