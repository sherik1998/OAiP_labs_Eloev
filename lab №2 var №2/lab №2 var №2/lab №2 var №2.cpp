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

int inputСorrectLength();
float inputСorrectArray();

int main()
{
	system("chcp 1251");
	system("cls");
	float array[MAX_LENGTH];
	printf("Введите длину массива:");
	int length = inputСorrectLength();
	for (int i = 0; i < length; i++)
	{
		printf("Ввведите значение array[%d]:", i);
		array[i] = inputСorrectArray();
	}
	float max = 0;
	float min = array[0];// присваем минимуму первый элемент массива, чтобы была возможность поиска самого маленького элемента массива
	for (int i = 0; i < length; i++)
	{
		if (max < array[i])
		{
			max = array[i];
		}

		if (min > array[i])
		{
			min = array[i];
		}
	}
	float average;
	float sum = 0;
	for (int i = 0; i < length; i++) 
	{
		sum += array[i];
	}
	sum -= max + min;
	average = (sum) / (length - 2);
	printf("Среднее арифметическое значение массива без минимального и максимального значения: %.1f", average);
	_getch();
	return 0;
}

int inputСorrectLength()
{
	int length;
	scanf("%d", &length);
	if (getchar() != '\n' || length > MAX_LENGTH || length < MIN_LENGTH)
	{
		printf("Ошибка ввода!Длина массива не должна содержать буквы, привышать %d и быть меньше 3!\nПовторите попытку ввода: ", MAX_LENGTH);
		while (getchar() != '\n');
		length = inputСorrectLength();
	}
	return length;
}

float inputСorrectArray()
{
	float number;
	scanf("%f", &number);
	if (getchar() != '\n')
	{
		printf("Ошибка!\nПовторите ввод:");
		while (getchar() != '\n');
		number = inputСorrectArray();
	}
	return number;
}