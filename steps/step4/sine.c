#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    double radian, degree;
    int numSteps = 40;
    double maxAngle = M_PI * 2;
    double sinVal, prevSinVal = -1;
    int i = 0;
    int j = 0;
    int numSpaces = 0, zeroPosition = 30; // 值为0的位置

    do
    {
        printf("Input the number of steps: ");
        scanf("%d", &numSteps);
    } while (numSteps < 2);

    // table head
    printf("\tradian\tdegree\tsin(r)\n");

    for (i = 0; i <= numSteps; i++)
    {
        radian = (double)i / (double)numSteps * maxAngle;
        degree = (double)(radian * 180 / M_PI);
        sinVal = sin(radian);

        // table content
        printf("%3d: \t%5.2f \t%5.2f \t%6.3f", i, radian, degree, sinVal);
        // sin function
        numSpaces = zeroPosition + sinVal * zeroPosition; // 将sinVal转换成对应的位置
        for (j = 0; j < numSpaces; j++)
        {
            printf(" ");
        }

        if (fabs(cos(radian)) < 0.1)
        {
            printf("*\n");
        }
        else if (sinVal > prevSinVal)
        {
            printf("\\\n");
        }
        else if (sinVal < prevSinVal)
        {
            printf("/\n");
        }

        prevSinVal = sinVal;
    }
}