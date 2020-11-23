#include <stdio.h>  // printf, scanf,puts,NULL
#include <stdlib.h> // srand,rand
#include <time.h>   //time

int main()
{
    int secretNumber, userInput, guessCount = 1;

    srand(time(NULL)); //用時間將亂數表先打亂

    secretNumber = rand() % 100 + 1; //用rand()取1~100的亂數

    printf("來玩猜數字(1~100):");
    scanf("%d", &userInput);
    while (userInput != secretNumber)
    {
        printf("===========================\n");
        guessCount++;
        if (userInput > secretNumber)
            printf("太大囉\n");
        else
            printf("太小囉\n");
        printf("第%d猜\n", guessCount);
        printf("來玩猜數字(1~100):");
        scanf("%d", &userInput);
    }

    printf("恭喜猜對!");

    return 0;
}