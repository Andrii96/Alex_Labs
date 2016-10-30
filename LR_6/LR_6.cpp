// LR_6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include<stdlib.h>
#include <time.h>

#define MAX 250

int main(void){

	int N, amount = 0;//���� ��� ���������� ������� ������������ ����� � ������� �����, � ���� ����� � ������� ����� ������� ��������
	printf("Input amount of numbers you want to generate:\n");
	scanf("%d", &N);//�������� ������� ����� ��� �����������

	while (N > MAX){//���� �� ������� �������� ����� �� 250 - ��������� ��������
		system("cls");//�������� ������ ������
		printf("Please, enter number less then %d.\n", MAX);
		scanf("%d", &N);//���������� ��������
	}

	srand((unsigned)time(NULL));//�������� ����������
	printf("Numbers that have the same first and last digit:\n");

	for (int i = 0; i < N; i++){

		int randomNumber = 1000 + rand() % 9999;//����������� 4-��������� �����

		if (randomNumber % 10 == (int)randomNumber / 1000){//���� ����������� ����� ������� ����
			printf("%d\n", randomNumber);//��������� ����� �� �����
			amount++;//��������� ������� ��������� ����� �� 1
		}		
	}

	printf("Total numbers: %d.\n", N);
	printf("Percentage of numbers that have the same 1-st and last digit: %.3f %%.\n", (double)amount / N * 100);

	getchar();
	getchar();
	return 0;
}

