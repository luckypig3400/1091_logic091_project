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
    char lastInputOperator = '\0';
    char alreadyInputFirstOperator = 'n';

    printf("請輸入一四則運算式:");

    for (int i = 0; i < arraySize; i++)
        inputArray[i] = '\0'; //inital char Array

    inputChar = getche();
    while (inputChar != '=' && inputCount != arraySize)
    {

        inputNum = inputChar - '0';
        if (alreadyInputFirstOperator == 'n') //第一次輸入，尚未輸入任何運算子
            result = result * 10 + inputNum;
        else
            caculateCache = caculateCache * 10 + inputNum; //直接乘10就可以處理多位數問題了 by 鑫哥

        if (inputChar == '+' || inputChar == '-' || inputChar == '*' || inputChar == '/')
        {
            alreadyInputFirstOperator = 'y';
            lastInputOperator = inputChar;
        }
        inputCount += 1;
        inputChar = getche();
    }

    switch (lastInputOperator)
    {
    case '+':
        result += caculateCache;
        break;
    case '-':
        result -= caculateCache;
        break;
    case '*':
        result *= caculateCache;
        break;
    case '/':
        result /= caculateCache;
        break;
    default:
        break;
    }

    printf("\nlastInputOperator:%c", lastInputOperator);
    printf("\nfinal result:%d", result);
    printf("\nlast caculateCache:%d", caculateCache);

    return 0;
}