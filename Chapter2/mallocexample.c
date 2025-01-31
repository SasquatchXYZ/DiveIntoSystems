#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* p;

    p = malloc(sizeof(int)); // Allocate heap memory for storing an int

    if (p != NULL)
    {
        *p = 6; // The heap memory p points to gets the value 6
    }
}
