/***********
�ļ�����All in all.c
���ߣ�������
ѧ�ţ�PB18000290
�ļ���Ҫ���ܣ�
	���������ַ���s��t���ж�s�Ƿ���t�������С�����t��ɾ��һЩ�ַ�����ʣ����ַ��������������ɻ��s��
	���ǣ���ӡYes�����򣬴�ӡNo
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
