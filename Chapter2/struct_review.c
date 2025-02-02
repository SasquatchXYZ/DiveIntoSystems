#include <stdio.h>
#include <string.h>

// Define a new struct type (outside function bodies)
struct studentT
{
    char name[64];
    int age;
    float gpa;
    int grad_yr;
};

// Function prototypes
int checkID(struct studentT s1, int min_age);
void changeName(char* old, char* new);

int main()
{
    int can_vote;
    // Declare variables of struct type;
    struct studentT student1, student2;

    // Access field values using `.`
    strcpy(student1.name, "Ruth");
    student1.age = 17;
    student1.gpa = 3.5;
    student1.grad_yr = 2021;

    // Structs are lvalues
    student2 = student1;
    strcpy(student2.name, "Frances");
    student2.age = student1.age + 4;

    // Passing a struct
    can_vote = checkID(student1, 18);
    printf("%s - Can Vote? %d, %d years old\n", student1.name, can_vote, student1.age);

    can_vote = checkID(student2, 18);
    printf("%s - Can Vote? %d, %d years old\n", student2.name, can_vote, student2.age);

    // Passing a struct field value
    changeName(student2.name, "Kwame");
    printf("Student 2's name is now %s\n", student2.name);

    return 0;
}

int checkID(struct studentT s, int min_age)
{
    int ret = 1;

    if (s.age < min_age)
    {
        ret = 0;
        // Changes age field IN PARAMETER COPY ONLY
        s.age = min_age + 1;
    }

    return ret;
}

void changeName(char* old, char* new)
{
    if ((old == NULL) || (new == NULL))
    {
        return;
    }
    strcpy(old, new);
}
