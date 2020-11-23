//sumInteger_without_if.c
#include <stdlib.h>

int main(){
	int sum,inputNum=0;
	printf("Please input an integer:");
	scanf("%d",&inputNum);
	while(inputNum >= 0){
		sum += inputNum;
		printf("Sum=%d\n",sum);
		printf("Please input an integer:");
		scanf("%d",&inputNum);
	}
	printf("===Program End===");
	return 0;
}

// factorial_caculator.c
#include<stdlib.h>

int main(){
	int n,sum=1;
	printf("請輸入一個正整數，將會自動算出其階乘總和:");
	scanf("%d",&n);	
	for(int i=n;i>0;i--){
		printf("%dx",i);
		sum*=i;
	}
	printf("=%d",sum);
	return 0;
}

// password
#include <stdlib.h>

int main(){
	int setpwd,inputpwd,errorCount=1;
	printf("請設定密碼:");
	scanf("%d",&setpwd);
	printf("密碼已設定 \n");
	
	printf("請輸入密碼:");
	scanf("%d",&inputpwd);
	while(inputpwd != setpwd){
		errorCount += 1;
		printf("密碼錯誤，請輸入密碼:");
		scanf("%d",&inputpwd);
		if(errorCount == 3 && inputpwd != setpwd){
			//為何多加上&& inputpwd != setpwd
			//因為可以避免在第三次輸入正確密碼，卻仍呼叫出以下程式碼 
			printf("已錯誤%d次，請於5秒後再試\n",errorCount);
			sleep(5);
		}else if(errorCount == 5 && inputpwd != setpwd){
			//為何多加上&& inputpwd != setpwd
			//因為可以避免在第五次輸入正確密碼，卻仍呼叫出以下程式碼 
			printf("錯誤次數過多，將結束程式...");
			break;
		}
	}
	if(inputpwd == setpwd){
		printf("密碼正確!");
	} 
	
	return 0;
}
