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
    char topPlayerName[128] = "預設第一名玩家";
    char topPlayerGuessCount[2] = "66";
    int bestRecord = 66;
    char fileContext[256] = "";
    char filename[60] = "20201208_W14_HW_GuessNumberGame_with_fileRW.txt";
    char tempstr[32];

    file1 = fopen(filename, "r"); //讀取歷史檔案僅採用讀取模式(可以測試檔案是否存在)

    if ((file1 == NULL))
    {
        printf("檔案發生錯誤(初次執行程式或是檔案毀損)\n");
        file1 = fopen(filename, "w");
        printf("建立預設檔案中...");
        char writeCahce[256] = "";
        strcat(writeCahce, "topPlayerGuessCount=");
        strcat(writeCahce, topPlayerGuessCount);
        strcat(writeCahce, "\ntopPlayerName=");
        strcat(writeCahce, topPlayerName);
        fputs(writeCahce, file1);
        fclose(file1); //寫完檔案關閉以存檔
    }

    while (fgets(tempstr, 32, file1) != NULL) /* 使用迴圈讀取完整來源檔內容 */
    {
        strcat(fileContext, tempstr); //連接字串
        // Use strcat to concatenate two strings
        // https://stackoverflow.com/questions/8465006/how-do-i-concatenate-two-strings-in-c
    }
    fclose(file1); //讀完檔案關閉

    if (fileContext[19] == '=' && fileContext[36] == '=') //檢查檔案正確性並存放最高分數
    {
        printf("目前的存檔內容為:\n%s\n", fileContext);

        //自行規定儲存最高紀錄的數據只能有兩位數
        topPlayerGuessCount[0] = fileContext[20];
        topPlayerGuessCount[1] = fileContext[21];

        int nameCharCount = 0, i = 37;
        while (fileContext[i] != '\0')
        {
            topPlayerName[nameCharCount] = fileContext[i];
            printf("%d", i);
            nameCharCount += 1;
            i += 1;
        }
    }
    else
    {
        printf("存檔錯誤，將重建紀錄檔案");
    }

    printf("抓出來的變數值如下:\n");
    printf("topPlayerGuessCount:%c%c\n", topPlayerGuessCount[0], topPlayerGuessCount[1]);
    printf("topPlayerName:%s\n", topPlayerName);

    bestRecord = (int)(topPlayerGuessCount[0] - '0') * 10 + (int)(topPlayerGuessCount[1] - '0');
    //把從檔案讀到的最高分轉成int儲存
    printf("bestRecord in deciaml:%d\n", bestRecord);

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
    printf("恭喜猜對! 共猜了%d次\n", guessCount);

    if (guessCount < bestRecord) //如果此局猜數字次數比檔案中的還要好寫入存檔
    {
        printf("太厲害了!!!恭喜您破了%s的歷史紀錄%d次!\n", topPlayerName, bestRecord);
        bestRecord = guessCount;
        if (bestRecord < 10)
        {
            topPlayerGuessCount[0] = '0';
            topPlayerGuessCount[1] = (char)(bestRecord + (int)'0');
            printf("bestRecord in char array:%c%c\n", topPlayerGuessCount[0], topPlayerGuessCount[1]);
        }
        else
        {
            topPlayerGuessCount[0] = (char)((bestRecord / 10) + (int)'0');
            topPlayerGuessCount[1] = (char)((bestRecord % 10) + (int)'0');
            printf("bestRecord in char array:%c%c\n", topPlayerGuessCount[0], topPlayerGuessCount[1]);
        }
    }

    system("pause");

    return 0;
}