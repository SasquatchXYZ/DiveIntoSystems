#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* infile;
    FILE* outfile;

    infile = fopen("input.txt", "r"); // relative path name of file, read mode
    if (infile == NULL)
    {
        printf("Error: unable to open file %s\n", "input.txt");
        exit(1);
    }

    // fopen with absolute path name of file, write mode
    outfile = fopen("/home/me/output.txt", "w");
    if (outfile == NULL)
    {
        printf("Error: unable to open outfile\n");
        exit(1);
    }

    int ch; // EOF is not a char value, but is an int.
    // since all char values can be stored in int, use int for char

    ch = getc(infile); // read next char from the infile stream
    if (ch != EOF)
    {
        putc(ch, outfile); // write the char to the outfile stream
    }

    // Example calls to `fscanf` and `fprintf`
    int x, b;
    double d;
    char c, array[SIZE_MAX];

    // write int & char values to file separated by colon with newline at the end
    fprintf(outfile, "%d:%c\n", x, c);

    // read an int & char from file where int and char are separated by a comma
    fscanf(infile, "%d,%c", &x, &c);

    // read a string from a file into array (stops reading at whitespace char)
    fscanf(infile, "%s", array);

    // read a double and a string up to 24 chars from infile
    fscanf(infile, "%lf %24s", &d, array);

    // read in a string consisting of only char values in the specified set (0-5)
    // stops reading when...
    //   20 chars have been read OR
    //   a character not in the set is reached OR
    //   end of file is reached (EOF)
    fscanf(infile, "%20[012345]", array);

    // read in a string; stop when reaching a punctuation mark from the set
    fscanf(infile, "%[^.,:!;]", array);

    // read in two integer values: store the first in long, second in int
    // then read in a char value following the int value
    fscanf(infile, "%ld %d%c", &x, &b, &c);

    fclose(infile);
    fclose(outfile);

    return 0;
}
