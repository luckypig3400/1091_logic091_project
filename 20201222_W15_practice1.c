#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

    srand(time(NULL)); 

    for (int i = 1; i <= 100; i++)
    {
        char num[9];
        sprintf(num, "%03d", i); //把i補0後存到num裡
        // 小技巧:使用atio()可以把字串轉數字
        //https://bbs.csdn.net/topics/10129157

        char userAccount[60] = "HN";
        strcat(userAccount, num);
        printf("%s\t", userAccount);
        strcat(userAccount, "\t");
        fputs(userAccount, file1);

        char password[32];
        password[0] = '2';
        password[1] = rand() % 26 + 97;  //a~z 97 ~ 122
        password[4] = rand() % 26 + 97;  //a~z 97 ~ 122
        password[7] = rand() % 26 + 97;  //a~z 97 ~ 122
        password[2] = rand() % 26 + 65;  //A~Z 65 ~ 90
        password[5] = rand() % 26 + 65;  //A~Z 65 ~ 90
        password[3] = rand() % 10 + '0'; //generate '0' to '9'
        password[6] = rand() % 10 + '0'; //generate '0' to '9'
        printf("%s\n", password);
    }

    fclose(file1);
    return 0;
}