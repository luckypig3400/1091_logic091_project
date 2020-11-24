#include <stdio.h>
#include <string.h>

int main()
{

    char inputArray[16];
    char input;
    int inputCount = 0;
    int intArray[16];
    int arraySize = 16;
    printf("請輸入一四則運算式:");

    for (int i = 0; i < arraySize; i++)
        inputArray[i] = '\0'; //inital char Array

    do
    {
        input = getche();
        inputArray[inputCount] = input;
        inputCount += 1;
    } while (input != '=' && inputCount != 99);

    for (int i = 0; i < arraySize; i++)
    {
        if (inputArray[i] != '=' || inputArray[i] != '+' || inputArray[i] != '-' || inputArray[i] != '*' || inputArray[i] != '/')
            intArray[i] = inputArray[i] - '0';
        //https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
    }

    printf("\n輸入的運算式為:\n");
    for (int i = 0; i < arraySize; i++)
    {
        if (inputArray[i] != '=')
            printf("str[%d]=%c\t", i, inputArray[i]);
    }

    printf("\n輸入的數字共有以下幾個:\n");
    for (int i = 0; i < arraySize; i++)
    {
        printf("int[%d]=%d\t", i, intArray[i]);
    }

    return 0;
}