#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

/* 
 * Simple lunar lander program.
 * By:  XmchxCoder
 * Best landing: Time = 15 seconds, Fuel = 85.0, Velocity = -1.95
 */

void debugInformation(double altitude, double velocity, double fuel)
{
    printf("Altitude: %.2f\n", altitude);
    printf("Velocity: %.2f\n", velocity);
    printf("You have %.1f kilograms of fuel\n", fuel);
}

int main()
{
    double altitude = 100; /* Meters */
    double velocity = 0;   /* Meters per second */
    double fuel = 100;     /* Kilograms */
    double power = 1.5;    /* Acceleration per pound of fuel */
    double g = -1.63;      /* Moon gravity in m/s^2 */
    double burn;           /* Amount of fuel to burn */
    bool valid;            /* Valid data entry flag */
    int times = 0;

    printf("Lunar Lander - (c) 2021, by XmchxCoder\n");

    while (altitude > 0)
    {

        times++;
        printf("------------------------------------\n");
        printf("Current time is %ds\n", times);
        printf("Altitude: %.2f\n", altitude);
        printf("Velocity: %.2f\n", velocity);
        printf("You have %.1f kilograms of fuel\n", fuel);
        do
        {
            valid = false;

            printf("How much fuel would you like to burn: ");
            scanf("%lf", &burn);

            if (burn < 0)
            {
                printf("You can't burn negative fuel\n");
            }
            else if (burn > 5)
            {
                printf("You can't burnning more than 5 kilograms per second\n");
            }
            else if (burn > fuel)
            {
                printf("You can't burn fuel you don't have\n");
            }
            else
            {
                valid = true;
                printf("Burning %.1f kilograms of fuel\n", burn);
            }
        } while (!valid);

        velocity = velocity + g + power * burn;
        altitude += velocity;
        fuel -= burn;
    }

    printf("------------------------------------\n");
    printf("You landed with a velocity of %.2f\n", velocity);
    printf("You remaining fuel is %.1f\n", fuel);

    if (fabs(velocity) > 3)
    {
        printf("Your next of kin have been notified\n");
        exit(0);
    }

    printf("Congratulations! Your have landed safely\n");
}