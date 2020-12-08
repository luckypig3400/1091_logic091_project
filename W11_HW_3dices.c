#include <stdio.h>  // printf, scanf, puts, NULL
#include <stdlib.h> //srand, rand
#include <time.h>   // time

int randomNumber, totalDiceNumber = 0;
int dice[3];
void tossDice();
void sortDice();

int main()
{

    char in_char = 'r';
    while (1 == 1)
    {
        if (in_char == 'r' || in_char == 'R')
        {
            tossDice();
            sortDice();
            //TODO:判斷其點數。其基本規則
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

void sortDice()
{
    //printf("dice.len=%d", sizeof(dice) / sizeof(dice[0]));
    //https://stackoverflow.com/questions/37538/how-do-i-determine-the-size-of-my-array-in-c
    int arrayLen = sizeof(dice) / sizeof(dice[0]);
    for (int i = 0; i < arrayLen; i++)
    {
        for (int j = 0; j < arrayLen-1; j++)
        {
            int swap = 0;
            if (dice[j] > dice[j + 1])
            {
                swap = dice[j + 1];
                dice[j + 1] = dice[j];
                dice[j] = swap;
            }
        }
    }
    printf("排序後的骰子點數為:");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", dice[i]);
    }
    printf("\n=========================\n");
}
