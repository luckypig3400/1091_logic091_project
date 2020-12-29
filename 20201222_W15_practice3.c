// W15 HW : http://logic091.ntunhs.org/course/W15.pdf

// string replace can refer to this page:
// https://jax-work-archive.blogspot.com/2009/04/c-strreplace.html

// string compare can refer to this page:
// http://tw.gitbook.net/c_standard_library/c_function_strcmp.html

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *inputFile;
FILE *outputFile;
char inputFileName[60] = ".\\bin\\user.dat";
char welcomeFileContent[256] = "親愛的用戶，您好：\n\n\t歡迎使用LowNet進行網路連線，以下為您的帳號與密碼。\n\n\t\t帳號: <ID>\n\t\t密碼: <PASSWORD>\n\n\n\t若有任何問題，歡迎與我們聯絡，電話為321。";

char *str_replace(char *source, char *find, char *rep)
{
    // 搜尋文字的長度
    int find_L = strlen(find);
    // 替換文字的長度
    int rep_L = strlen(rep);
    // 結果文字的長度
    int length = strlen(source) + 1;
    // 定位偏移量
    int gap = 0;

    // 建立結果文字，並複製文字
    char *result = (char *)malloc(sizeof(char) * length);
    strcpy(result, source);

    // 尚未被取代的字串
    char *former = source;
    // 搜尋文字出現的起始位址指標
    char *location = strstr(former, find);

    // 漸進搜尋欲替換的文字
    while (location != NULL)
    {
        // 增加定位偏移量
        gap += (location - former);
        // 將結束符號定在搜尋到的位址上
        result[gap] = '\0';

        // 計算新的長度
        length += (rep_L - find_L);
        // 變更記憶體空間
        result = (char *)realloc(result, length * sizeof(char));
        // 替換的文字串接在結果後面
        strcat(result, rep);
        // 更新定位偏移量
        gap += rep_L;

        // 更新尚未被取代的字串的位址
        former = location + find_L;
        // 將尚未被取代的文字串接在結果後面
        strcat(result, former);

        // 搜尋文字出現的起始位址指標
        location = strstr(former, find);
    }

    return result;
}

char *str_replace(char *, char *, char *);

int main()
{

    inputFile = fopen(inputFileName, "r");

    if (inputFile == NULL)
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
        while (fgets(tempStr, 64, inputFile) != NULL)
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

        for (int i = 0; i < 100; i++)
        {
            // TODO:將已經更改好的文字分別寫入到100個檔案中
            char outputFileName[60] = ".\\bin\\W15HWoutput\\HN";
            char fileNum[4];
            fileNum[0] = ((i + 1) / 100) + '0';
            fileNum[1] = ((i + 1) / 10) % 10 + '0';
            fileNum[2] = ((i + 1) % 10) + '0';
            fileNum[3] = '\0';
            strcat(outputFileName, fileNum);
            strcat(outputFileName, ".txt");
            printf("檔名:%s\n", outputFileName);

            char *contentToWriteInFiles = str_replace(welcomeFileContent, "<ID>", userAccount[i]);
            contentToWriteInFiles = str_replace(contentToWriteInFiles, "<PASSWORD>", userPWD[i]);
            printf("HN%03d的文件內容:\n%s\n", i + 1, contentToWriteInFiles);

            outputFile = fopen(outputFileName, "w+");
            fputs(contentToWriteInFiles, outputFile);
            fclose(outputFile);
        }

        return 0;
    }
}