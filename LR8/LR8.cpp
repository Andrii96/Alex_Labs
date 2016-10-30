// LR8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int main(void){

	double firstArray[] = { 1.2, 6.7, 0.4, 1.1, 13.11,0.55 };//Оголошення та ініціалізація першого масиву
	double secondArray[] = { 123.1, 163.7, 333.24, 811.1, 111.22,111.4,711.09 };//Оголошення та ініціалізація другого масиву
	double  firstArrAverage;//Змінна для збереження середнього значення елементів 1 масиву

	int amount1 = sizeof(firstArray) / sizeof(double);//Кількість елементів в першому масиві
	int amount2 = sizeof(secondArray) / sizeof(double);//Кількість елементів в другому масиві
	double sum = 0.0;//Змінна для збереження суми
	double value;//Змінна для збереження значення елемента масиву, що задовільняє умову
	int index = -1; //Змінна для збереження індексу елемента масиву, що задовільняє умову

	for (double* pointer = firstArray; pointer < firstArray + amount1; pointer++){//Обчислення суми всіх елементів першого масиву
		sum += *pointer;
	}
	firstArrAverage = sum / amount1;//Обчислення середнього значення елементів першого масиву

	printf("\nFirst array:\n");
	for (double* pointer = firstArray; pointer < firstArray + amount1; pointer++){//Виведення на екран першого масиву
		printf("%.3f ", *pointer);
	}

	printf("\nSecond array:\n");
	for (double* pointer = secondArray; pointer < secondArray + amount2; pointer++){//Виведення на екран другого масиву
		printf("%.3f ", *pointer);
	}

	printf("\nAverage of elements in 1-st array: %f.\n", firstArrAverage);//Виведення на екран середнє значення

	for (double* pointer = secondArray; pointer < secondArray + amount2; pointer++){//Цикл пошуку максимального елемента у 2-му масиві що не перевищує сер. значення елементів 1-го масиву
		
		if (index == -1 && *pointer <= firstArrAverage){
			value = *pointer;
			index = pointer - secondArray;

			for (double *p = pointer + 1; p < secondArray + amount2; p++){
				if (*p > value && *p <= firstArrAverage){
					value = *p;//Запис знайденого елемента у змінну
					index = p - secondArray;//Пошук індекса елемента(різниця вказівників)
				}
			}
			break;
		}
	}
	
	if (index == -1){//Якщо немає елемента, що відповідає умові 
		printf("\nThere is not max element in 2-nd array that is less than average of elements in 1-st array.\n");
	}
	else{
		//Виведення елемента та його номера у масиві
		printf("\nMax element in 2-nd array that is less than average of elements in 1-st array is %.3lf with %d number ", value, index+1);
	}
	getchar();
	getchar();
	return 0;
}

