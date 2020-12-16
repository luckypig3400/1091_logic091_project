# 1091_logic091_project
 
## 解決CMD顯示出現亂碼:

	use command "chcp 65001" to active utf-8 output in cmd

+ https://blog.darkthread.net/blog/command-prompt-codepage/

## C 字串處理

+ https://openhome.cc/Gossip/CGossip/StringLengthCopyCat.html

```=c
#include <stdio.h>
#include <string.h>

int main(){
	char destinationString[64];
	char sourceString[32] = "source string";
	char concatedString[256] = "some text...";

	strcpy(destinationString, sourceString);
	// 複製字串

	strcat(concatedString, souceString);
	// 串接字串
	
}

```

## 輸出補零

+ https://zhidao.baidu.com/question/199473779.html

```=c
#include <stdio.h>

int main()
{
    for(int i=0;i<100;i++){
    	// printf("filename%3d\n",i);//  輸出補空格
		printf("filename%03d\n",i);// 輸出補0
    }

	return 0;
}

```
