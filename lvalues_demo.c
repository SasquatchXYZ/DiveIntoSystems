#include <stdio.h>
#include <string.h>

struct studentT
{
    char name[32];
    int age;
    float gpa;
    int grad_year;
};

int main()
{
    struct studentT student1, student2;
    int x;
    char arr[10], ch;

    x = 10;                     // Valid C: x is an lvalue
    ch = 'm';                   // Valid C: ch is an lvalue
    student1.age = 18;          // Valid C: age field is an lvalue
    student2 = student1;        // Valid C: student2 is an lvalue
    arr[3] = ch;                // Valid C: arr[3] is an lvalue

    x + 1 = 8;        // Invalid C: x + 1 is not an lvalue
    arr = "hello";    // Invalid C: arr is not an lvalue
                      // cannot change base addr of statically deeclared array
                      // (use `strcpy` to copy the string value "hello" to arr)

    student1.name = student2.name;    // Invalid C: name field is not an lvalue
                                      // (the base address of a statically
                                      // declared string is not an lvalue)

    strcpy(student1.name, student2.name);

    return 0;
}
