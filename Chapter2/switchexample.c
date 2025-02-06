#include <stdio.h>

int main()
{
    int num, new_num = 0;

    printf("Enter a number between 6 and 9: ");
    scanf("%d", &num);

    switch (num)
    {
    case 6:
        new_num = num + 1;
        break;
    case 7:
        new_num = num;
        break;
    case 8:
        new_num = num - 1;
        break;
    case 9:
        new_num = num + 2;
        break;
    default:
        printf("Hey, %d is not between 6 and 9\n", num);
    }

    printf("num: %d, new_num: %d\n", num, new_num);
    return 0;
}
