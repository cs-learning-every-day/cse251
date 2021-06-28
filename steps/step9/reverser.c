#include <stdio.h>
#include <string.h>

/* 
 * Name : XmchxCoder
 * Program to experiment with files
 */

void Reverse(char[]);

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Insufficient arguments\n");
        return 1;
    }

    FILE *inFile;
    FILE *outFile;
    char line[120];

    printf("Copy from file: %s\n", argv[1]);
    printf("Copy to file: %s\n", argv[2]);

    inFile = fopen(argv[1], "r");
    if (inFile == NULL)
    {
        fprintf(stderr, "Unable to open file %s\n", argv[1]);
        return 1;
    }

    outFile = fopen(argv[2], "w");
    if (outFile == NULL)
    {
        fprintf(stderr, "Unable to open file %s\n", argv[1]);
        return 1;
    }

    /* While we are not at the end of the file */
    while (!feof(inFile))
    {
        /* Read a line of text from the file*/
        fgets(line, sizeof(line), inFile);

        /* Remove the newline at the end of the line */
        if (strlen(line) > 0)
        {
            line[strlen(line) - 1] = '\0';
        }
        Reverse(line);
        fprintf(outFile, "%s\n", line);
    }

    fclose(outFile);
    fclose(inFile);
}

void Reverse(char str[])
{
    int front = 0;
    int back = strlen(str) - 1;
    char t;

    while (front < back)
    {
        t = str[front];
        str[front] = str[back];
        str[back] = t;
        front++;
        back--;
    }
}
