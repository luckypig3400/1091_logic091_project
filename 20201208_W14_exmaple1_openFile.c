#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;                      /*宣告一個指標形態的變數，變數名稱:pFile */
    fp = fopen("fileIO.txt", "r"); /*以讀取方式開啟檔案*/
    if (fp != NULL)
    {
        fclose(fp); /*關閉檔案 */
        printf("檔案關閉成功\\n");
    }
    return 0;
}