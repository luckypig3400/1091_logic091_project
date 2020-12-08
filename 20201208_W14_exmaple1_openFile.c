#include <stdio.h>
#include <stdlib.h>

//解決CMD顯示出現亂碼:https://blog.darkthread.net/blog/command-prompt-codepage/

int main()
{
    FILE *fp;                      /*宣告一個指標形態的變數，變數名稱:pFile */
    //fp = fopen("fileIO.txt", "r"); /*以讀取方式開啟檔案*/
    //開檔關檔建議寫法by老師
    if (!(fp = fopen("fileIO.txt","r")))
    {
        printf("無法開啟檔案");
        return -1;
    }else 
        printf("成功開啟檔案");
    
    fclose(fp);

    return 0;
}