// LR_6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include<stdlib.h>
#include <time.h>

#define MAX 250

int main(void){

	int N, amount = 0;//Змінні для збереження кількості згенерованих чисел і кількості чисел, у яких перша і остання цифра однакові відповідно
	printf("Input amount of numbers you want to generate:\n");
	scanf("%d", &N);//Введення кількості чисел для генерування

	while (N > MAX){//Поки не введено значення менше за 250 - повторити введення
		system("cls");//Очищення екрану консолі
		printf("Please, enter number less then %d.\n", MAX);
		scanf("%d", &N);//Повторення введення
	}

	srand((unsigned)time(NULL));//Затравка генератора
	printf("Numbers that have the same first and last digit:\n");

	for (int i = 0; i < N; i++){

		int randomNumber = 1000 + rand() % 9999;//Генерування 4-цифрового числа

		if (randomNumber % 10 == (int)randomNumber / 1000){//Якщо зненероване число відповідає умові
			printf("%d\n", randomNumber);//Виведення числа на екран
			amount++;//Збільшення кількості знайдених чисел на 1
		}		
	}

	printf("Total numbers: %d.\n", N);
	printf("Percentage of numbers that have the same 1-st and last digit: %.3f %%.\n", (double)amount / N * 100);

	getchar();
	getchar();
	return 0;
}

