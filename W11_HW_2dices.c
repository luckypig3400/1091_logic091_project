#include <stdio.h>  // printf, scanf, puts, NULL
#include <stdlib.h> //srand, rand
#include <time.h>   // time

int main()
{

    int randomNumber;

    //initialize random seed
    srand(time(NULL)); //用時間將亂數表先打亂

    //generate random number between 1 to 6
    randomNumber = rand() % 6 + 1;

    printf("%d", randomNumber);

    return 0;
}