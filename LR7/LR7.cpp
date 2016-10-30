// LR7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include<stdlib.h>

#define MAX 20

int main(void){
	double array[MAX + 1], newElement;//���������� ������ � ����� ��� ���������� ������ ��������
	int N,index;//���������� ������ ��� ���������� ������� �������� ������ � ������� ��� ������� ������ ��������

	printf("Enter amount of elements in array:\n");
	scanf("%d", &N);//�������� ������� �������� � �����

	while (N > MAX){//���� ������� �������� �������� ����������� ��������� ��������� ������ ������ ��������� ���
		system("cls");
		printf("Enter amount of elements in array less then %d:\n",MAX);
		scanf("%d", &N);
	}

	printf("Input %d elements in descending order:\n", N);

	for (int i = 0; i < N; i++){//���� �������� �������� ������ � ���������� �������
		double element;
		scanf("%lf", &element);

		if (i>0){
			while (array[i - 1] < element){//���� �������� ������� �� ������� �������������� ������, ��������� ��������
				printf("This element should be less then: %f.\n", array[i - 1]);
				printf("Please, enter another value.\n");
				scanf("%lf", &element);
			}
		}
		array[i] = element;//����� �������� � �����
	}

	printf("Array:\n");
	for (int i = 0; i < N; i++){//���� ��������� ������ �� ����� ������
		printf("%f ", array[i]);
	}

	printf("\n Enter element for inserting in array:");
	scanf("%lf", &newElement);//�������� �������� ��� �������

	for (int i = 0; i < N-1; i++){//���� ������ ������� ������ ��� ������� ������ �������� � ����������� ��������������

		if (newElement > array[0]){
			index = 0;
			break;
		}
		else if (newElement < array[N - 1]){
			index = N;
			break;
		}
		else if (newElement < array[i] && newElement > array[i + 1]){
			index = i+1;
			break;
		}		
	}

	for (int j = N - 1; j >=index; j--){//���� ����� ��� �������� �� 1 ��������
		array[j + 1] = array[j];
	}
	array[index] = newElement;//���������� ������ �������� � �����
	
	printf("Updated array:\n");
	for (int i = 0; i < N + 1; i++){//��������� ������ ������ �� ����� ������
		printf("%f ", array[i]);
	}

	getchar();
	getchar();
	return 0;
}

