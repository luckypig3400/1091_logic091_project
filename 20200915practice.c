// 輸出輸入基本練習

#include <stdio.h>

int main(){
	int WrongQ = 3,Score = 100;
	float Question = 2.5;
	char Level = 'A';
	char Name[16] = "Your Name";
	
	printf("這個課程是\"C\"\n");
	printf("程式在'C:\\Dev-C\\'下\n");
	printf("總分佔100%%\n");

	printf("學生姓名:%s\n",Name);
	printf("成績(整數):%d\n",(Score - WrongQ*(int)Question));
	printf("成績(浮點數)：%f\n", (Score- WrongQ*Question));
	printf("等級：%c\n",Level);

	return 0;
}
