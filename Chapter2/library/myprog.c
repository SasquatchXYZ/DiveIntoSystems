#include <stdio.h>
#include "mylib.h"

int main()
{
    float val1, val2, ret;
    printf("Enter two float values: ");
    scanf("%f%f", &val1, &val2);
    ret = bigger(val1, val2); // use a library function
    printf("%f is the biggest\n", ret);

    return 0;
}
