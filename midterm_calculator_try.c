#include <stdio.h>

int main()
{

    char str[16];
    printf("Please input string:");
    gets(str); //抓一字串。(可包含空格)
    printf("Input String is:%s", str);
    for (int i = 0; i < 16; i++)
    {
        printf("str[%d]=%d   ", i, str[i]);
    }

    return 0;
}