// LR9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int main(void){
	char binaryDecimalCode[130], decimalValue[30],symb;//�������� ����� ��� ��������� �������-����������� ���� ����� �� ���� ����������� �������� ��������
	int length = 0, count = 0;//���� ��� ���������� ������� ���� ���������� �����
	puts("Enter binary-decimal code of some number:\n");

	while ((symb = getchar()) != '\n'){//����������� �������� �������-����������� ����
		binaryDecimalCode[length++] = symb;
	}

	binaryDecimalCode[length] = '\0';//����� ����-������� � ����� ����������� �����
	
	char*pEnd = binaryDecimalCode + length-1;//������������ ��������� �� ����� ����������� ����� � �������-���������� �����

	while (pEnd >= binaryDecimalCode){//���� �� ������� �����
		int decimal=0;
		int binary = 1;
		for (int i = 0; i < 4 && pEnd >= binaryDecimalCode; pEnd--, i++){//����� ����������� �������� ����� �������
			decimal += (*pEnd - 48)*binary;
			binary *= 2;
		}
		decimalValue[count++] = decimal + '0';//����� ����������� �������� � ����� ���������� �����
	}
	decimalValue[count] = '\0';//����� ����-������� � ����� ����������� �����

	//���� ������� ����������� �����(������ - ����� ����������� ����� � ����������� �������: "123��"->"��321")
	for (char *begin = decimalValue, *end = decimalValue + count - 1; begin < end; begin++, end--){
		char tmp = *begin;
		*begin = *end;
		*end = tmp;
	}
	puts("Decimal value of binary-decimal code:");
	//��������� ���������� �������� �� �����
	puts(decimalValue);
	getchar();
	getchar();
	return 0;
}
