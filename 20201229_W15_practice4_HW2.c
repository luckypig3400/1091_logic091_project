#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *file1;
char *fileName = ".\\bin\\search.dat";

int main()
{
    file1 = fopen(fileName, "r");

    if (file1 == NULL)
    {
        printf("檔案錯誤或檔案不存在");
        return -1;
    }
    else
    {
        char searchString[60];
        memset(searchString, '\0', 60);
        printf("請輸入要在文件中搜尋的字串:");
        scanf("%s", &searchString);
        int totalLinesInFileCount = 0, foundSearchStringCount = 0;
        char fileLinesCache[512];
        while (fgets(fileLinesCache, 512, file1) != NULL)
        {
            totalLinesInFileCount += 1;
            // printf("第%d行:%s", totalLinesInFileCount, fileLinesCache);
            if (strstr(fileLinesCache, searchString) != NULL)
            {
                printf("於第%d行找到字串%s，該行完整句子為:\n%s", totalLinesInFileCount, searchString, fileLinesCache);
                foundSearchStringCount += 1;
            }
            if (foundSearchStringCount >= 3)
            {
                printf("已達最大搜尋數量3行，請付費解鎖無限行搜尋");
                break;
            }
        }

        if (foundSearchStringCount == 0)
            printf("QQ 找不到資料!");

        return 0;
    }
}

// 設計一簡易之搜尋引擎, 判斷關鍵字是否有在檔案(search.dat)中出現
// 若有, 則顯示出該行內容，最多顯示3列字串
// 若無, 則顯示「找不到資料!!」