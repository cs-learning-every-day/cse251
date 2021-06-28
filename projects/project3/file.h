#ifndef FILE_H
#define FILE_H
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct _event
{
    char description[50];
    time_t beginDate;
    time_t endDate;
} Event;

typedef struct _node
{
    Event *data;
    struct _node *next;
} Node;

int InputOption(char *prompt);
Event *InputEvent();
time_t InputDate(char *prompt);
time_t InputTime(char *prompt, time_t date);
void InputDescription(char *prompt, char *dst, int max);

#endif