/***********
文件名：反正切函数的应用.c
作者：胡毅翔
学号：PB18000290
文件主要功能：
	给定的 a（1 <= a <= 60000），求 b＋c 的值。对给定的 a 一定存在整数解。如果有多个
解，要求给出 b + c 最小的解。
************/
#include <stdio.h>
#include <math.h>
/***********
函数名：Check
函数功能描述：判断当b+c=sum时，b*c=sum*a+1有无正整数解
			 若有，返回1，否则，返回0
输入参数的类型和意义：1）long long a:方程中给定的系数 2）long long sum:b+c的值
输出参数的类型和意义：1）int:方程是否有解
************/
int Check(long long a, long long sum) {
	long long b;
	long long M;
	long long res;
	//求得等式右边的值
	M = sum * a + 1;
	printf("%lld\n",sum);
	for (b = 1; b <= sum/2; b++) {
		//计算等式左边的值
		res = b * (sum - b);
		if (M == res)
		{
			return 1;
		}
		else if(M < res)
		{
			break;
		}
	}
	return 0;
}
int main() {
	long long a, i;
	//输入
	scanf("%lld", &a);
	//计算
	for (i = 2;; i++) {
		if (Check(a, i))
			break;
	}
	//输出
	printf("%d\n", i);
	return 0;
}
