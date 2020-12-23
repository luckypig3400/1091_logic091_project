#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *file1;
char fileName[60] = "user.dat";

void writeFile(char in_userAccount[60], char in_pwd[60])
{
    char writeCache[256] = "";
    strcat(writeCache, in_userAccount);
    strcat(writeCache, "\t");
    strcat(writeCache, in_pwd);
    strcat(writeCache, "\n");
    fputs(writeCache, file1);
}

int main()
{
    file1 = fopen(fileName, "w+");

    for (int i = 1; i <= 100; i++)
    {
        char num[9];
        sprintf(num, "%03d", i); //把i補0後存到num裡
        // 小技巧:使用atio()可以把字串轉數字
        //https://bbs.csdn.net/topics/10129157

        char userAccount[60] = "HN";
        strcat(userAccount, num);
        printf("%s\n", userAccount);
        strcat(userAccount, "\t");
        fputs(userAccount, file1);


    }

    fclose(file1);
    return 0;
}