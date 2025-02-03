#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* argc: a count of the number of command line arguments, the executable
 *       name (command) is included so argc is at least 1 for every program
 * argv: an array of strings, there is one string for each command line arg
 */
int main(int argc, char* argv[])
{
    int age, i;
    float gpa;
    long long id;
    char* name;

    // lets just print out the argv strings to see what they are:
    for (i = 0; i < argc; i++)
    {
        printf("Command line argument %2d: %s\n", i, argv[i]);
    }
    printf("\n");

    // In a program that takes command line arguments, usually there
    // is code to check that hte user passed in the correct number of
    // command line arguments, and if not, often an error message with
    // some information on how to call this executable is printed out
    // (what command line this program expects, and in which order),
    // and then a call to exit stops execution.  Sometimes some command
    // line options are optional, in which case default values should
    // be set by the program, and a check for them existing should be
    // made before trying to access what would be their argv[1] value

    // (1) check that the user passed the correct number of command line args
    if (argc != 5)
    {
        printf("Usage: ./prog name age id_num gpa\n");
        exit(1);
    }

    // (2) get command line argument's values, sometimes converting them
    //     from strings to other types
    // atoi, atol, atoll, atof converts a string of numeric characters to
    // the equivalent int, long, long long, or float value
    age = atoi(argv[2]);
    id = atoll(argv[3]);
    gpa = atof(argv[4]);

    // Let's copy the name argument to a dynamically allocated
    // string and modify it (just to illustrate malloc, strlen, strcpy)
    name = malloc(sizeof(char) * (strlen(argv[1]) + 1));
    if (!name)
    {
        printf("Error allocating memory\n");
        exit(1);
    }

    if (strcpy(name, argv[1]) != NULL)
    {
        printf("Name: %s Age: %d, Id: %lld, GPA: %3.2f\n",
               name,
               age,
               id,
               gpa
        );
    }
    else
    {
        printf("Error: strcpy failed...\n");
    }

    free(name);
    name = NULL;

    return 0;
}
