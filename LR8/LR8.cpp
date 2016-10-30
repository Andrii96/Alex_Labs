// LR8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int main(void){

	double firstArray[] = { 1.2, 6.7, 0.4, 1.1, 13.11,0.55 };//���������� �� ����������� ������� ������
	double secondArray[] = { 123.1, 163.7, 333.24, 811.1, 111.22,111.4,711.09 };//���������� �� ����������� ������� ������
	double  firstArrAverage;//����� ��� ���������� ���������� �������� �������� 1 ������

	int amount1 = sizeof(firstArray) / sizeof(double);//ʳ������ �������� � ������� �����
	int amount2 = sizeof(secondArray) / sizeof(double);//ʳ������ �������� � ������� �����
	double sum = 0.0;//����� ��� ���������� ����
	double value;//����� ��� ���������� �������� �������� ������, �� ���������� �����
	int index = -1; //����� ��� ���������� ������� �������� ������, �� ���������� �����

	for (double* pointer = firstArray; pointer < firstArray + amount1; pointer++){//���������� ���� ��� �������� ������� ������
		sum += *pointer;
	}
	firstArrAverage = sum / amount1;//���������� ���������� �������� �������� ������� ������

	printf("\nFirst array:\n");
	for (double* pointer = firstArray; pointer < firstArray + amount1; pointer++){//��������� �� ����� ������� ������
		printf("%.3f ", *pointer);
	}

	printf("\nSecond array:\n");
	for (double* pointer = secondArray; pointer < secondArray + amount2; pointer++){//��������� �� ����� ������� ������
		printf("%.3f ", *pointer);
	}

	printf("\nAverage of elements in 1-st array: %f.\n", firstArrAverage);//��������� �� ����� ������ ��������

	for (double* pointer = secondArray; pointer < secondArray + amount2; pointer++){//���� ������ ������������� �������� � 2-�� ����� �� �� �������� ���. �������� �������� 1-�� ������
		
		if (index == -1 && *pointer <= firstArrAverage){
			value = *pointer;
			index = pointer - secondArray;

			for (double *p = pointer + 1; p < secondArray + amount2; p++){
				if (*p > value && *p <= firstArrAverage){
					value = *p;//����� ���������� �������� � �����
					index = p - secondArray;//����� ������� ��������(������ ���������)
				}
			}
			break;
		}
	}
	
	if (index == -1){//���� ���� ��������, �� ������� ���� 
		printf("\nThere is not max element in 2-nd array that is less than average of elements in 1-st array.\n");
	}
	else{
		//��������� �������� �� ���� ������ � �����
		printf("\nMax element in 2-nd array that is less than average of elements in 1-st array is %.3lf with %d number ", value, index+1);
	}
	getchar();
	getchar();
	return 0;
}

