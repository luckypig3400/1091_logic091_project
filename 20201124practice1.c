#include <stdio.h>
#include <string.h>

int main()
{

    char user[10][16] = {"User1", "User2", "User3", "User4", "User5",
                         "User6", "User7", "User8", "User9", "User10"};
    char pwd[10][16] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};

    char userInput[16];
    char pwdInput[16];
    printf("請輸入帳號：");
    scanf("%s", &userInput);
    printf("請輸入密碼：");
    scanf("%s", &pwdInput);

    int foundUser = 0;

    for (int i = 0; i < 10; i++)
    {
        if (stricmp(user[i], userInput) == 0)
        { //找到帳號
            if (stricmp(pwd[i], pwdInput) == 0)
            {
                printf("帳號密碼正確");
            }
            else
            {
                printf("密碼錯誤");
            }
            foundUser = 1;
            break;
        }
    }

    if(foundUser == 0)printf("密碼正確");

    return 0;
}