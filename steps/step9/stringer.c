#include <stdio.h>
#include <string.h>
/* 
 * Name : XmchxCoder
 * Program to experiment with strings
 */

int StringLength(char str[])
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

void PrintLength(char str[])
{
    printf("The string %s is %ld characters long\n", str, strlen(str));
}

// 清除stdin里的缓冲 防止下次读入垃圾
void CleanStdin()
{
    int c;
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void Reverse(char str[])
{
    int front = 0;
    int back = strlen(str) - 1;
    char t;

    while (front < back)
    {
        t = str[front];
        str[front] = str[back];
        str[back] = t;
        front++;
        back--;
    }
}

int NumberOfSpaces(char str[])
{
    int numSpaces = 0;
    int i = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            numSpaces++;
        }
    }
    return numSpaces;
}

int NumberOfAppearances(char str[], char ch)
{
    int nums = 0;
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ch)
        {
            nums++;
        }
    }
    return nums;
}

int main()
{
    char word[] = "chudge";
    char myWord[80];
    char mySentence[80];
    int i;
    int len;

    printf("Enter a word: ");
    scanf("%79s", myWord);
    myWord[79] = '\0';
    printf("The entered word is: %s\n", myWord);

    CleanStdin();
    printf("Enter a sentence: ");
    // fflush(stdin); // linux下没有实现stdin 清除前面打开的标准输入内容

    fgets(mySentence, 80, stdin);

    len = strlen(mySentence);
    mySentence[len - 1] = '\0';
    printf("The entered sentence is: %s\n", mySentence);

    Reverse(mySentence);
    printf("Reverse sentece is: %s\n", mySentence);

    printf("The number of spaces is: %d\n", NumberOfSpaces(mySentence));
    printf("The number of t is: %d\n", NumberOfAppearances(mySentence, 't'));

    PrintLength(word);
    PrintLength(myWord);
    PrintLength(mySentence);
}