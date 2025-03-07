#include <stdlib.h>

struct studentT
{
    char name[64];
    int age;
    float gpa;
    int year;
};

void updateAges(struct studentT* classroom, int size);

int main()
{
    struct studentT classroom1[40]; // An array of 40 struct studentT

    struct studentT* classroom2; // A pointer to a struct studentT
                                 // (for a dynamically allocated array)

    struct studentT* classroom3[50]; // An array of 40 struct studentT*
                                     // (each element stores a (struct studentT *))

    /* classroom1 is an array:
     *      use indexing to access a particular element
     *      each element in classroom1 stores a struct studentT:
     *      use dot notation to access fields
     */
    classroom1[3].age = 21;

    /* classroom2 is a pointer to a struct studentT:
     *      call malloc to dynamically allocate an array
     *      of 15 studentT structs for it to point to:
     */
    classroom2 = malloc(sizeof(struct studentT) * 15);

    /* each element in array pointed to by classroom2 is a studentT struct
     *      use [] notation to access an element of the array, and dot notation
     *      to access a particular field value of the struct at that index:
     */
    classroom2[3].year = 2013;

    /* classroom3 is an array of struct studentT *
     *      use [] notation to access a particular element
     *      call malloc to dynamically allocate a struct for it to point to
     */
    classroom3[5] = malloc(sizeof(struct studentT));

    // access fields of the struct using -> notation
    // set the age field pointed to in element 5 of the classroom3 array to 21
    classroom3[5]->age = 21;

    updateAges(classroom1, 40);
    updateAges(classroom2, 15);

    // Does not work because the types don't match
    // updateAges(classroom3, 50);
}

void updateAges(struct studentT* classroom, int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        classroom[i].age += 1;
    }
}
