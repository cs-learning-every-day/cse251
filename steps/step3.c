#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    double annualIncome;
    printf("Enter your annual income: ");
    scanf("%lf", &annualIncome);

    if (annualIncome < 9350)
    {
        printf("0\n");
        exit(0);
    }
    int status;
    printf("What is your filing status?\n");
    printf("1) single\n");
    printf("2) married filing jointly\n");
    printf("3) married filing separately\n");

    printf("Please enter a number: ");
    scanf("%d", &status);

    int dependents = 0;
    int decution = 0;
    switch (status)
    {
    case 1:
    case 3:
        dependents = 1;
        decution = 5700;
        break;
    case 2:
        decution = 11400;
        printf("How many children do you have? ");
        scanf("%d", &dependents);
        dependents += 2;
        break;
    default:
        printf("not valid value!\n");
        exit(1);
    }
    decution += dependents * 3650;
    double result = 0;
    double tmp = annualIncome - decution;
    if (tmp <= 16750)
    {
        result = 0.1 * tmp;
    }
    else if (tmp <= 68000)
    {
        result = 1675 + 0.15 * (tmp - 16750);
    }
    else if (tmp <= 137300)
    {
        result = 9362.50 + 0.25 * (tmp - 68000);
    }
    else
    {
        result = 26687.50 + 0.28 * (tmp - 137300);
    }
    printf("%.2lf\n", result);
}