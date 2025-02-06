#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char str[64];
    int len, i;

    strcpy(str, "I see 20 ZEBRAS, GOATS, and COWS");

    if (islower(str[2]))
    {
        printf("%c is lower case\n", str[2]);
    }

    len = strlen(str);
    for (i = 0; i < len; i++)
    {
        if (isupper(str[i]))
        {
            str[i] = tolower(str[i]);
        }
        else if (isdigit(str[i]))
        {
            str[i] = 'X';
        }
    }

    printf("%s\n", str);

    return 0;
}
