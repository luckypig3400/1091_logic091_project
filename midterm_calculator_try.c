#include <stdio.h>
#include <string.h>

int main()
{

    char inputArray[16];
    int inputCount = 0;
    int arraySize = 16;
    char inputChar;
    int inputNum = 0;
    int result = 0;
    int caculateCache = 0;

    printf("請輸入一四則運算式:");

    for (int i = 0; i < arraySize; i++)
        inputArray[i] = '\0'; //inital char Array

    inputChar = getche();
    while (inputChar != '=' && inputCount != arraySize)
    {
        switch (inputChar)
        {
        case '+':
            result += caculateCache;
            caculateCache = 0;
            break;
        case '-':
            result -= caculateCache;
            caculateCache = 0;
            break;
        case '*':
            result *= caculateCache;
            caculateCache = 0;
            break;
        case '/':
            result /= caculateCache;
            caculateCache = 0;
            break;
        default:
            inputNum = inputChar - '0';
            caculateCache = caculateCache * 10  + inputNum;//直接乘10就可以處理多位數問題了 by 鑫哥
            break;
        }
        inputCount += 1;
        inputChar = getche();
    }

    printf("%d", result);

    return 0;
}