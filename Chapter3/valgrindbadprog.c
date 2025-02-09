#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* a mystery function that takes a string and returns an int value */
int foo(char* str)
{
    char a[5]; // Valgrind can't find mem access errors with
    char b[5]; // variables statically allocated on the Stack
    char* c; // but it can with dynamically allocated heap memory
    int i;

    c = (char*)malloc(sizeof(char) * 5); // bad code - doesn't check for an error

    strcpy(a, "aaaa");
    strcpy(b, "bbbb");
    strcpy(c, "cccc");

    for (i = 0; i <= 5; i++)
    {
        // here we are going beyond the bounds
        // of "a", but Valgrind can't detect it
        // because the array is on the Stack
        a[i] = str[i];
    }

    for (i = 0; i <= 5; i++)
    {
        // here we are going beyond the bounds
        // of the array, and Valgrind can detect
        // it because the array is in the Heap
        c[i] = str[i];
    }

    printf("a = %s, b = %s, c = %s\n", a, b, c);

    // gere we are forgetting to free malloced space for c before
    // exiting this function: this is a memory leak
    return 0;
}

/* main function with some bad memory access errors */
int main(int argc, char* argv[])
{
    char* s;

    s = (char*)malloc(sizeof(char) * 8);
    strcpy(s, "ssssss");

    foo(s); // calling foo with an allocated and initialized string
    printf("s = %s\n", s);
    free(s); // deallocate space for s

    s = (char*)malloc(sizeof(char) * 8);
    foo(s); // calling foo with an allocated but uninitialized string

    free(s); // deallocate space for s
    foo(s); // calling foo with an unallocated and uninitialized string

    s = (char*)malloc(sizeof(char) * 8);
    strcpy(s, "xxxx");
    printf("s = %s\n", s);
    s = (char*)malloc(sizeof(char) * 8); // a memory leak
    printf("s = %s\n", s); // uninitialized read
    free(s);
    free(s); // freeing already free'ed memory

    return 0;
}
