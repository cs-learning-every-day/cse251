#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void InputQuardaticEquation(double *a, double *b, double *c)
{
    printf("Input a: ");
    scanf("%lf", a);
    printf("Input b: ");
    scanf("%lf", b);
    printf("Input c: ");
    scanf("%lf", c);
}

void QuadraticEquation(double a, double b, double c,
                       double *pZ1r, double *pZ1i, double *pZ2r, double *pZ2i)
{
    double discriminant;
    /*
     * This code computes the quadratic equation
     * for both real and complex zeros 
     */
    /* Compute the discriminant */
    discriminant = b * b - 4 * a * c;
    if (discriminant >= 0)
    {
        /* If the discriminant is greater than or
           equal to zero, the zeros are real */
        *pZ1r = (-b + sqrt(discriminant)) / (2 * a);
        *pZ2r = (-b - sqrt(discriminant)) / (2 * a);
        *pZ1i = 0;
        *pZ2i = 0;
    }
    else
    {
        /* If the discriminant is less than zero
           the zeros are complex  */
        *pZ1r = -b / (2 * a);
        *pZ2r = *pZ1r;
        *pZ1i = sqrt(-discriminant) / (2 * a);
        *pZ2i = -sqrt(-discriminant) / (2 * a);
    }
}

int main()
{
    /* Values for the quadratic formula */
    double a, b, c;
    double z1r, z1i; /* First zero */
    double z2r, z2i; /* Second zero */

    InputQuardaticEquation(&a, &b, &c);

    QuadraticEquation(a, b, c, &z1r, &z1i, &z2r, &z2i);

    /* Display the results */
    printf("Zero 1: %f + %fi\n", z1r, z1i);
    printf("Zero 2: %f + %fi\n", z2r, z2i);
}