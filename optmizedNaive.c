#include <stdio.h>
#include <stdbool.h>

void modNaiveStringMatching(const char str[], const char pattern[])
{
    int n = 0;
    int m = 0;
    int flag = 0;
    while (str[n] != '\0')
    {
        if (str[n] == pattern[m])
        {
            n++;
            m++;

            if (pattern[m] == '\0')
            {
                printf("Index : %d\n", n - m);
                flag = 1;
                m = 0;
            }
        }
        else
        {
            if (m == 0)
                n++;
            else
                m = 0;
        }
    }
    if (!flag)
        printf("Pattern not in String\n");
}

int main()
{
    char str[100];
    char pattern[100];

    printf("Enter string: ");
    scanf("%99[^\n]%*c", str);

    printf("Enter pattern: ");
    scanf("%99[^\n]%*c", pattern);

    modNaiveStringMatching(str, pattern);

    return 0;
}
