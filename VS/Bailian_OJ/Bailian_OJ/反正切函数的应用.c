/***********
文件名：反正切函数的应用.c
作者：胡毅翔
学号：PB18000290
文件主要功能：
	给定的 a（1 <= a <= 60000），求 b＋c 的值。对给定的 a 一定存在整数解。如果有多个
解，要求给出 b + c 最小的解。
************/
#include <stdio.h>
/***********
函数名：Check
函数功能描述：判断当b+c=sum时，bc=sum*a+1有无正整数解
             若有，返回1，否则，返回0
输入参数的类型和意义：1）int a:方程中给定的系数 2）int sum:b+c的值
输出参数的类型和意义：1）int:方程是否有解
************/
int Check(int a, int sum)
{
    int b;
    int M;
    //求得等式右边的值
    M = sum * a + 1;
    for (b = 1; b < sum; b++)
    {
        //判断b是否整除M，且对应的c是否满足方程
        if ((M % b == 0) && (sum == M / b + b))
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int a, i;
    //输入
    scanf("%d", &a);
    //计算
    for (i = 2;; i++)
    {
        if (Check(a, i))
            break;
    }
    //输出
    printf("%d\n", i);
}
