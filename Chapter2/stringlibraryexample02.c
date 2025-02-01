#include <stdio.h>
#include <stdlib.h>
#include <string.h> // include the string library

int main()
{
    char str[32];
    char* ptr;

    strcpy(str, "Zebra fish");
    strcat(str, " stripes");
    printf("%s\n", str); // Prints: Zebra fish stripes

    strncat(str, " are black.", 8);
    printf("%s\n", str); // Prints: Zebra fish stripes are bla (spaces count)

    ptr = strstr(str, "trip");
    if (ptr != NULL)
    {
        printf("%s\n", ptr); // Prints: tripes are bla
    }

    ptr = strchr(str, 'e');
    if (ptr != NULL)
    {
        printf("%s\n", ptr); // Prints: ebra fish stripes are bla
    }

    return 0;
}
