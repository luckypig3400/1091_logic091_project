#include <stdio.h>
#include <string.h>

int main()
{

    float score[3][6];
    /*
    ch en math sum average original_id
    [] [] []   []  []      [] = 0
    [] [] []   []  []      [] = 1
    [] [] []   []  []      [] = 2
    */

    int searchID = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (j == 5)
                score[i][j] = i; //write original ID
            else
                score[i][j] = 0;
        }
    }

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

            scanf("%f", &score[i][j]);
        }
        score[i][3] = score[i][0] + score[i][1] + score[i][2]; //計算並儲存總和
        score[i][4] = score[i][3] / 3;                         //計算平均
    }

    printf("======未按照成績排序======\n");
    for (searchID = 0; searchID < 3; searchID++)
    { //輸出全部結果(未排序)
        printf("第%d位同學的成績為：國文%.0f分，英文%.0f分，數學%.0f分\t總分:%.0f分\t平均:%.2f分 \n", searchID + 1, score[searchID][0], score[searchID][1], score[searchID][2], score[searchID][3], score[searchID][4]);
    }

    for (int i = 0; i < 3; i++) //排序區塊(小到大)
    {
        for (int j = 0; j < 3; j++)
        {
            if (score[i][3] < score[j][3]) //[][3]第三格為總分
            {
                int swap = score[i][3];
                score[i][3] = score[j][3];
                score[j][3] = swap;

                int orgID = score[i][5]; //總分排序完後搬移原始ID儲存格
                score[i][5] = score[j][5];
                score[j][5] = orgID;
            }
        }
    }

    //TODO 按照原始ID搬移剩餘的成績

    printf("======已按照成績排序======\n");
    for (int searchID = 0; searchID < 3; searchID++)
    {
        printf("(原始ID:%d)第%d位同學的成績為：國文%.0f分，英文%.0f分，數學%.0f分\t總分:%.0f分\t平均:%.2f分 \n", score[searchID][5], searchID + 1, score[searchID][0], score[searchID][1], score[searchID][2], score[searchID][3], score[searchID][4]);
    }

    return 0;
}