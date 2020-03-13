/***********
文件名：校门外的树.c
作者：胡毅翔
学号：PB18000290
文件主要功能：
    某校大门外长度为L的马路上有一排树，每两棵相邻的树之间的间隔都是1米。我们可以把
马路看成一个数轴，马路的一端在数轴0的位置，另一端在L的位置；数轴上的每个整数点，即
0，1，2，……，L，都种有一棵树。
    马路上有一些区域要用来建地铁，这些区域用它们在数轴上的起始点和终止点表示。已知
任一区域的起始点和终止点的坐标都是整数，区域之间可能有重合的部分。现在要把这些区域
中的树（包括区域端点处的两棵树）移走。你的任务是计算将这些树都移走后，马路上还有多
少棵树。
************/
#include <stdio.h>
#include <stdlib.h>
#define MAX_M 100

int main()
{
    int nTotal;
    int tree[MAX_M][2];
    int nM;
    int i,j,tmp,curr_tree;
    /*获得输入 马路长度 和 区域数*/
    scanf("%d",&nTotal);
    scanf("%d",&nM);
    /*获得输入 各个区域的起点 和 终点*/
    for(i = 0;i < nM;i++)
    {
        scanf("%d",&tree[i][0]);
        scanf("%d",&tree[i][1]);
    }
    /*冒泡排序 按 区域起点的大小 升序排序*/
    for(i = 0;i < nM;i++)
    {
        for(j = 0;j < nM-i-1;j++)
        {
            if(tree[j][0] > tree[j+1][0])
            {
                tmp = tree[j][0];
                tree[j][0] = tree[j+1][0];
                tree[j+1][0] = tmp;
                tmp = tree[j][1];
                tree[j][1] = tree[j+1][1];
                tree[j+1][1] = tmp;
            }
        }
    }
    /*砍掉第一段区域中的树*/
    nTotal = nTotal - tree[0][1] + tree[0][0];
    /*用变量curr_tree表示当前砍到的最后一棵树*/
    curr_tree = tree[0][1];
    for(i = 1;i < nM;i++)
    {
        if(curr_tree < tree[i][0])
        {
            /*若下一个要砍的区间 和 已砍区间无交集*/
            /*砍下一个区间*/
            nTotal = nTotal - tree[i][1] + tree[i][0] - 1;
            curr_tree = tree[i][1];

        }
        else if(curr_tree < tree[i][1])
        {
            /*若下一个要砍的区间 和 已砍区间有交集*/
            /*且待砍区间 不包含于已砍区间*/
            /*砍去待砍区间剩余部分*/
            nTotal = nTotal - tree[i][1] + curr_tree;
            curr_tree = tree[i][1];
        }
    }
    /*输出*/
    printf("%d\n",nTotal);
    return 0;
}
