#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 4

/*
 * initialize a 2D array
 * arr: the array
 * rows: number of rows
 * cols: number of columns
 */
void init2D_Method2(int** arr, int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            arr[i][j] = 0;
        }
    }
}

int main()
{
    // the 2D array variable is declared to be `int **` (a pointer to an int *)
    // a dynamically allocated array of dynamically allocated int arrays
    // (a pointer to pointers to ints)
    int** two_d_array;
    int i, j;

    // allocate an array of N pointers to ints
    // malloc returns the address of this array (a pointer to (int *)'s)
    two_d_array = malloc(sizeof(int*) * N);

    if (two_d_array == NULL)
    {
        printf("Error allocating memory\n");
        exit(1);
    }

    // for each row, malloc space for its column elements and add it to
    // the array of arrays
    for (i = 0; i < N; i++)
    {
        // malloc space for row i's M column elements
        two_d_array[i] = malloc(sizeof(int) * M);
        if (two_d_array[i] == NULL)
        {
            printf("Error allocating memory\n");
            exit(1);
        }
    }

    // access the array using the [] notation
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            two_d_array[i][j] = 0;
        }
    }

    // passing the 2D array to a function
    init2D_Method2(two_d_array, N, M);
}
