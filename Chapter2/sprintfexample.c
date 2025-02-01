#include <stdio.h>

int main()
{
    char str[64];
    float ave = 76.8;
    int num = 2;

    // Initialize str to format string, filling in each placeholder with
    // a char representation of its arguments' values
    sprintf(str, "%s is %d years old and in grade %d", "Henry", 12, 7);
    printf("%s\n", str);

    sprintf(str, "The average grade on exam %d is %g", num, ave);
    printf("%s\n", str);
}
