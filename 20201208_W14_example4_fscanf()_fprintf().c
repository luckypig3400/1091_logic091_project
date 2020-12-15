/* 檔名:ch11_04.c 功能:複製檔案(使用fscanf與fprintf) */

#include <stdlib.h>
#include <stdio.h>

FILE *fp1, *fp2;

void main(void)
{
    char filename1[80], filename2[80];
    char tempstr[32];

    printf("請輸入來源檔名:");
    scanf("%s", filename1);
    printf("請輸入目的檔名:");
    scanf("%s", filename2);

    fp1 = fopen(filename1, "r");
    fp2 = fopen(filename2, "w");

    if ((fp1 == NULL) || (fp2 == NULL))
    {
        printf("檔案發生錯誤\n");
        exit(1); /* 強迫結束程式 */
    }
    
    printf("讀取並寫入中......\n");
    
    while ((fscanf(fp1, "%s", tempstr)) != EOF) /* 使用迴圈讀取來源檔內容 */
    {
        /* printf("%s\n",tempstr); */
        fprintf(fp2, "%s\n", tempstr); /* 使用迴圈寫入目的檔內容 */
    }
    printf("讀取並寫入完畢......\n");
    
    fclose(fp1);
    fclose(fp2);
    /* system("pause"); */
}

//第29~33行：使用迴圈讀取fp1檔案串流中的字串，並將之寫入到fp2檔案串
//流中。由於fscanf和scanf一樣，遇到空白就會停止讀取，所以我們在寫入時，
//若加上換行符號，就可以清楚看出迴圈每次使用fscanf讀出的字串為何。