// LR10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>

int main(void){
	char str[130];//���������� ����� ��� �������� �������
	const char *lim = " ,.!?:;";//���������� ����� �� ���������-�����������(������� �����)
	char *word; int flag = 0;
	puts("Enter sentence:");
	gets(str);//�������� �������

	word = strtok(str, lim);//�������� ������� ����� � �������
	while (word != NULL){//���� �� �������� �� �����
		char *p = word;//������������ ��������� �� ������� �����
		while (*(p + 1) != '\0'){//���� �������� ����� �� �������� ��������
			if (*p == *(p + 1)){
				flag = 1;
				puts(word);//��������� �����, �� ������ ��������
				break;
			}
			p++;
		}
		word = strtok(NULL, lim);//�������� ����������� ����� � ������
	}
	if (flag == 0){//���� ��� � ��������� ����
		printf("There is not words with double letter.");
	}

	getchar();
	getchar();
	return 0;
}

