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
    char unprocessOperator = '\0';
    char alreadyInputFirstOperator = 'n';

    printf("請輸入一四則運算式:");

    for (int i = 0; i < arraySize; i++)
        inputArray[i] = '\0'; //inital char Array

    inputChar = getche(); //接取輸入字元並顯示出來
    while (inputChar != '=' && inputCount != arraySize)
    {
        if (inputChar == '+' || inputChar == '-' || inputChar == '*' || inputChar == '/')
        {
            if (alreadyInputFirstOperator == 'n')
            { //第一次接到運算符號先不運算
                alreadyInputFirstOperator = 'y';
                unprocessOperator = inputChar;
            }
            else
            {
                switch (unprocessOperator)
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
                    //do nothing
                    break;
                }

                caculateCache = 0;             //finish calculate set cache=0
                unprocessOperator = inputChar; //更新unprocessOperator
            }
        }
        else //輸入非運算子 處理數字位數的部分
        {
            inputNum = inputChar - '0';
            if (alreadyInputFirstOperator == 'n') //第一次輸入，尚未輸入任何運算子
            {
                //直接乘10就可以處理多位數問題了 by 鑫哥
                result = result * 10 + inputNum; //尚未輸入任何運算子，將數字直接儲存到結果
            }
            else
            {
                //直接乘10就可以處理多位數問題了 by 鑫哥
                caculateCache = caculateCache * 10 + inputNum; //已經輸入過運算子，接下來輸入的數字都要等待運算
            }
        }

        inputCount += 1;
        inputChar = getche();
    }

    switch (unprocessOperator) //輸入等於後處理尚未運算的數值
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

    printf("%d", result); //output final result
    // printf("\nunprocessOperator:%c", unprocessOperator); //debug Info
    // printf("\nfinal result:%d", result);                 //debug Info
    // printf("\nlast caculateCache:%d", caculateCache);    //debug Info

    return 0;
}