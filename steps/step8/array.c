#include <stdio.h>

#define NumMovies 10
#define MaxGrosses 5

int main()
{
    double gross[NumMovies] = {4633070, 3856195, 3171189, 1877685, 3251622,
                               3156594, 1629735, 2659234, 2028036, 510768};
    char *names[NumMovies] = {"Hall Pass", "Unknown", "I Am Number Four", "The King's Speech",
                              "Just Go With It", "Gnomeo and Juliet", "Drive Angry",
                              "Justin Beiber: Never Say Never", "Big Mommas: Like Father, Like Son",
                              "True Grit"};
    double sum;
    int i, j;
    int highestGrossIndex = 0;
    double highestGross = 0;
    double maxGross[MaxGrosses] = {500000, 1000000, 2000000, 4000000, 10000000};
    double tmpHighestGross;
    int tmpHighestGrossIndex;

    for (i = 0; i < NumMovies; i++)
    {
        if (gross[i] > highestGross)
        {
            highestGrossIndex = i;
            highestGross = gross[highestGrossIndex];
        }
        printf("Movie %2d %33s: %.0f\n", i + 1, names[i], gross[i]);
    }
    printf("The highest grossing film is: %s\n", names[highestGrossIndex]);

    for (i = 0; i < MaxGrosses; i++)
    {
        tmpHighestGross = -1;
        tmpHighestGrossIndex = -1;
        for (j = 0; j < NumMovies; j++)
        {
            if (gross[j] < maxGross[i])
            {
                if (tmpHighestGrossIndex == -1 || tmpHighestGross < gross[j])
                {
                    tmpHighestGrossIndex = j;
                    tmpHighestGross = gross[tmpHighestGrossIndex];
                }
            }
        }
        if (tmpHighestGrossIndex == -1)
        {
            printf("No film made less than %.0f\n", maxGross[i]);
        }
        else
        {
            printf("The highest gross less than %.0f is %s at %0.f\n", maxGross[i], names[tmpHighestGrossIndex], tmpHighestGross);
        }
    }

    // sum = gross[0] + gross[1] + gross[2] + gross[3] + gross[4];
    sum = 0;
    for (i = 0; i < NumMovies; i++)
    {
        sum += gross[i];
    }
    printf("Total gross for these films was $%.0f\n", sum);
}