#include <stdio.h>

int main()
{
    int number[100];
    int inputNumberCache;
    int findNumber;
    int inputCount = 0;

    printf("請輸入第%d個數字:", inputCount + 1);
    scanf("%d", &inputNumberCache);
    while (inputNumberCache != -1)
    {
        number[inputCount] = inputNumberCache;
        inputCount += 1;
        printf("請輸入第%d個數字:", inputCount + 1);
        scanf("%d", &inputNumberCache);
    }

    printf("==================\n");
    printf("請輸入欲搜尋的值:");
    scanf("%d", &findNumber);
    printf("==================\n");

    printf("size of number:%d\n",sizeof(number));
    
    int foundInArray = 0;

    for (int i = 0; i <= inputCount; i++)
    {
        if (number[i] == findNumber){
            foundInArray = 1;
            printf("%d為輸入的第%d個整數\n", findNumber, i + 1);
        }
    }

    if(foundInArray == 0) printf("%d不在剛剛輸入的數值之中",findNumber);

    return 0;
}