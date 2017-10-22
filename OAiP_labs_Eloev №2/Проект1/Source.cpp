/*Елоев Георгий Александрович
КТБО 1-8
Лабораторная № 2
Вариант №2
Задание: Написать программу, которая вычисляет среднее арифметическое элементов
массива без учета минимального и максимального элементов массива. Массив и
его длина вводятся пользователем.*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_LENGTH 100
#define MIN_LENGTH 3



int main()
{
	system("chcp 1251");
	system("cls");
	float array[MAX_LENGTH];
	int length;
	printf("Введите длину массива:");
	while (!scanf("%d", &length) || (length > MAX_LENGTH) || (length < MIN_LENGTH))
	{ 
		printf("Ошибка ввода!Длина массива не должна содержать буквы, привышать 100 и быть меньше 3!\nПовторите попытку ввода: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');
	int counter; 
	float min_and_max;
	for (counter = 0; counter < length; counter++)
	{
		printf("Ввведите значение array[%d]:", counter);
		while (!scanf("%f", &array[counter]))
		{
			printf("Ошибка ввода!!!\nПовторите попытку ввода array[%d]: ", counter);
			while (getchar() != '\n');
		}
		while (getchar() != '\n');
	}
	for (counter = 0; counter < (length - 1); counter++)
	{
		if (array[counter] > array[counter + 1])
		{
			min_and_max = array[counter + 1];
			array[counter + 1] = array[counter];
			array[counter] = min_and_max;
		}
	}
	for (counter = 0; counter < (length - 2); counter++)
	{
		if (array[counter] < array[counter + 1])
		{
			min_and_max = array[counter + 1];
			array[counter + 1] = array[counter];
			array[counter] = min_and_max;
		}
	}
	float average;
	average = 0;
	for (counter = 0; counter < (length - 2); counter++)
		average = average + array[counter];
	average = average / (length - 2);
	printf("Среднее арифметическое значение массива без минимального и максимального значения: %.1f", average);
	_getch();
	return 0;
}