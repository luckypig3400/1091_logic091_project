#include <stdio.h>
#include <string.h>

int main(){

    int score[3][3];
    /*
    ch en math
    [] [] []
    [] [] []
    [] [] []
    */
   int searchID = 0;

   for(int i=0;i<3;i++){
       for(int j=0;j<3;j++){
           if(j == 0)printf("請輸入第%d位同學的國文成績：",i+1);
           else if(j==1)printf("請輸入第%d位同學的英文成績：",i+1);
           else printf("請輸入第%d位同學的數學成績：",i+1);

           scanf("%d",&score[i][j]);
       }
   }

    printf("===========================\n");
    printf("請輸入想查詢成績的同學編號:");
    scanf("%d",&searchID);
    searchID -= 1;//讓查詢的位置符合實際存在陣列上位置
    printf("===========================\n");

    printf("第%d位同學的成績為：國文%d分，英文%d分，數學%d分",searchID+1,score[searchID][0],score[searchID][1],score[searchID][2]);

    return 0;
}