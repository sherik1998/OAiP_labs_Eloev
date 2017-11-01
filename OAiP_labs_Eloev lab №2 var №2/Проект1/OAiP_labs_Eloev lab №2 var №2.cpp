/*
	Елоев Георгий Александрович
	КТБО 1-8
	Лабораторная № 2
	Вариант №2
	Задание: Написать программу, которая вычисляет среднее арифметическое элементов
массива без учета минимального и максимального элементов массива. Массив и
его длина вводятся пользователем.
*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_LENGTH 100
#define MIN_LENGTH 3

int function_enter2(void);
float function_enter(void);

int main()
{
	system("chcp 1251");
	system("cls");
	float array[MAX_LENGTH];
	int length = 0;
	printf("Введите длину массива:");
	while (length > MAX_LENGTH || length < MIN_LENGTH)
	{
		length = function_enter2();
		if (length > MAX_LENGTH || length < MIN_LENGTH)
		{
			printf("Ошибка ввода!Длина массива не должна содержать буквы, привышать 100 и быть меньше 3!\nПовторите попытку ввода: ");
		}
	}

	int counter; 
	for (counter = 0; counter < length; counter++)
	{
		printf("Ввведите значение array[%d]:", counter);
		array[counter] = function_enter();
	}
	int max = 0;
	int min = 0;
	for (counter = 1; counter < length; counter++)
	{
		if (array[max] < array[counter])
		{
			max = counter;
		}

		if (array[min] > array[counter])
		{
			min = counter;
		}
	}
	array[max] = 0;
	array[min] = 0;
	float average;
	average = 0;
	for (counter = 0; counter < length; counter++)
		average = average + array[counter];
	average = average / (length - 2);
	printf("Среднее арифметическое значение массива без минимального и максимального значения: %.1f", average);
	_getch();
	return 0;
}
int function_enter2(void)
{
	int number;
	scanf("%d", &number);
	if (getchar() != '\n' ) 
	{
		printf("Ошибка ввода!Длина массива не должна содержать буквы, привышать 100 и быть меньше 3!\nПовторите попытку ввода: ");
		while (getchar() != '\n');
		number = function_enter();
	}
	return number;
}

float function_enter(void)
{
	float number;
	scanf("%f", &number);
	if (getchar() != '\n') 
	{
		printf("Ошибка!\nПовторите ввод:");
		while (getchar() != '\n');
		number = function_enter();
	}
	return number;
}