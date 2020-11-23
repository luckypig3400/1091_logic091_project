// 將上禮拜的練習進行修改，讓使用者可以輸入姓名(Name)與答錯的題 數(WrongQ)

#include <stdio.h>

int main(){
	int WrongQ = 3,Score = 100;
	float Question = 2.5;
	char Level = 'A';
	char Name[16] = "Your Name";
	
	printf("請依序輸入名字、答錯題數(以空白間隔開):\n");
	scanf("%s %d",&Name,&WrongQ);
	
	printf("學生姓名:%s\n",Name);
	printf("成績(整數):%d\n",(Score - WrongQ*(int)Question));
	printf("成績(浮點數)：%f\n", (Score- WrongQ*Question));
	printf("等級：%c\n",Level);

	return 0;
}



// // 練習題 身高判斷
// #include <stdio.h>

// int main() {
// 	int height = 0;
// 	printf("請輸入您的身高(cm):\n");
// 	scanf("%d",&heighWt);
// 	if(height > 180){
// 		printf("高人一等\n");
// 	}else if(height >= 151 && height <= 180){
// 		printf("中等身高\n");
// 	}else{
// 		printf("有點矮喔\n");
// 	}
	
// 	return 0;
// }

// // 練習題 計算平方和
// #include <stdio.h>

// int main() {
// 	int number_in = 1;
// 	int sum = 0;
// 	printf("平方和計算機，請輸入小於100的整數，將會計算1+到該數的平方和:\n");
// 	scanf("%d",&number_in);
// 	for(int i=1; i<=number_in; i++) {
// 		sum += i*i;	
// 		printf("加到%d時總和：%d\n",i,sum);	
// 	}
// 	printf("最後總和：%d\n",sum);
// 	return 0;
// }
