#include "file.h"

int InputOption(char *prompt)
{
    char buffer[100];
    int result = -1;

    do
    {
        // 文件输入结束符
        if (feof(stdin))
        {
            break;
        }

        printf("%s", prompt);

        fgets(buffer, sizeof(buffer), stdin);

        if (strlen(buffer) > 0)
            buffer[strlen(buffer) - 1] = '\0';
        sscanf(buffer, "%d", &result);

    } while (!(result > -1 && result < 7));

    return result;
}

Event *InputEvent()
{
    Event *newEvent = malloc(sizeof(Event));
    time_t date;

    InputDescription("What is the event: ", newEvent->description, 50);
    date = InputDate("Event date: ");
    newEvent->beginDate = InputTime("Start time: ", date);
    newEvent->endDate = InputTime("End time: ", date);

    return newEvent;
}

void InputDescription(char *prompt, char *dst, int max)
{
    char buffer[100];

    printf("%s", prompt);

    /* Get a line of up to 100 characters */
    fgets(buffer, sizeof(buffer), stdin);

    /* Remove any \n we may have input */
    if (strlen(buffer) > 0)
        buffer[strlen(buffer) - 1] = '\0';

    strncpy(dst, buffer, 50);
}

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