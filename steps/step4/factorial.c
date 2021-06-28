#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int num;
    bool valid = true;
    int result = 1;
    printf("Number to compute the factorial of: ");
    scanf("%d", &num);
    if (num < 0)
    {
        valid = false;
    }

    if (valid)
    {

        for (int i = num; i > 1; i--)
        {
            result *= i;
        }
        printf("%d! = %d\n", num, result);
    }

    return 0;
}