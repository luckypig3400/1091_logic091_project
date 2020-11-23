#include <stdio.h>

int main()
{

    printf("======type1======\n");
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("======type2======\n");
    for (int i = 5; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("======type3======\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 4; j > i; j--)
        {
            printf(" ");
        }
        for (int k = 0; k < 2 * i + 1; k++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}