#include <stdio.h>
#include <string.h>

int main()
{

    int originalPoker[52];
    for (int i = 0; i < 52; i++)
    {
        originalPoker[i] = i + 1;
        //1 ~ 52
    }

    for (int i = 0; i < 52; i++)
    {
        if (originalPoker[i] <= 13)
        {
            printf("♠%d", originalPoker[i]);
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