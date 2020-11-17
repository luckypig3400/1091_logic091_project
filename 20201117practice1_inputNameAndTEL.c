#include <stdio.h>
#include <string.h>

int main()
{

    char name[5][64];
    char phone[5][64];
    char inputCache[64];
    char continueInput[3];

    // 假設宣告name[3][6]則:
    // 0 1 2 3 4 5
    // □ □ □ □ □ □ name[0][]
    // □ □ □ □ □ □ name[1][]
    // □ □ □ □ □ □ name[2][]

    // □ □ □ □ □ □ inputCache
    // gets()獲取字串 可以把輸入的字串轉存到字元陣列內(包含空白)

    // 使用strcpy(name[0],inputCache)
    // 可以把inputCache字串(或者說是inputCache的每個字元) 複製到 name[0]

    int inputCount = 0;

    while (inputCount < 5)
    { //不可超過字元陣列範圍
        printf("請輸入姓名：");
        gets(inputCache);
        strcpy(name[inputCount], inputCache); //複製string

        printf("請輸入電話：");
        gets(inputCache);
        strcpy(phone[inputCount], inputCache); //複製string

        printf("%s\t", name[inputCount]);
        printf("%s\n", phone[inputCount]);

        printf("是否繼續輸入(y/n):");
        gets(continueInput);
        if(continueInput[0] == 'n' || continueInput[0] == 'N') break;
        // else do nothing(默認繼續輸入)
        printf("===========================\n");

        inputCount++;
    }

    

    return 0;
}