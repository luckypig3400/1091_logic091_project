#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *file1;
char fileName[60] = "user.dat";

void writeFile(char in_user[60], char in_pwd[60])
{
    char writeCache[256] = "";
    strcat(writeCache, in_user);
    strcat(writeCache, "\t");
    strcat(writeCache, in_pwd);
    strcat(writeCache, "\n");
    fputs(writeCache, file1);
}

int main()
{
    file1 = fopen(fileName, "w");

    return 0;
}