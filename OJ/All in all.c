/***********
文件名：All in all.c
作者：胡毅翔
学号：PB18000290
文件主要功能：
	给定两个字符串s和t，判断s是否是t的子序列。即从t中删除一些字符，将剩余的字符连接起来，即可获得s。
	若是，打印Yes，否则，打印No
************/
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
#define MAX_LEN 100010
int main() {
	char str1[MAX_LEN], str2[MAX_LEN];
	int i = 0, j = 0, len1, len2;
	scanf("%s", str1);
	scanf("%s", str2);
	len1 = strlen(str1);
	len2 = strlen(str2);
	for (; j < len2; j++) {
		if (str1[i] == str2[j])
			i++;
		if (i == len1)
			break;
	}
	if (i == len1)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
