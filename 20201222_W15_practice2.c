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
        char userAccount[101][32];
        char userPWD[101][32];
        memset(userAccount, '\0', 3232); //要先把變數的記憶體全部清空才不會出現亂碼
        memset(userPWD, '\0', 3232);
        int i = 0;
        while (fgets(tempStr, 64, file1) != NULL)
        {
            for (int j = 0; j < 64; j++)
            {
                if (tempStr[j] == '\t')
                    break; // 遇到\t直接跳出迴圈不複製
                userAccount[i][j] = tempStr[j];
            } // 改寫成這樣，可以讀取符合標準格式(有\t與\n)但長度不同的帳號與密碼
            int pwdDetectedLocation = 0;
            for (int j = 0; j < 64; j++)
            { // 密碼為8個字元從tempStr[6]開始
                if (pwdDetectedLocation > 0 && tempStr[j] != '\n')
                    userPWD[i][j - pwdDetectedLocation] = tempStr[j];
                if (tempStr[j] == '\t')
                    pwdDetectedLocation = j + 1; // 遇到\t才開始複製，並記錄碰到\t的下一格字元位置
            }
            // printf("%s\t%s\n", userAccount[i], userPWD[i]); //hide debug infos
            i += 1;
        }

        printf("成功讀取檔案\n");

        char searchAccStr[64];
        char searchPWDstr[64];
        memset(searchAccStr, '\0', 64);
        memset(searchPWDstr, '\0', 64);
        printf("請輸入使用者帳號:");
        scanf("%s", &searchAccStr);
        printf("請輸入密碼:");
        scanf("%s", &searchPWDstr);
        int foundAccount = 0;
        for (int i = 0; i < 101; i++)
        {
            if (strcmp(userAccount[i], searchAccStr) == 0)
            {
                printf("找到帳號!\n");
                foundAccount = 1;
                if (strcmp(userPWD[i], searchPWDstr) == 0)
                {
                    printf("密碼正確!歡迎%s成功登入\n", userAccount[i]);
                }
                else
                {
                    printf("密碼輸入錯誤>=<\n");
                }
                break;
            }
        }

        if (foundAccount == 0)
            printf("查無此帳號，請查明後再播");

        return 0;
    }
}