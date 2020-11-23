#include <stdio.h>

int main()
{

    int inputCount = 0, userInput, sum = 0, min = 999999, max = 0;
    printf("【最大值最小值與平均數計算機】\n");
    printf("請不斷地輸入整數，將會自動找出其最大與最小值並計算出平均值(輸入0結束)\n");
    printf("請輸入第%d個數:", inputCount+1);
    scanf("%d", &userInput);
    while (userInput != 0)
    {
        sum += userInput;
        if (userInput > max)
        {
            max = userInput;
        }
        if (userInput < min)
        {
            min = userInput;
        }

        inputCount += 1;
        printf("請輸入第%d個數:", inputCount+1);
        scanf("%d", &userInput);
    }

    float average = (float)sum / inputCount;

    printf("共輸入了%d個數\n最大值為:%d\t最小值為:%d\t平均值為:%.2f", inputCount, max, min, average);
	//%.0f代表輸出的數顯示0位小數點
	//%.1f代表輸出的數顯示1位小數點
    //%.2f代表輸出的數顯示2位小數點 以此類推...
    return 0;
}