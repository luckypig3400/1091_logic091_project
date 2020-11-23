#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
time delay in C/C++
https://www.geeksforgeeks.org/time-delay-c/
void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
} 
*/

void delay(int number_of_milliSeconds)
{
	// Storing start time
	clock_t start_time = clock();

	// looping till required time is not achieved
	while (clock() < start_time + number_of_milliSeconds)
		;
}

int main()
{
	printf("~來玩猜數字遊戲~\n");
	printf("正在隨機產生1~100的數字中");
	for (int i = 0; i < 6; i++)
	{
		printf(".");
		delay(200);
	}
	printf("\n");
	srand(time(NULL));
	int bingoNumber = (rand() % 100) + 1;
	int guessNumber = 0;
	int guessCount = 0;
	printf("%d", bingoNumber); //debug
	while (guessNumber != bingoNumber)
	{
		printf("請猜數字:");
		scanf("%d", &guessNumber);
		guessCount += 1;
	}
	printf("恭喜猜對! 您共花了%d次猜出BinGo數字!",guessCount);
	return 0;
}
