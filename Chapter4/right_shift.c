#include <stdio.h>

int main(int argc, char** argv)
{
    /* Unsigned integer value: u_val */
    unsigned int u_val = 0xFF000000;

    /* Signed integer value: s_val */
    int s_val = 0xFF000000;

    printf("u_val >> 12: %08X\n", u_val >> 12); // Logical right shift
    printf("s_val >> 12: %08X\n", s_val >> 12); // Arithmetic right shift

    return 0;
}
