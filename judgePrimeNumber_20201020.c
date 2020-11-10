#include <stdio.h>

int main()
{

    int userInput;
    printf("======Prime Number Judger======\n");
    printf("Please input an integer(enter 0 to exit):");
    scanf("%d", &userInput);
    while (userInput != 0)
    {

        for (int i = 2; i <= userInput; i++)
        {
            if (userInput % i == 0 && i == userInput)
            {//如果只能被1或自己整除則為質數
                printf("Prime Number\n");
                break;
            }
            else if(userInput % i == 0 && i != userInput)
            {//如果還會被其他數字整除則非質數
                printf("Not prime number\n");
                break;
            }
        }

        printf("Please input an integer(enter 0 to exit):");
        scanf("%d", &userInput);
    }
    return 0;
}
