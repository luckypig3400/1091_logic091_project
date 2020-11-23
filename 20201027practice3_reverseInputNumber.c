#include <stdio.h>

int main()
{

    int userInput;
    printf("【數字反向器】\n");
    printf("將會把輸入的數字反向 EX:123 變成 321\n");
    printf("請輸入整數:");
    scanf("%d", &userInput);
    //方法一:取餘數(%10)後輸出，然後除以十，直到結束
    while (userInput != 0)
    {
        printf("%d", (userInput%10));
        userInput = userInput / 10;
    }
    //方法二:使用字元陣列分別儲存，反向輸出陣列

    return 0;
}