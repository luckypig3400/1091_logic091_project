#include <stdio.h>
#include <stdlib.h>

int main()
{

	//practice1 判斷停車的時數與收費
	int hour = 0;
	printf("請輸入您停車的時數，將會為您自動算出停車費(每小時收費$40):\n");
	scanf("%d", &hour);
	if (hour == 1)
		printf("只停1小時不收費\n");
	else
		printf("您的停車費用為%d\n", hour * 40);

	printf("###==================###\n");
	//practice2 浮動決定入場卷的價格
	int ticketCount = 0;
	printf("每張票券360元\n");
	printf("請輸入您欲購買的入場券張數，將會為您自動算出總價(購買入場卷的數量大於等於10張可享有9折優惠):\n");
	scanf("%d", &ticketCount);
	if (ticketCount >= 10)
		printf("您購買的票券總額為%f元\n", (ticketCount * 360 * 0.9));
	else
		printf("您購買的票券總額為%d元\n", ticketCount * 360);


	printf("###==================###\n");
	//practice3 讓使用者輸入一個數值，並可以選擇計算立方或平方
	int number_in = 0, functionSelection;
	printf("平方或立方計算機，請輸入所要計算的數值：");
	scanf("%d", &number_in);
	printf("請輸入1(計算平方值)或2(計算立方值):");
	scanf("%d", &functionSelection);
	printf("==================\n");
	if (functionSelection == 1)
		printf("平方值為：%d\n", number_in * number_in);
	else if (functionSelection == 2)
		printf("立方值為：%d\n", number_in * number_in * number_in);
	else
		printf("您輸入的數字不在功能選項內!\n");


	printf("###==================###\n");
	//practice4 讓使用者輸入一正整數，假如此數值能被2或3整除，則顯示「此數為2或3的倍數」；否則，則顯示「此數非為2或3的倍數」。
	printf("請輸入一正整數(會自動判斷是否為2或3的倍數)：");
	scanf("%d", &number_in);
	printf("==================\n");
	if (number_in % 2 == 0 || number_in % 3 == 0)
		printf("此數為2或3的倍數\n");
	else
		printf("此數非2或3的倍數\n");


	printf("###==================###\n");
	//practiceBeforeExam
	float upper, lower, height, area;
	printf("請分別輸入梯形的上底、下底與高將會自動算出梯形面積(數字以空白隔開):\n");
	scanf("%f%f%f", &upper, &lower, &height);
	area = (upper + lower) * height / 2;
	printf("%f\n", (upper + lower) * height / 2); //solution1
	printf("%f\n", area);						  //solution2

	return 0;
}
