#include <stdio.h>

void test(int a[], int size)
{
    if (size > 3)
    {
        a[3] = 8;
    }

    size = 2; // Changing the parameter does not change the argument
}

int main()
{
    int arr[5], n = 5, i;

    for (i = 0; i < n; i++)
    {
        arr[i] = i;
    }

    printf("Original - 4th element: %d, Size: %d\n", arr[3], n);

    test(arr, n);
    printf("Post-Test Call - 4th element: %d, Size: %d", arr[3], n);

    return 0;
}
