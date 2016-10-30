// LR7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include<stdlib.h>

#define MAX 20

int main(void){
	double array[MAX + 1], newElement;//Оголошення масиву і змінної для збереження нового елемента
	int N,index;//Оголошення змінних для збереження кількості елементів масиву і індексу для вставки нового елемента

	printf("Enter amount of elements in array:\n");
	scanf("%d", &N);//Введення кількості елементів у масиві

	while (N > MAX){//Якщо введене значення перевищує максимально дозволену розмірність масиву ввести значеннще раз
		system("cls");
		printf("Enter amount of elements in array less then %d:\n",MAX);
		scanf("%d", &N);
	}

	printf("Input %d elements in descending order:\n", N);

	for (int i = 0; i < N; i++){//Цикл введення елементів масиву у спадаючому порядку
		double element;
		scanf("%lf", &element);

		if (i>0){
			while (array[i - 1] < element){//Поки введений елемент не відповідає впорядкованості масиву, повторити введення
				printf("This element should be less then: %f.\n", array[i - 1]);
				printf("Please, enter another value.\n");
				scanf("%lf", &element);
			}
		}
		array[i] = element;//запис елемента у масив
	}

	printf("Array:\n");
	for (int i = 0; i < N; i++){//Цикл виведення масиву на екран консолі
		printf("%f ", array[i]);
	}

	printf("\n Enter element for inserting in array:");
	scanf("%lf", &newElement);//Введення елемента для вставки

	for (int i = 0; i < N-1; i++){//Цикл пошуку індекса масиву для вставки нового елементу зі збереженням впорядкованості

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

	for (int j = N - 1; j >=index; j--){//Цикл зсуву всіх елементів на 1 праворуч
		array[j + 1] = array[j];
	}
	array[index] = newElement;//Вставлення нового елемента у масив
	
	printf("Updated array:\n");
	for (int i = 0; i < N + 1; i++){//Виведення нового масиву на екран консолі
		printf("%f ", array[i]);
	}

	getchar();
	getchar();
	return 0;
}

