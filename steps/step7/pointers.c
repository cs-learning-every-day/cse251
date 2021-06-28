#include <stdio.h>

int main()
{
    int a = 0;
    int b = 5;
    int c = 0x2251;

    printf("%lx\n", (long int)&a);
    printf("%x\n", b);
    printf("%x\n", c);

    int *pA = &a;
    int *pB = &b;
    int *p;
    printf("a=%d, pA=0x%lx, *pA=%d\n", a, (long int)pA, *pA);
    a = 47;
    printf("a=%d, pA=0x%lx, *pA=%d\n", a, (long int)pA, *pA);
    *pA = 99;
    printf("a=%d, pA=0x%lx, *pA=%d\n", a, (long int)pA, *pA);

    printf("Next experiment:\n");
    p = pA;
    *p = 22; // a=22
    p = pB;
    *p = 18; // b=18
    p = &b;
    *p = 108; // b=108
    p = pA;
    *p = 2; // a=2
    printf("a=%d, pA=%lx, *pA=%d\n", a, (long int)pA, *pA);
    printf("b=%d, pB=%lx, *pB=%d\n", b, (long int)pB, *pB);
    printf("p=%lx, *p=%d\n", (long int)p, *p);
}