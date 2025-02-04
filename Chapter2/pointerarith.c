#include <stdio.h>

#define N 10
#define M 20

int main()
{
    // Array declarations:
    char letters[N];
    int numbers[N], i, j;
    int matrix[N][M];

    // Declare pointer variables that will access int or char array elements
    // using pointer arithmetic (the pointer type must match array element type)
    char* cptr = NULL;
    int* iptr = NULL;

    // Make the pointer point to the first element in the array
    cptr = &(letters[0]); // &(letters[0]) is the address of element 0
    iptr = numbers; // the address of element 0 (numbers is &(numbers[0]))

    // initialized letters and numbers arrays through pointer variables
    for (i = 0; i < N; i++)
    {
        // dereference each pointer and update the element it currently points to
        *cptr = 'a' + i;
        *iptr = i * 3;

        // use pointer arithmetic to set each pointer to the next element
        cptr++; // cptr points to the next char address (next element of letter)
        iptr++; // iptr points to the next int address (next element of numbers)
    }

    printf("\n array values using indexing to access: \n");
    // see what the code above did:
    for (i = 0; i < N; i++)
    {
        printf("letters[%d] = %c, numbers[%d] = %d\n",
               i,
               letters[i],
               i,
               numbers[i]
        );
    }

    // we could also use pointer arithmetic to print thse out:
    printf("\n array values using pointer arithmetic to access: \n");
    // first: initialize pointers to base address of arrays:
    cptr = letters; // letters = &letters[0]
    iptr = numbers;
    for (i = 0; i < N; i++)
    {
        // dereference pointers to access array element values
        printf("letters[%d] = %c, numbers[%d] = %d\n",
               i,
               *cptr,
               i,
               *iptr
        );
        // increment pointers to point to next element
        cptr++;
        iptr++;
    }

    // sets matrix to:
    // row 0:   0,   1,   2, ...,  99
    // row 1: 100, 110, 120, ..., 199
    //        ...
    iptr = &(matrix[0][0]);
    for (i = 0; i < N * M; i++)
    {
        *iptr = i;
        iptr++;
    }

    // see what the above code did:
    printf("\n 2D array values inited using pointer arithmetic: \n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            printf("%3d, ", matrix[i][j]);
        }
        printf("\n");
    }

    iptr = &numbers[2];
    *iptr = -13;
    iptr += 4;
    *iptr = 9999;

    printf("\n changing values using pointer arithmetic \n");
    for (i = 0; i < N; i++)
    {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }

    return 0;
}
