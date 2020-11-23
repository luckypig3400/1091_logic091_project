#include <stdio.h>

int main(){
    
    printf("請輸入一整數:");
    int userInput;
    scanf("%d",&userInput);
    if(userInput == 0)printf("0!=0");
    else{
        int sum = 1;
        for(int i = 1;i<=userInput;i++){
            sum *= i;
            printf("%d!=%d\n",i,sum);
        }
    }

    return 0;
}