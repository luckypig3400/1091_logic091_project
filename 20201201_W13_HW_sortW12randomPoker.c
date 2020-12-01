#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void outputPoker(int[]);

int main()
{

    int originalPoker[52];
    int randomPoker[52];
    int sortedPoker[52];
    for (int i = 0; i < 52; i++) //產生原始順序的撲克牌
    {
        originalPoker[i] = i + 1;
        randomPoker[i] = i + 1;
        //1 ~ 52
        sortedPoker[i] = -1; //initalize sortedPoker
    }

    srand(time(NULL));
    for (int i = 0; i < 52; i++) //產生打亂順序的撲克牌
    {
        int j = rand() % 52;
        int swap = randomPoker[i];
        randomPoker[i] = randomPoker[j];
        randomPoker[j] = swap;
    }

    printf("正常順序的撲克牌:\n");
    outputPoker(originalPoker);

    printf("\n打亂順序的撲克牌:\n");
    outputPoker(randomPoker);

    // TODO 排序打亂的撲克牌

    printf("\n排序後的撲克牌:\n");
    outputPoker(sortedPoker);

    return 0;
}

void outputPoker(int in_Poker[])
{
    for (int i = 0; i < 52; i++) //輸出撲克牌
    {
        if (i % 13 == 0 && i != 0)
            printf("\n"); //每13張分一組
        if (in_Poker[i] <= 13)
        {
            switch (in_Poker[i] % 13)
            {
            case 0:
                printf("♠K ");
                break;
            case 1:
                printf("♠A ");
                break;
            case 11:
                printf("♠J ");
                break;
            case 12:
                printf("♠Q ");
                break;
            default:
                printf("♠%d ", in_Poker[i]);
                break;
            }
        }
        else if (in_Poker[i] <= 26)
        {
            switch (in_Poker[i] % 13)
            {
            case 0:
                printf("♥K ");
                break;
            case 1:
                printf("♥A ");
                break;
            case 11:
                printf("♥J ");
                break;
            case 12:
                printf("♥Q ");
                break;
            default:
                printf("♥%d ", in_Poker[i] % 13);
                break;
            }
        }
        else if (in_Poker[i] <= 39)
        {
            switch (in_Poker[i] % 13)
            {
            case 0:
                printf("♦K ");
                break;
            case 1:
                printf("♦A ");
                break;
            case 11:
                printf("♦J ");
                break;
            case 12:
                printf("♦Q ");
                break;
            default:
                printf("♦%d ", in_Poker[i] % 13);
                break;
            }
        }
        else if (in_Poker[i] <= 52)
        {
            switch (in_Poker[i] % 13)
            {
            case 0:
                printf("♣K ");
                break;
            case 1:
                printf("♣A ");
                break;
            case 11:
                printf("♣J ");
                break;
            case 12:
                printf("♣Q ");
                break;
            default:
                printf("♣%d ", in_Poker[i] % 13);
                break;
            }
        }
    }
}