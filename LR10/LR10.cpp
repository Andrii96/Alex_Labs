// LR10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>

int main(void){
	char str[130];//Символьний рядок для введення речення
	const char *lim = " ,.!?:;";//Символьний рядок із символами-обмеженнями(розділові знаки)
	char *word; int flag = 0;
	puts("Enter sentence:");
	gets(str);//Введення речення

	word = strtok(str, lim);//Виділення першого слова з речення
	while (word != NULL){//Поки не перевірені усі слова
		char *p = word;//Налаштування вказівника на початок слова
		while (*(p + 1) != '\0'){//Цикл перевірки слова на наявність подвоєння
			if (*p == *(p + 1)){
				flag = 1;
				puts(word);//Виведення слова, що містить подвоєння
				break;
			}
			p++;
		}
		word = strtok(NULL, lim);//Виділення наступнорго слова у реченні
	}
	if (flag == 0){//Якщо слів з подвоєнням немає
		printf("There is not words with double letter.");
	}

	getchar();
	getchar();
	return 0;
}

