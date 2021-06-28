#include <stdbool.h>
#include "file.h"
#include "display.h"

#define kFilename "schedule.dat"

void addEvent(Event *event, Node *head);
void freeEvent(Node *head);
void showOverlaps(Node *cur, Node *head);
void LoadFile(Node *head);
void SaveFile(Node *head);

int main()
{
    Node *head;
    int op;

    // 初始化仓库
    head = malloc(sizeof(Node));
    head->data = NULL;
    head->next = NULL;

    while (true)
    {
        DisplayMenu();
        op = InputOption("Please select an option: ");

        switch (op)
        {
        case 0:
            freeEvent(head);
            exit(EXIT_SUCCESS);
        case 1:
            // Insert a new event
            addEvent(InputEvent(), head);
            break;
        case 2:
            // Display all events
            DisplayEvents(head);
            break;
        case 3:
            //  NOw?
            DisplayCurrentActiveEvents(head);
            break;
        case 4:
            // Delete expired
            DeleteExpiredEvents(head);
            break;
        case 5:
            LoadFile(head);
            break;
        case 6:
            SaveFile(head);
            break;
        default:
            freeEvent(head);
            printf("Error Option\n");
            exit(EXIT_FAILURE);
        }
    }

    freeEvent(head);
    return 0;
}

void LoadFile(Node *head)
{
    printf("未实现\n");
    return;
    FILE *file = fopen(kFilename, "r");
    char buffer[256];
    int numEvents = 0;

    if (file == NULL)
    {
        file = fopen(kFilename, "w");

        fclose(file);
        return;
    }

    fscanf(file, "%d\n", &numEvents);
    // printf("%d\n", numEvents);
    // fseek(file, sizeof(int), SEEK_CUR);

    while (fgets(buffer, sizeof(buffer), file))
    {

        if (strlen(buffer) > 0)
            buffer[strlen(buffer) - 1] = '\0';
        printf("%s\n", buffer);
    }

    fclose(file);
}

void SaveFile(Node *head)
{
    printf("未实现\n");
    return;
    FILE *file = fopen(kFilename, "w");
    int i;
    int numEvents = 0;

    fprintf(file, "%d\n", numEvents);

    fclose(file);
}

// 是否重叠
void showOverlaps(Node *cur, Node *head)
{
    bool overlaps = false;
    Node *p = head->next;
    while (p != NULL)
    {
        if (p != cur)
        {
            if (cur->data->beginDate < p->data->endDate ||
                cur->data->endDate > p->data->beginDate)
            {
                overlaps = true;
            }
        }

        p = p->next;
    }

    if (!overlaps)
    {
        return;
    }

    p = head->next;
    printf("Warning, this event overlaps: \n");
    while (p != NULL)
    {
        if (p != cur)
        {
            if (
                (cur->data->beginDate < p->data->endDate && cur->data->endDate > p->data->beginDate) ||
                (cur->data->endDate > p->data->beginDate && p->data->endDate > cur->data->beginDate))
            {
                PrintEventInfo(p->data);
            }
        }

        p = p->next;
    }
}

void addEvent(Event *event, Node *head)
{
    Node *newNode;
    newNode = malloc(sizeof(Node));
    newNode->data = event;
    if (head->next == NULL)
    {
        newNode->next = NULL;
        head->next = newNode;
    }
    else
    {
        // 按日期顺序排序
        Node *p = head;
        while (p->next != NULL && p->next->data->beginDate < event->beginDate)
        {
            p = p->next;
        }
        newNode->next = p->next;
        p->next = newNode;

        showOverlaps(newNode, head);
    }
}

void freeEvent(Node *head)
{
    Node *p = head;
    while (head != NULL)
    {
        head = head->next;
        free(p);
        p = head;
    }
}