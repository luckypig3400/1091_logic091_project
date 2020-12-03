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
    printf("總和為%d", totalDiceNumber);

    return 0;
}