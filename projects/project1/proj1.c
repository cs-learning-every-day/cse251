/*
∗ CSE 251 Project 1
∗ By: XmchxCoder
∗
∗ Complete the following table:
∗
∗ a     b   n       estimate
∗ −1    1   1883    1.178979838
∗ 0     10
∗ −1000 1000
∗ 10    15
∗ 0.1   0.2
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 100001
#define DECREASE_ERROR (pow(10, -10))
#define FUNC(x) (sin(M_PI * x) / (M_PI * x))

void InputAB(double *a, double *b)
{
    printf("Input a:");
    scanf("%lf", a);
    printf("Input b:");
    scanf("%lf", b);
}

double compute(double delta, int n, double a, double b)
{
    int i;
    double estimate = 0.0, x = 0.0;
    for (i = 1; i <= n; i++)
    {
        x = a + (i - 0.5) * delta;
        if (x == 0)
        {
            estimate += 1 * delta;
        }
        else
        {
            estimate += FUNC(x) * delta;
        }
    }
    return estimate;
}

int main()
{
    double a, b;
    int n = 10, i;
    double estimate = 0, prev_estimate = 0, delta, decrease;
    double x;

    InputAB(&a, &b);
    printf("Integral evaluation:\n");

    delta = (b - a) / n;
    estimate = compute(delta, n, a, b);
    printf("%d: %.9lf\n", n, estimate);
    n++;

    while (n < MAX_N)
    {
        delta = (b - a) / (n * 1.0);
        prev_estimate = estimate;

        estimate = compute(delta, n, a, b);
        decrease = prev_estimate - estimate;

        printf("%d: %.9lf %E\n", n, estimate, decrease);
        if (decrease < DECREASE_ERROR)
        {
            break;
        }
        n++;
    }
    printf("The integral result is %.8lf\n", estimate);

    return EXIT_SUCCESS;
}