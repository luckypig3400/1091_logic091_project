#include <stdio.h>  // printf, scanf,puts,NULL
#include <stdlib.h> // srand,rand
#include <time.h>   //time
#include <string.h>

FILE *file1;

int main()
{

    //TODO:開啟檔案，若無檔案則建立檔案，檔案預設值如下:
    //topPlayerName=預設第一名玩家
    //topPlayerGuessCount=66
    int secretNumber, userInput, guessCount = 0;
    char topPlayerName[128];
    char topPlayerGuessCount[3] = "66";
    char fileContext[256] = "";
    char filename[60] = "20201208_W14_HW_GuessNumberGame_with_fileRW.txt";
    char tempstr[32];

    file1 = fopen(filename, "r"); //讀取歷史檔案僅採用讀取模式(可以測試檔案是否存在)

    if ((file1 == NULL))
    {
        printf("檔案發生錯誤(初次執行程式或是檔案毀損)\n");
        file1 = fopen(filename, "w");
        printf("建立預設檔案中...");
        fputs("topPlayerName=預設第一名玩家\n", file1);
        fputs("topPlayerGuessCount=66", file1);
        exit(1); /* 強迫結束程式 */
    }

    while (fgets(tempstr, 32, file1) != NULL) /* 使用迴圈讀取完整來源檔內容 */
    {
        strcat(fileContext, tempstr); //連接字串
        // Use strcat to concatenate two strings
        // https://stackoverflow.com/questions/8465006/how-do-i-concatenate-two-strings-in-c
    }

    printf("%s\n", fileContext);

    if (fileContext[13] == '=')//檢查檔案正確性並存放變數值
    {
        printf("正確的存檔存檔內容為:\n%s\n", fileContext);
        int nameCopyFinished = 0;
        int nameCharCount = 0;
        for (int i = 14; i < 256; i++)
        {
            if (fileContext[i] != '\n' && nameCopyFinished == 0)
            {
                topPlayerName[nameCharCount] = fileContext[i];
                nameCharCount += 1;
            }
            else
            {
                nameCopyFinished = 1;
                printf("get topPlayerName:%s\n", topPlayerName);
                i += 21;                    //直接跳過紀錄最高分變數的=符號
                for (int j = 0; j < 3; j++) //最高分紀錄只取三位數
                {
                    topPlayerGuessCount[j] = fileContext[i];
                    i += 1;
                }
                break;
            }
        }

        printf("topPlayerName:%s\n", topPlayerName);
        printf("topPlayerGuessCount:%s\n",topPlayerGuessCount);
    }

    srand(time(NULL)); //用時間將亂數表先打亂

    secretNumber = rand() % 100 + 1; //用rand()取1~100的亂數

    printf("來玩猜數字(1~100):");
    scanf("%d", &userInput);
    while (userInput != secretNumber)
    {
        guessCount++;
        if (userInput > secretNumber)
            printf("太大囉\n");
        else
            printf("太小囉\n");
        printf("已經猜了%d次\n", guessCount);
        printf("===========================\n");
        printf("請繼續猜(1~100):");
        scanf("%d", &userInput);
    }

    guessCount += 1; //猜對的那次也要加進去
    printf("恭喜猜對! 共猜了%d次", guessCount);

    //TODO:如果此局猜數字次數比檔案中的還要好
    //(打破歷史紀錄)

    system("pause");

    return 0;
}