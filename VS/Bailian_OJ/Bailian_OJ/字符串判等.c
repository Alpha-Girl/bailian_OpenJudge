/***********
文件名：字符串判等.c
作者：胡毅翔
学号：PB18000290
文件主要功能：
	判断两个由大小写字母和空格组成的字符串在忽略大小写，且忽略空格后是否相等。
************/
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
#define MAX_LEN 120
/***********
函数名：DelSpace
函数功能描述：删除字符串中的空格
输入参数的类型和意义：1）char*:待处理的字符串的地址
输出参数的类型和意义：无
************/
void DelSpace(char* str) {
	int i = 0, j = 0;
	//i指向当前处理字符的位置，j指向下一字符应写入位置
	for (; str[i] != '\0'; i++) {//判断字符串是否结束
		if (str[i] != ' ') {//当前字符不是空格，写入，j向后移动
			str[j] = str[i];
			j++;
		}
	}
	str[j] = '\0';
}
int main() {
	char str1[MAX_LEN], str2[MAX_LEN];
	//读取字符串
	gets(str1);
	gets(str2);
	//删除字符串中的空格
	DelSpace(str1);
	DelSpace(str2);
	if (strlen(str1) == 0 && strlen(str2) == 0)//特殊情况判断
		printf("YES\n");
	else if (!stricmp(str1, str2))//字符串比较
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
