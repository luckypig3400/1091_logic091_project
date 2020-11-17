#include <stdio.h>
#include <string.h>

int main()
{

    char name[5][64];
    char phone[5][64];
    char inputCache[64];

    int inputCount = 0;

    while (inputCount < 5)
    { //不可超過字元陣列範圍
        printf("請輸入姓名：");
        gets(inputCache);
        printf("%s\n",inputCache);//debug
        strcpy(name[inputCount], inputCache);//複製string

        printf("請輸入電話：");
        gets(inputCache);
        printf("%s\n",inputCache);//debug
        strcpy(phone[inputCount], inputCache);//複製string

        printf("%s\t", name[inputCount]);
        printf("%s\n", phone[inputCount]);

        inputCount++;
    }

    return 0;
}