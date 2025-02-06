#include <stdio.h>
#include <string.h>

int main()
{
    char str1[10];
    char str2[10];
    int len;

    str1[0] = 'h';
    str1[1] = 'i';
    str1[2] = '\0';

    len = strlen(str1);

    printf("%s %d\n", str1, len); // hi 2

    strcpy(str2, str1);
    printf("%s\n", str2); // hi

    strcpy(str2, "hello");
    len = strlen(str2);
    printf("%s has %d characters\n", str2, len);

    return 0;
}
