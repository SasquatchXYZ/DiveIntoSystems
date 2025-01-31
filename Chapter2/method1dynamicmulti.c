#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 4

/*
 * Initialize all elements in a 2D array to 0
 *  arr: the array
 *  rows: number of rows
 *  cols: number of columns
 */
void init_2d_array(int* arr, int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            arr[i * cols + j] = 0;
        }
    }
}

int main()
{
    int i, j;
    int* two_d_array; // the type is a pointer to an int (the element type)

    // Allocate in a single malloc of N * M int-sized elements
    two_d_array = malloc(sizeof(int) * N * M);

    if (two_d_array == NULL)
    {
        printf("Error allocating memory\n");
        exit(1);
    }

    // OPTION 1:
    // access using [] notation:
    //  cannot use [i][j] syntax because the compiler has no idea where the
    //  next row starts within this chunk of heap space, so the programmer
    //  must explicitly add a function of row and column index values
    //  (i * M + j) to map their 2D view of the space into the 1D chunk of memory
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            two_d_array[i * M + j] = i * j;
        }
    }

    // OPTION 2:
    // access using a function of row and column index values
    init_2d_array(two_d_array, N, M);
}
