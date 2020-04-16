/***********
文件名：2749_分解因数.c
作者：胡毅翔
学号：PB18000290
文件主要功能：
	给出一个正整数a，要求分解成若干个正整数的乘积，即a = a1 * a2 * a3 * ... * an，
并且1 < a1 <= a2 <= a3 <= ... <= an，问这样的分解的种数有多少。注意到a = a也是一种分解。
************/
#include <stdio.h>
/***********
函数名：factor
函数功能描述：对 goal进行因数分解，且因数<=max，返回该条件下的所有分解的种数
输入参数的类型和意义：1）int goal:待因数分解的数 2）int max:因子的最大值
输出参数的类型和意义：1）int:分解的种数
************/
int factor(int goal, int max)
{
    int sum = 0, i;
    if (goal == 1) //递归结束条件
        return 1;
    for (i = 2; i <= max; i++)
    {
        if (goal % i == 0)
        { //i为因子
            sum = sum + factor(goal / i, i);
        }
    }
    return sum;
}
int main()
{
    int n, a;
    //输入 待因数分解的数的个数
    scanf("%d", &n);
    while (n--)
    {
        //输入 待因数分解的数
        scanf("%d", &a);
        //输出
        printf("%d\n", factor(a, a));
    }
    return 0;
}