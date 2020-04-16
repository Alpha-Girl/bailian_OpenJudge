/***********
文件名：2787_算24.c
作者：胡毅翔
学号：PB18000290
文件主要功能：
	给出4个小于10个正整数，你可以使用加减乘除4种运算以及括号把这4个数连接起来得到一个表达式。
现在的问题是，是否存在一种方式使得得到的表达式的结果等于24。这里加减乘除以及括号的运算结果和
运算的优先级跟我们平常的定义一致（这里的除法定义是实数除法）。
************/
#include <stdio.h>
#include <math.h>
int numbers[4]; //存放输入的4个数
int flag = 0;   //0表示无解，1表示有解
int num_cal[4]; //计算过程中，存放排列后的四个数
int a[10];      //全排列中使用的全局变量
/***********
函数名：calculate
函数功能描述：判断当前排列是否有解，若有置flag为1
             计算方法为：计算最后两个数的 和 积 差（两种） 商（两种）之后
                        将两位数合为一位 递归计算 新的最后两位数
输入参数的类型和意义：1）int n:还未使用的数的个数 2）float result:已计算部分的值
输出参数的类型和意义：无
************/
void calculate(int n, float result)
{
    if (n == 0) //4个数均已用过，判断是否有解
    {
        if (fabs(result - 24) < 10e-3)
            flag = 1;
        return;
    }
    if (flag == 1) //已有解
        return;
    else
    {
        //递归
        calculate(n - 1, result + num_cal[n - 1]);
        calculate(n - 1, result * num_cal[n - 1]);
        calculate(n - 1, result / (float)num_cal[n - 1]);
        calculate(n - 1, result - num_cal[n - 1]);
        calculate(n - 1, num_cal[n - 1] - result);
        if (!fabs(result) < 10e-3)
            calculate(n - 1, (float)(num_cal[n - 1]) / result);
    }
}
/***********
函数名：handle_before_cal
函数功能描述：对全排列后的数（1-4）进行处理，转换为对 输入的四个数的排列，后调用calculate()函数
输入参数的类型和意义：1）int n:须处理的数的个数
输出参数的类型和意义：无
************/
void handle_before_cal(int n)
{
    int i;
    int b[10], c;
    for (i = 1; i <= n; i++)
    {
        c = a[i];
        b[c] = i;
    }
    for (i = 1; i <= n; i++)
        num_cal[i - 1] = numbers[b[i] - 1];
    calculate(3, num_cal[3]);
}
/***********
函数名：Permatution
函数功能描述：进行全排列
输入参数的类型和意义：1）int n:排列的总数 2）int m:待排列的数的个数
输出参数的类型和意义：无
************/
void Permatution(int n, int m)
{
    int i, j;
    if (m == 0) //已排完 调用处理函数
    {
        handle_before_cal(n);
        return;
    }
    for (i = 1; i <= n; i++)
    {
        if (a[i] == 0)
        {
            a[i] = n - m + 1;
            Permatution(n, m - 1);
            a[i] = 0;
        }
    }
}
/***********
函数名：check
函数功能描述：全排列前的初始化
输入参数的类型和意义：无
输出参数的类型和意义：无
************/
int check()
{
    int i, j;
    for (i = 0; i < 10; i++)
        a[i] = 0;
    Permatution(4, 4);
}

int main()
{
    int i;
    numbers[0] = 1;
    //输入
    for (i = 0; i < 4; i++)
        scanf("%d", &numbers[i]);
    while (numbers[0] != 0)
    {
        flag = 0;
        check();
        //输出
        if (flag == 1)
            printf("YES\n");
        else
            printf("NO\n");
        //读入新的一组数
        for (i = 0; i < 4; i++)
            scanf("%d", &numbers[i]);
    }
    return 0;
}