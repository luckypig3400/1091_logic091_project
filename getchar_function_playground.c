#include <stdio.h>

int main()
{

    char ch;
    printf("Please input a char:");
    ch = getchar(); //抓一字元。按下Enter後才處理
    printf("Input Char is:%c\n", ch);

    printf("Please input a char:");
    ch = getch(); //抓一字元。按下即處理，字元不會顯示出來
    printf("Input Char is:%c\n", ch);

    printf("Please input a char:");
    ch = getche(); //抓一字元。按下即處理，字元會顯示出來
    printf("Input Char is:%c\n", ch);

    char str[128];
    printf("Please input string:");
    gets(str); //抓一字串。(可包含空格)
    printf("Input String is:%s", str);

    return 0;
}