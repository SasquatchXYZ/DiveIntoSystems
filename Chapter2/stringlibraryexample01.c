#include <stdio.h>
#include <stdlib.h>
#include <string.h> // include the string library

int main()
{
    // Variable declarations that will be used in examples
    int len, i, ret;
    char str[32];
    char *d_str, *ptr;

    strcpy(str, "Hello There");
    len = strlen(str); // len is 11

    d_str = malloc(sizeof(char) * (len + 1));
    if (d_str == NULL)
    {
        printf("Error allocating memory\n");
        exit(1);
    }

    strncpy(d_str, str, 5);
    d_str[5] = '\0'; // set the terminating null character

    printf("%d:%s\n", strlen(str), str); // prints: 11:Hello There
    printf("%d:%s\n", strlen(d_str), d_str); // prints: 5:Hello

    strcpy(str, "alligator");
    strcpy(d_str, "Zebra");

    ret = strcmp(str, d_str);
    if (ret == 0)
    {
        printf("%s is equal to %s\n", str, d_str);
    }
    else if (ret < 0)
    {
        printf("%s is less than %s\n", str, d_str);
    }
    else
    {
        printf("%s is greater than %s\n", str, d_str); // true for these strings
    }

    ret = strncmp(str, "all", 3); // returns 0: they are equal up to the first 3 chars
    if (ret == 0)
        printf("The first 3 chars of '%s' are equal\n", str);

    return 0;
}
