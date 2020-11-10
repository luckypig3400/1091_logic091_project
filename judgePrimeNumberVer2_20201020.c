#include <stdio.h>

int main()
{

    int userInput;
    printf("======Prime Number Judger Ver2======\n");
    printf("Please input an integer:");
    scanf("%d", &userInput);
    printf("The following numbers are prime numbers which are smaller than %d:\n", userInput);
    for (int number = 2; number <= userInput; number++)
    {

        for (int i = 2; i <= number; i++)
        {
            if (number % i == 0 && i == number)
            { //如果只能被1或自己整除則為質數
                printf("%d ", number);
                break;
            }
            else if (number % i == 0 && i != number)
            { //如果還會被其他數字整除則非質數
                // printf("Not prime number\n");
                //do nothing just break;
                break;
            }
        }
    }
    return 0;
}