/*
Елоев Георгий Александрович
Лабораторная работа №3
Вариант №1
Задание: Написать программу, которая во вводимом с клавиатуры тексте
заменит все окончания слов «ть» на «ся» и выведет результат на экран.
*/

  

#include <stdio.h>
#include <conio.h>
#include <locale>

#define MAX_LENGTH 1024
#define SYMBOL '!',' ',';','.',',','?',':','-',')','}',']','"'

int replacement(char *text);

int main()
{
	system("chcp 1251");
	system("cls");
	char text[MAX_LENGTH];
	printf("\tВведите ваш текст:\n");
	fgets(text, MAX_LENGTH, stdin);
	replacement(text);
	printf("\tИзменённый текст:\n");
	printf("%s", text);
	_getch();
	return 0;
}

int replacement(char *text)
{
	for (int i = 2; text[i] != '\0'; i++)
	{
		if ((text[i] == SYMBOL || text[i] == '\n') && text[i - 1] == 'ь' && text[i - 2] == 'т')
		{
			text[i - 1] = 'я';
			text[i - 2] = 'с';
		}
	}
	return 0;
} 