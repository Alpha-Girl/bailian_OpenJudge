/***********
文件名：计算2的N次幂.c
作者：胡毅翔
学号：PB18000290
文件主要功能：
    任意给定一个正整数 N(N<=100)，计算 2 的 N 次方的值。
************/
#include <stdio.h>
#define MAX_LEN 200
int result[MAX_LEN];
int nHighestPos = 0;
/***********
函数名：DoMultiply
函数功能描述：对reslut[]数组中所表示的数乘2，并修改nHighestPos的值
             保持nHighestPos指向当前最高位
输入参数的类型和意义：无
输出参数的类型和意义：无
************/
void DoMultiply(){
    int i;
    for (i = 0; i <= nHighestPos; i++){
        result[i] *= 2;
    }
    //进位处理
    for (i = 0; i <= nHighestPos; i++){
        if (result[i] >= 10){
            result[i + 1]++;
            result[i] = result[i] % 10;
        }
    }
    //nHighestPos修改
    if (result[nHighestPos + 1] != 0){
        nHighestPos++;
    }
}
int main(){
    int n, i;
    //result[]数组初始化
    for (i = 0; i < MAX_LEN; i++){
        result[i] = 0;
    }
    //输入
    scanf("%d", &n);
    //判断输入是否合法
    if (n < 0){
        printf("Illegal input value.\n");
        return 0;
    }
    result[0] = 1;
    //计算
    while (n > 0){
        DoMultiply();
        n--;
    }
    //输出
    for (i = nHighestPos; i >= 0; i--){
        printf("%d", result[i]);
    }
    printf("\n");
    return 0;
}