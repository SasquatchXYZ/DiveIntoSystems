#include <stdio.h>
#include <string.h>

/* struct type definition */
struct studentT
{
    char name[64];
    int age;
    float gpa;
    int grad_yr;
};

/* function prototype (prototype: a declaration of the
 * checkID function so that main can call it, its full
 * definition is listed after main function in the file):
 */
int checkID(struct studentT s, int min_age);

int main()
{
    int can_vote;
    struct studentT student;

    strcpy(student.name, "Ruth");
    student.age = 17;
    student.gpa = 3.5;
    student.grad_yr = 2021;

    can_vote = checkID(student, 18);

    if (can_vote)
    {
        printf("%s is %d years old and can vote.\n",
               student.name, student.age);
    }
    else
    {
        printf("%s is only %d years old and cannot vote.\n",
               student.name, student.age);
    }

    return 0;
}

/* check if a student is at least the min age
 * s: a student
 * min_age: a minimum age value to test
 * returns: 1 if the student is min_age or older, 0 otherwise
 */
int checkID(struct studentT s, int min_age)
{
    int ret = 1; // initialize the return value to 1 (true)

    if (s.age < min_age)
    {
        ret = 0; // update the return value to 0 (false)

        // lets try changing the student's age
        s.age = min_age + 1;
    }

    printf("%s is %d years old\n", s.name, s.age);

    return ret;
}
