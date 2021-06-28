#include "display.h"

#include <stdio.h>
#include <string.h>

void DisplayMenu()
{
    printf("1 - Insert a new event\n");
    printf("2 - Display all events\n");
    printf("3 - Now?\n");
    printf("4 - Delete expired\n");
    printf("5 - Load Data\n");
    printf("6 - Export Data\n");
    printf("0 - Exit\n");
}

void convertTime(int hours, int minues, char *dst)
{
    char h[3];
    char m[3];
    char p[2];

    if (hours > 12)
    {
        sprintf(h, "%d", hours - 12);
        strncpy(p, "PM", 2);
    }
    else
    {
        sprintf(h, "%d", hours);
        strncpy(p, "AM", 2);
    }
    sprintf(m, "%d", minues);

    strncpy(dst, h, 2);
    strcat(dst, ":");
    strncat(dst, m, 2);
    strncat(dst, p, 2);
}

void PrintEventInfo(Event *event)
{
    struct tm startTM;
    struct tm endTM;
    char buf[20];
    startTM = *localtime(&event->beginDate);
    endTM = *localtime(&event->endDate);

    printf("%d/%d/%d\t", startTM.tm_mon + 1, startTM.tm_mday, startTM.tm_year + 1900);
    convertTime(startTM.tm_hour, startTM.tm_min, buf);
    printf("%s\t", buf);
    convertTime(endTM.tm_hour, endTM.tm_min, buf);
    printf("%s\t", buf);
    printf("%s\n", event->description);
}

void DisplayEvents(Node *head)
{
    printf("Schedule:\n");

    while (head->next != NULL)
    {
        head = head->next;
        PrintEventInfo(head->data);
    }
}

void DisplayCurrentActiveEvents(Node *head)
{
    time_t t = time(NULL);
    Node *p = head->next;
    printf("Currently active events: \n");
    while (p != NULL)
    {
        if (t > p->data->beginDate && t < p->data->endDate)
        {
            PrintEventInfo(p->data);
        }
        p = p->next;
    }
}

void DeleteExpiredEvents(Node *head)
{
    Node *prev = head;
    Node *cur = head->next;

    time_t t = time(NULL);

    Node *delNodeHead = malloc(sizeof(Node));
    delNodeHead->next = NULL;
    while (cur != NULL)
    {
        if (t > cur->data->endDate)
        {
            prev->next = cur->next;
            PrintEventInfo(cur->data);
            // 保存要被删除的节点
            cur->next = delNodeHead->next;
            delNodeHead->next = cur;

            cur = prev->next;
        }
        else
        {
            cur = cur->next;
        }
    }

    if (delNodeHead->next == NULL)
    {
        printf("No expired events\n");
        return;
    }

    printf("Deleting: \n");
    delNodeHead = delNodeHead->next;
    while (delNodeHead != NULL)
    {
        cur = delNodeHead;
        PrintEventInfo(cur->data);
        delNodeHead = delNodeHead->next;
        free(cur);
    }
}