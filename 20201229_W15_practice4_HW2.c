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
        int totalLinesInFileCount = 0;
        char fileLinesCache[512];
        while (fgets(fileLinesCache, 512, file1) != NULL)
        {
            totalLinesInFileCount += 1;
            printf("第%d行:%s", totalLinesInFileCount, fileLinesCache);
        }

        return 0;
    }
}