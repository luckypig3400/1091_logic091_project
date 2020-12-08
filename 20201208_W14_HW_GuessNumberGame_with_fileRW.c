#include <stdio.h>  // printf, scanf,puts,NULL
#include <stdlib.h> // srand,rand
#include <time.h>   //time

int main()
{

    //TODO:開啟檔案，若無檔案則建立檔案，檔案預設值如下:
    //topPlayerName=預設第一名玩家
    //topPlayerGuessCount=66

    int secretNumber, userInput, guessCount = 0;

    srand(time(NULL)); //用時間將亂數表先打亂

    secretNumber = rand() % 100 + 1; //用rand()取1~100的亂數

    printf("來玩猜數字(1~100):");
    scanf("%d", &userInput);
    while (userInput != secretNumber)
    {
        guessCount++;
        if (userInput > secretNumber)
            printf("太大囉\n");
        else
            printf("太小囉\n");
        printf("已經猜了%d次\n", guessCount);
        printf("===========================\n");
        printf("請繼續猜(1~100):");
        scanf("%d", &userInput);
    }

    guessCount += 1; //猜對的那次也要加進去
    printf("恭喜猜對! 共猜了%d次", guessCount);

    //TODO:如果此局猜數字次數比檔案中的還要好
    //(打破歷史紀錄)

    return 0;
}