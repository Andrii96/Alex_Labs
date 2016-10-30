// LR9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int main(void){
	char binaryDecimalCode[130], decimalValue[30],symb;//Символьні рядки для зберігання двійково-десядкового коду числа та його десяткового значення відповідно
	int length = 0, count = 0;//Змінні для збереження довжини обох символьних рядків
	puts("Enter binary-decimal code of some number:\n");

	while ((symb = getchar()) != '\n'){//Посимвольне введення двійково-десяткового коду
		binaryDecimalCode[length++] = symb;
	}

	binaryDecimalCode[length] = '\0';//Запис нуль-символа в кінець символьного рядка
	
	char*pEnd = binaryDecimalCode + length-1;//Налаштування вказівника на кінець символьного рядка з двійково-десятковим кодом

	while (pEnd >= binaryDecimalCode){//Поки не початок рядка
		int decimal=0;
		int binary = 1;
		for (int i = 0; i < 4 && pEnd >= binaryDecimalCode; pEnd--, i++){//Пошук десяткового значення кожної тетради
			decimal += (*pEnd - 48)*binary;
			binary *= 2;
		}
		decimalValue[count++] = decimal + '0';//Запис десяткового значення в новий символьний рядок
	}
	decimalValue[count] = '\0';//Запис нуль-символа в кінець символьного рядка

	//Цикл реверсу символьного рядка(Реверс - запис символьного рядка у зворотньому порядку: "123ак"->"ка321")
	for (char *begin = decimalValue, *end = decimalValue + count - 1; begin < end; begin++, end--){
		char tmp = *begin;
		*begin = *end;
		*end = tmp;
	}
	puts("Decimal value of binary-decimal code:");
	//Виведення знайденого значення на екран
	puts(decimalValue);
	getchar();
	getchar();
	return 0;
}
