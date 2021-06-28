#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

time_t InputDate(char *prompt)
{
    char buffer[100];
    char *result;
    struct tm date;

    do
    {
        printf("%s", prompt);

        /* Get a line of up to 100 characters */
        fgets(buffer, sizeof(buffer), stdin);

        /* Remove any \n we may have input */
        if (strlen(buffer) > 0)
            buffer[strlen(buffer) - 1] = '\0';

        result = strptime(buffer, "%m/%d/%Y", &date);

    } while (result == NULL);

    /* Convert to time_t format */
    date.tm_min = 0;
    date.tm_hour = 0;
    date.tm_sec = 0;
    date.tm_isdst = 0;

    return mktime(&date);
}

time_t InputTime(char *prompt, time_t date)
{
    char buffer[100];
    char *result;
    struct tm time;

    time = *localtime(&date);

    do
    {
        printf("%s", prompt);

        /* Get a line of up to 100 characters */
        fgets(buffer, sizeof(buffer), stdin);

        /* Remove any \n we may have input */
        if (strlen(buffer) > 0)
            buffer[strlen(buffer) - 1] = '\0';

        result = strptime(buffer, "%I:%M%p", &time);

    } while (result == NULL);

    return mktime(&time);
}

int main(void)
{
    while (1)
    {
        time_t t = InputDate("Date:");
        struct tm startTM;

        /* ... */

        startTM = *localtime(&t);
        t = InputTime("Start time: ", t);
        printf("%d %d %d\n", startTM.tm_year + 1900, startTM.tm_mon, startTM.tm_mday);
        printf("The date/time is %s\n", ctime(&t));
        char p[3];
        strncpy(p, "abc", 3);
        strcat(p, p);
        printf("%s", p);
    }

    exit(EXIT_SUCCESS);
}