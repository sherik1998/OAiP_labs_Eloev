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

int check();
float checkarray();

int main()
{
	system("chcp 1251");
	system("cls");
	float array[MAX_LENGTH];
	int length = 0;
	printf("Введите длину массива:");
	while (length > MAX_LENGTH || length < MIN_LENGTH)
	{
		length = check();
		if (length > MAX_LENGTH || length < MIN_LENGTH)
		{
			printf("Ошибка ввода!Длина массива не должна содержать буквы, привышать %d и быть меньше 3!\nПовторите попытку ввода: ", MAX_LENGTH);
		}
	}

	for (int i = 0; i < length; i++)
	{
		printf("Ввведите значение array[%d]:", i);
		array[i] = checkarray();
	}
	int max = 0;
	int min = 0;
	for (int i = 1; i < length; i++)
	{
		if (array[max] < array[i])
		{
			max = i;
		}

		if (array[i] > array[i])
		{
			min = i;
		}
	}
	array[max] = 0;
	array[min] = 0;
	float average;
	average = 0;
	for (int i = 0; i < length; i++)
		average = average + array[i];
	average = average / (length - 2);
	printf("Среднее арифметическое значение массива без минимального и максимального значения: %.1f", average);
	_getch();
	return 0;
}

int check()
{
	int number;
	scanf("%d", &number);
	if (getchar() != '\n' ) 
	{
		printf("Ошибка ввода!Длина массива не должна содержать буквы, привышать %d и быть меньше 3!\nПовторите попытку ввода: ", MAX_LENGTH);
		while (getchar() != '\n');
		number = check();
	}
	return number;
}

float checkarray()
{
	float number;
	scanf("%f", &number);
	if (getchar() != '\n') 
	{
		printf("Ошибка!\nПовторите ввод:");
		while (getchar() != '\n');
		number = checkarray();
	}
	return number;
}