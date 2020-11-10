#include <stdio.h>

int main()
{

    int userInput = 0;
    printf("正因數分析，請輸入一個數字:");
    scanf("%d", &userInput);
    printf("以下為%d的正因數:\n", userInput);
    for (int i = 1; i <= userInput; i++){
        if (userInput % i == 0){
            printf("%d ",i);
        }
    }

    return 0;
}