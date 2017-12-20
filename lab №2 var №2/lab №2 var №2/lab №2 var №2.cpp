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

int input_checkLength();
float input_checkArray();

int main()
{
	system("chcp 1251");
	system("cls");
	float array[MAX_LENGTH];
	int length = 0;
	printf("Введите длину массива:");
	length = input_checkLength();
	for (int i = 0; i < length; i++)
	{
		printf("Ввведите значение array[%d]:", i);
		array[i] = input_checkArray();
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
	average = 0;
	for (int i = 0; i < length; i++)
		average += array[i];
	average = (average - (min + max)) / (length - 2);
	printf("Среднее арифметическое значение массива без минимального и максимального значения: %.1f", average);
	_getch();
	return 0;
}

int input_checkLength()
{
	int length;
	scanf("%d", &length);
	if (getchar() != '\n' || length > MAX_LENGTH || length < MIN_LENGTH)
	{
		printf("Ошибка ввода!Длина массива не должна содержать буквы, привышать %d и быть меньше 3!\nПовторите попытку ввода: ", MAX_LENGTH);
		while (getchar() != '\n');
		length = input_checkLength();
	}
	return length;
}

float input_checkArray()
{
	float number;
	scanf("%f", &number);
	if (getchar() != '\n')
	{
		printf("Ошибка!\nПовторите ввод:");
		while (getchar() != '\n');
		number = input_checkArray();
	}
	return number;
}