#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIMIT 200
int Search(char *str1, char *str2);
int main(int argc, char *argv[])
{
    if (argc == 1) // nothing specified
    {
        printf("%s\n", "wgrep: searchterm [file ...]");
        exit(1);
    }
    else if (argc == 2) // only string is specified
    {
        /*
            No file is specified
            standerd input method
        */
        // char str[MAX_LIMIT];
        // fgets(str, MAX_LIMIT, stdin);
        // if (Search(argv[1], str) == 1)
        // {
        //     printf("%s", str);
        // }
        while (1)
        {
            char str[MAX_LIMIT];
            fgets(str, MAX_LIMIT, stdin);
            if (Search(argv[1], str) == 1)
            {
                printf("%s", str);
            }
        }
    }
    else
    {
        for (int i = 2; i < argc; i++)
        {
            char str[MAX_LIMIT];
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
                    if (strncmp(argv[1], str, strlen(argv[1])) == 0)
                    {
                        printf("%s", str);
                    }
                    else
                    {
                        if (Search(argv[1], str) == 1)
                        {
                            printf("%s", str);
                        }
                    }
                }
            }
            fclose(to_open);
        }
    }
    exit(0);
}

//////////////////////////
int Search(char *to_search, char *from)
{
    for (int i = 0; i < strlen(from); i++)
    {
        if (to_search[0] == from[i])
        {
            int matched = 1;
            int temp = i + 1;
            for (int j = 1; j < strlen(to_search); j++)
            {
                if (from[temp] == to_search[j])
                {
                    matched++;
                    temp++;
                }
                else
                {
                    break;
                }

                if (matched == strlen(to_search))
                {
                    return 1;
                }
            }
        }
    }
}