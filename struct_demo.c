#include <stdio.h>
#include <string.h>

struct studentT
{
    char name[64]; // Character array, for use as a string
    int age;
    float gpa;
    int grad_year;
};

int main()
{
    struct studentT student1, student2;

    // The `name` field is an array of characters, so we can use the `strcpy`
    // string library function to fill in the array with a string value.
    strcpy(student1.name, "Kwame Salter");

    // The `age` field is an integer
    student1.age = 18 + 2;

    // The `gpa` field is a float
    student1.gpa = 3.5;

    // The `grad_year` field is an integer
    student1.grad_year = 2020;

    printf("Name: %s, Age: %d, GPU: %g, Year: %d\n",
           student1.name,
           student1.age,
           student1.gpa,
           student1.grad_year
    );

    // student2 gets the value of student1
    // (student1's field values are copied to
    // corresponding field values of student2)
    student2 = student1;

    // Change one field value
    strcpy(student2.name, "Frances Allen");
    student2.grad_year = student2.grad_year + 1;

    printf("Name: %s, Age: %d, GPU: %g, Year: %d\n",
           student2.name,
           student2.age,
           student2.gpa,
           student2.grad_year
    );

    // Note: the `%lu` format placeholder specifies an unsigned long value
    printf("Number of bytes in student struct: %lu\n", sizeof(struct studentT)); // should be > 76 bytes
    // 64 bytes for the name (1 for each char)
    // 4 bytes for the int age field
    // 4 bytes for the float gpa field
    // 4 bytes for the int grad_year field

    return 0;
}
