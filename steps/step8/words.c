#include <stdio.h>
#include <string.h>

/* 
 * Name : XmchxCoder
 * Program to experiment with character arrays
 */

#define MaxWord 20

int main()
{
    char c;
    char str[MaxWord + 1];
    int len = 0;
    int totalWordLen = 0;
    int totalWordCount = 0;
    double avgWordLen = 0.0;
    char highestWord[MaxWord];
    int highestWordLen = 0;

    puts("Enter text. Include a dot ('.') to end a sentence to exit:");
    do
    {
        c = getchar();
        if (c != ' ' && c != '.')
        {
            if (len < MaxWord)
            {
                str[len] = c;
                len++;
            }
        }
        else
        {
            str[len] = 0;
            if (len == 0)
                continue;
            if (len > highestWordLen)
            {
                strcpy(highestWord, str);
                highestWordLen = len;
            }
            totalWordCount++;
            totalWordLen += len;
            printf("%s\n", str);
            len = 0;
        }
    } while (c != '.');

    avgWordLen = totalWordLen = totalWordCount;
    printf("平均单词长度: %.1lf\n", avgWordLen);
    printf("最长单词: %s\n", highestWord);
}