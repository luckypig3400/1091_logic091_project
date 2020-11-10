#include <stdio.h>
#include <string.h>

int main()
{

    int score[3][5];
    /*
    ch en math sum average
    [] [] []   []  []  
    [] [] []   []  []
    [] [] []   []  []
    */
    int searchID = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
                printf("請輸入第%d位同學的國文成績：", i + 1);
            else if (j == 1)
                printf("請輸入第%d位同學的英文成績：", i + 1);
            else
                printf("請輸入第%d位同學的數學成績：", i + 1);

            scanf("%d", &score[i][j]);
        }
        score[i][3] = score[i][0] + score[i][1] + score[i][2];//計算並儲存總和
        score[i][4] = score[i][3] / 3;//計算平均
    }

    for(int i=0;i<3)

    printf("第%d位同學的成績為：國文%d分，英文%d分，數學%d分", searchID + 1, score[searchID][0], score[searchID][1], score[searchID][2]);

    return 0;
}