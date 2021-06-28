#include <stdio.h>
#include <math.h>

/*
 * Name : XmchxCoder
 * 
 * This is my first CSE 251 C program!!!
 */

int main()
{
    double radius = 7.88;
    double height = 12.231;
    printf("The cylinder has a radius of %f and a height of %f\n", radius, height);

    int wins = 11;
    int losses = 2;
    printf("MSU had an %d-%d season in 2010!\n", wins, losses);

    double volume, diameter, hypot;
    int games;

    volume = radius * radius * M_PI * height;
    games = wins + losses;
    double near = 10;
    double far = 22.5;

    hypot = sqrt(near * near + far * far);

    double bottleVolume = 1700; /* Milliliters */
    double cupVolume = 350;     /* Milliliters */
    int numCups;

    numCups = bottleVolume / cupVolume;
    printf("Number of cups: %d\n", numCups);

    double l;     /* Inductance in millihenrys */
    double c;     /* Caacitance in microfarads */
    double omega; /* Resonance frequency in radians per second */
    double f;     /* Resonance frequency in Hertz */

    printf("Enter the inductance in millihenrys: ");
    scanf("%lf", &l);

    printf("Enter the capacitance in microfarads: ");
    scanf("%lf", &c);

    omega = 1.0 / sqrt((l / 1000) * (c / 1000000));
    f = omega / (2 * M_PI);
    printf("Resonant frequency: %.2f\n", f);
}
