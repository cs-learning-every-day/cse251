#include <stdio.h>
#include <string.h>

#include "transistors.h"

void InputString(char *str, int max);
double InputPositiveValues(char *prompt);
int InputTransistorType(char *prompt);
int InputTransistorCaseStyle(char *prompt);

void DisplayTransistor(Tran tran)
{
    printf("Number: %s\n", tran.number);
    switch (tran.type)
    {
    case NPN:
        printf("Type: NPN\n");
        break;

    case PNP:
        printf("Type: PNP\n");
        break;
    }

    printf("pMax: %.3f\n", tran.pmax);
    printf("icMax: %.3f\n", tran.icmax);
    printf("caseStyle: ");
    switch (tran.caseStyle)
    {
    case TO18:
        printf("TO18");
        break;
    case TO92A:
        printf("TO92A");
        break;
    case TO92C:
        printf("TO92C");
        break;
    case TO220:
        printf("TO220");
        break;
    case TO39:
        printf("TO39");
        break;
    default:
        printf("Error");
        break;
    }
    printf("\n\n");
}

Tran InputTransistor()
{
    Tran t1;

    // strcpy(t1.number, "2N3053");

    printf("Input Number: ");
    InputString(t1.number, sizeof(t1.number));

    t1.pmax = InputPositiveValues("Input pMax: ");
    t1.icmax = InputPositiveValues("Input icMax: ");
    t1.type = InputTransistorType("Input type: ");
    t1.caseStyle = InputTransistorCaseStyle("Input case style:");

    return t1;
}

int InputTransistorCaseStyle(char *prompt)
{
    char buffer[100];
    int value = 0;

    do
    {
        printf("%s(%s)", prompt, "1 to 5");

        fgets(buffer, sizeof(buffer), stdin);

        if (strlen(buffer) > 0)
            buffer[strlen(buffer) - 1] = '\0';
        sscanf(buffer, "%d", &value);
    } while (!(value > 0 && value < 6));

    return value;
}

int InputTransistorType(char *prompt)
{
    char buffer[100];
    int value = 0;

    do
    {
        printf("%s(%s)", prompt, "1 or 2");

        fgets(buffer, sizeof(buffer), stdin);

        if (strlen(buffer) > 0)
            buffer[strlen(buffer) - 1] = '\0';
        sscanf(buffer, "%d", &value);
    } while (value != NPN && value != PNP);

    return value;
}

void InputString(char *str, int max)
{
    char buffer[100];

    /* Get a line of up to 100 characters */
    fgets(buffer, sizeof(buffer), stdin);

    /* Remove any stray newlines from the buffer */
    while (buffer[0] == '\n')
        fgets(buffer, sizeof(buffer), stdin);

    /* Remove any \n we may have input */
    if (strlen(buffer) > 0)
        buffer[strlen(buffer) - 1] = '\0';

    /* Copy up to max characters to our string */
    strncpy(str, buffer, max);
    str[max - 1] = '\0';
}

double InputPositiveValues(char *prompt)
{
    char buffer[100];
    double value = 0;
    do
    {
        printf("%s", prompt);

        /* Get a line of up to 100 characters */
        fgets(buffer, sizeof(buffer), stdin);

        /* Remove any \n we may have input */
        if (strlen(buffer) > 0)
            buffer[strlen(buffer) - 1] = '\0';

        sscanf(buffer, "%lf", &value);
    } while (value <= 0);
    return value;
}