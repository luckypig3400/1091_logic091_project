#include <stdio.h>

int main()
{
	/*
	//practice1
	float customerShoppingAmount = 0;
	printf("請輸入客戶購物金額(元):");
	scanf("%f", &customerShoppingAmount);
	printf("==========================\n");
	if (customerShoppingAmount >= 100000)
	{
		printf("折扣為20%%\n"); //%%才會正常輸出百分比%符號
		printf("實付為%.0f元\n", (customerShoppingAmount * 0.8));
		//%.0f代表輸出的數顯示0位小數點
		//%.1f代表輸出的數顯示1位小數點 以此類推...
	}
	else if (customerShoppingAmount >= 30000)
	{
		printf("折扣為15%%\n"); //%%才會正常輸出百分比%符號
		printf("實付為%.0f元\n", (customerShoppingAmount * 0.85));
	}
	else if (customerShoppingAmount >= 5000)
	{
		printf("折扣為10%%\n"); //%%才會正常輸出百分比%符號
		printf("實付為%.0f元\n", (customerShoppingAmount * 0.9));
	}
	else if (customerShoppingAmount >= 1000)
	{
		printf("折扣為5%%\n"); //%%才會正常輸出百分比%符號
		printf("實付為%.0f元\n", (customerShoppingAmount * 0.95));
	}
	else
	{
		printf("折扣為0%%\n"); //%%才會正常輸出百分比%符號
		printf("實付為%.0f元\n", customerShoppingAmount);
	}

	//practice2
	float weight = 0, height = 0;
	printf("請輸入體重(Kg):");
	scanf("%f", &weight);
	printf("請輸入身高(Cm):");
	scanf("%f", &height);
	height = height / 100; //cm to m
	float BMI = weight / (height * height);
	printf("==========================\n");
	printf("BMI:%.3f\n", BMI);
	*/return 0;
}

//practice3
#include <stdio.h>

int main()
{
	char scoreGrade = 'w';
	printf("請輸入分數群組:");
	scanf("%c", &scoreGrade);
	printf("==========================\n");
	if (scoreGrade == 'a' || scoreGrade == 'A')
		printf("分數在90分以上\n");
	else if (scoreGrade == 'b' || scoreGrade == 'B')
		printf("分數在80分以上\n");
	else if (scoreGrade == 'c' || scoreGrade == 'C')
		printf("分數在70分以上\n");
	else if (scoreGrade == 'd' || scoreGrade == 'D')
		printf("分數在60分以上\n");
	else if (scoreGrade == 'e' || scoreGrade == 'E')
		printf("你被當掉了\n");
	else
		printf("沒有此分數群組\n");

	return 0;
}

//practice4 creditCard classmate version
#include <stdio.h>
int main() {
	int functionSelection;
	float credits,cardYear;
	printf("請輸入信用額度:");
	scanf("%f",&credits);
	printf("繳款是否正常(1:正常,0:不正常):");
	scanf("%d",&functionSelection);
	if(functionSelection==0) {
		printf("預借金額為0元");
	} else if(functionSelection==1) {
		printf("請輸入持卡年分");
		scanf("%f",&cardYear);
		if(cardYear>=1) {
			printf("預借金額為%.0f元",credits*0.1);
		} else if(cardYear<1&&cardYear>=0.5) {
			printf("預借金額為%.0f元",credits*0.05);
		} else {
			printf("預借金額為0元");
		}

	}
	return 0;
}

//practice4 creditCard
#include <stdio.h>
int main() {
	int credit , regularUse;
	float cardYear;
	printf("請輸入信用額度:");
	scanf("%d",&credit);
	printf("繳款是否正常(1:正常,0:不正常):");
	scanf("%d",&regularUse);
	if(regularUse == 1){
		printf("請輸入持卡年份:");
		scanf("%f",&cardYear);
		if(cardYear >= 1)printf("預借現金金額為%d元",credit/10);
		else if(cardYear >= 0.5)printf("預借現金金額為%d元",credit/20);
		else printf("無法預借現金");
	}else printf("無法預借現金");
	
	return 0;
}

//practice5 leapYearJudge
#include <stdlib.h>
int main() {
	int year;
	printf("請輸入年分:");
	scanf("%d",&year);
	if(year%400==0||year%4==0&&year%100!=0) {
		printf("閏年");
	} else printf("平年") ;
	
	return 0;
}
