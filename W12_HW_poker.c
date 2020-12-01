#include <stdio.h>

int main()
{

    int originalPoker[52];
    int randomPoker[52];
    for (int i = 0; i < 52; i++) //產生原始順序的撲克牌
    {
        originalPoker[i] = i + 1;
        //1 ~ 52
    }

    for (int i = 0; i < 52; i++) //產生打亂順序的撲克牌
    {
        int j = rand() % 52;
        int swap = randomPoker[i];
        randomPoker[i] = randomPoker[j];
        randomPoker[j] = swap;
    }

    for (int i = 0; i < 52; i++) //輸出原始撲克牌
    {
        if (i % 13 == 0 && i != 0)
            printf("\n"); //每13張分一組
        if (originalPoker[i] <= 13)
        {
            printf("♠%d ", originalPoker[i]);
        }
        else if (originalPoker[i] <= 26)
        {
            if (originalPoker[i] % 13 == 0)
                printf("♥%d ", 13);
            else
                printf("♥%d ", originalPoker[i] % 13);
        }
        else if (originalPoker[i] <= 39)
        {
            if (originalPoker[i] % 13 == 0)
                printf("♦%d ", 13);
            else
                printf("♦%d ", originalPoker[i] % 13);
        }
        else if (originalPoker[i] <= 52)
        {
            if (originalPoker[i] % 13 == 0)
                printf("♣%d ", 13);
            else
                printf("♣%d ", originalPoker[i] % 13);
        }
    }

    //printf("♠ ♥ ♦ ♣\n");

    return 0;
}