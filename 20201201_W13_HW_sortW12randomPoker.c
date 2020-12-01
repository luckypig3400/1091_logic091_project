#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void outputPoker(int []);

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
        sortedPoker[i] = -1;//initalize sortedPoker
    }

    srand(time(NULL));
    for (int i = 0; i < 52; i++) //產生打亂順序的撲克牌
    {
        int j = rand() % 52;
        int swap = randomPoker[i];
        randomPoker[i] = randomPoker[j];
        randomPoker[j] = swap;
    }

    printf("\n打亂順序的撲克牌:\n");
    outputPoker(randomPoker);

    // TODO 排序打亂的撲克牌

    printf("\n排序後的撲克牌:\n");
    outputPoker(sortedPoker);

    return 0;
}

void outputPoker(int in_Poker[]){
    for (int i = 0; i < 52; i++) //輸出原始撲克牌
    {
        if (i % 13 == 0 && i != 0)
            printf("\n"); //每13張分一組
        if (in_Poker[i] <= 13)
        {
            printf("♠%d ", in_Poker[i]);
        }
        else if (in_Poker[i] <= 26)
        {
            if (in_Poker[i] % 13 == 0)
                printf("♥%d ", 13);
            else
                printf("♥%d ", in_Poker[i] % 13);
        }
        else if (in_Poker[i] <= 39)
        {
            if (in_Poker[i] % 13 == 0)
                printf("♦%d ", 13);
            else
                printf("♦%d ", in_Poker[i] % 13);
        }
        else if (in_Poker[i] <= 52)
        {
            if (in_Poker[i] % 13 == 0)
                printf("♣%d ", 13);
            else
                printf("♣%d ", in_Poker[i] % 13);
        }
    }
}