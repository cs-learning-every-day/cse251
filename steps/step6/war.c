#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

#define ACE 1

typedef struct _Card
{
    int suit;
    int card;
    char *name;
} Card;

void PrintResult();
void PrintCard();
Card GenerateCard(char *);
int CompareCard(Card, Card);

int main()
{
    srand(time(NULL));
    // char name1[20];
    // char name2[20];

    // printf("Please two hero's name: \n");
    // printf("one Hero's name: ");
    // scanf("%s", name1);

    // printf("the other Hero's name: ");
    // scanf("%s", name2);

    Card player1Card = GenerateCard("西门吹雪");
    Card player2Card = GenerateCard("Joker");

    PrintCard(player1Card);
    PrintCard(player2Card);

    PrintResult(player1Card, player2Card);
    return 0;
}

void PrintResult(Card c1, Card c2)
{
    int cmp = CompareCard(c1, c2);

    if (cmp == 0)
    {
        printf("There is a tie\n");
    }
    else if (cmp < 0)
    {
        printf("Player %s wins\n", c2.name);
    }
    else
    {
        printf("Player %s wins\n", c1.name);
    }
}

Card GenerateCard(char *name)
{
    Card newCard;
    printf("Generate New Card(waitting 1s)\n");
    sleep(1);
    newCard.suit = rand() % 4;
    newCard.card = rand() % 13 + 1;
    newCard.name = name;
    return newCard;
}

/**
 * negative c1 < c2
 * 0  c1 == c2
 * positive  c1 > c2
 */
int CompareCard(Card c1, Card c2)
{
    // A
    if (c1.card == ACE && c2.card != ACE)
    {
        return 1;
    }

    if (c2.card == ACE && c1.card != ACE)
    {
        return -1;
    }

    if (c1.card == c2.card)
    {
        return -(c1.suit - c2.suit);
    }
    else
    {
        return c1.card - c2.card;
    }
}

void PrintCard(Card c)
{
    printf("------------------------------\n");
    printf("Player %s has this card: ", c.name);
    switch (c.card)
    {
    case 1:
        printf("Ace");
        break;

    case 11:
        printf("Jack");
        break;

    case 12:
        printf("Queen");
        break;

    case 13:
        printf("King");
        break;

    default:
        printf("%d", c.card);
        break;
    }

    printf(" of ");

    switch (c.suit)
    {
    case 0:
        printf("Hearts");
        break;

    case 1:
        printf("Diamonds");
        break;

    case 2:
        printf("Spades");
        break;

    case 3:
        printf("Clubs");
        break;
    }
    printf("\n");
}