#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
 * Name :  <insert name here>
 * 
 * Simple Wumpus game in 1D
*/

/* Add any #defines here */
/* Id's for things in our Cave */
#define Empty 0
#define Wumpus 1
#define End 2
/* Number of rooms in our Cave */
#define CaveSize 20
#define ArraySize (CaveSize + 2)
/* Directions I can face */
#define Left 0
#define Right 1

/* Add any function prototypes here */
void CreateWorld(int[]);
int *GetEmptyRoom(int[]);
void DisplayWorld(int[], int *, int);
int DifferenceByDirection(int);
bool DisplayStatus(int[], int *);
void Fire(int *, int);

bool isWin = false;

int main()
{
    int cave[ArraySize];
    int *agentRoom;
    int agentDirection;
    int direction;
    char command[20];

    /* Seed the random number generator */
    srand(time(NULL));

    CreateWorld(cave);
    agentRoom = GetEmptyRoom(cave);
    agentDirection = rand() % 2;

    while (true)
    {
        if (DisplayStatus(cave, agentRoom))
            break;
        DisplayWorld(cave, agentRoom, agentDirection);
        /* Get the command */
        printf("Command: ");
        scanf("%20s", command);

        if (strcmp(command, "quit") == 0)
        {
            break;
        }
        else if (strcmp(command, "move") == 0)
        {
            /* Move command */
            /* What way do we need to go? */
            direction = DifferenceByDirection(agentDirection);
            if (*(agentRoom + direction) != End)
                agentRoom += direction;
        }
        else if (strcmp(command, "turn") == 0)
        {
            agentDirection = !agentDirection;
        }
        else if (strcmp(command, "fire") == 0)
        {
            Fire(agentRoom, agentDirection);
        }
        else
        {
            printf("I don't know what you are talking about\n");
        }
    }
}

void CreateWorld(int cave[])
{
    int i;
    int *room;

    /* Initialize cave to empty */
    for (i = 0; i < ArraySize; i++)
    {
        cave[i] = Empty;
    }

    cave[0] = End;
    cave[ArraySize - 1] = End;
    /* Get a random empty room and put the Wumpus in it */
    room = GetEmptyRoom(cave);
    *room = Wumpus;
}

int *GetEmptyRoom(int cave[])
{
    int room;

    do
    {
        room = rand() % ArraySize;
    } while (cave[room] != Empty);

    return &cave[room];
}

void DisplayWorld(int cave[], int *agent, int agentDir)
{
    int *room;
    for (room = cave + 1; *room != End; room++)
    {
        if (room == agent)
        {
            switch (agentDir)
            {
            case Left:
                printf("<A  ");
                break;

            case Right:
                printf(" A> ");
            }

            continue;
        }
        switch (*room)
        {
        case Wumpus:
            printf("-W- ");
            break;
        default:
            printf(" .  ");
            break;
        }
    }
    printf("\n");
}

int DifferenceByDirection(int dir)
{
    if (dir == Left)
        return -1;
    else
        return 1;
}

bool DisplayStatus(int cave[], int *agent)
{
    if (isWin)
    {
        printf("You have Win\n");
        return true;
    }

    if (*agent == Wumpus)
    {
        printf("You have been eaten by the Wumpus\n");
        return true;
    }

    if (*(agent - 1) == Wumpus || *(agent + 1) == Wumpus)
    {
        printf("I smell a Wumpus\n");
    }

    /* We will return true to indicate we are dead! */
    return false;
}

void Fire(int *agent, int agentDir)
{
    int *room = agent;
    int i;
    int dir = DifferenceByDirection(agentDir);
    for (i = 0; i < 3 && *room != End; i++)
    {
        room += dir;
        if (*room == Wumpus)
        {
            *room = Empty;
            isWin = true;
        }
    }
}