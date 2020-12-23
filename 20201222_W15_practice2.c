#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *file1;
char fileName[60] = ".\\bin\\user.dat";

int main()
{

    file1 = fopen(fileName, "r");

    if (file1 == NULL)
    {
        printf("無法開啟檔案 檔案損毀或不存在 將離開系統...");
        return -1;
    }

    else
    {
        char tempStr[64];
        char userAccount[100][32];
        char userPWD[100][32];
        memset(userAccount, '\0', 3200); //要先把變數的記憶體全部清空才不會出現亂碼
        memset(userPWD, '\0', 3200);
        int i = 0;
        while (fgets(tempStr, 64, file1) != NULL)
        {
            for (int j = 0; j < 5; j++)
            { // tempStr[5]為\t 不複製
                userAccount[i][j] = tempStr[j];
            }// 其實這樣寫不太好，因為這樣只能讀取符合標準格式與長度的帳號與密碼
            for (int j = 0; j < 8; j++)
            { // 密碼為8個字元從tempStr[6]開始
                userPWD[i][j] = tempStr[6 + j];
            }
            printf("%s\t%s\n", userAccount[i], userPWD[i]);
            i += 1;
        }

        printf("成功讀取檔案\n");

        return 0;
    }
}