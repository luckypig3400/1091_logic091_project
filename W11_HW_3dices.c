#include <stdio.h>  // printf, scanf, puts, NULL
#include <stdlib.h> //srand, rand
#include <time.h>   // time

int main()
{

    int randomNumber, totalDiceNumber = 0;
    int dice[3];
    //initialize random seed
    srand(time(NULL)); //用時間將亂數表先打亂

    //generate random number between 1 to 6
    randomNumber = rand() % 6 + 1;

    printf("骰子點數為:");
    for (int i = 0; i < 3; i++)
    {
        dice[i] = rand() % 6 + 1;
        printf("%d ", dice[i]);
        totalDiceNumber += dice[i];
    }
    printf("\n=========================\n");
    printf("結果為%d", totalDiceNumber);

    //TODO:判斷其點數。其基本規則
    //TODO:由小到大排列
    //TODO:按’r’或’R’可重擲，按’q’或’Q’結束

    return 0;
}