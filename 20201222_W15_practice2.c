#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *file1;
char fileName[60] = ".\\bin\\user.dat";

int main(){

    file1 = fopen(fileName, "r");

    if(file1 == NULL){
        printf("無法開啟檔案 檔案損毀或不存在 將離開系統...");
        return -1;
    }

    else{
        char tempStr[64];
        char userAccAndPWD[100][64];

        printf("成功讀取檔案\n");

        return 0;
    }
}