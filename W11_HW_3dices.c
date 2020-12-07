#include <stdio.h>  // printf, scanf, puts, NULL
#include <stdlib.h> //srand, rand
#include <time.h>   // time

int randomNumber, totalDiceNumber = 0;
int dice[3];
void tossDice();

int main()
{

    char in_char = 'r';
    while (1 == 1)
    {
        if (in_char == 'r' || in_char == 'R')
        {
            tossDice();
            //TODO:判斷其點數。其基本規則
            //TODO:由小到大排列
        }

        printf("輸入R再投擲一次，或是輸入Q離開:");
        scanf("%c", &in_char);
        if (in_char == 'q' || in_char == 'Q')
            break;
    }

    return 0;
}

void tossDice()
{
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
}