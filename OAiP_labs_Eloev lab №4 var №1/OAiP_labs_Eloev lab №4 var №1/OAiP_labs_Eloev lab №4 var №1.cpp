/*
	Елоев Георгий Александрович
	Лабораторная работа №4
	Вариант №1
	Задание: Написать программу, которая в данных из файла заменяет
	все окончания слов «ть» на «ся» и записывает в другой файл.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <locale>

#define MAX_LENGTH 1024
#define SYMBOL '!',' ',';','.',',','?',':','-',')','}',']','"'


int checkfile(FILE *File);//проверка нахождения файла
int thenumberofcharacters(FILE *File);//счет количества символов в файле
int fileintoanarray(int stop,char *text, FILE *SourceFile);//запись символов из файла в массив
int replacement(char *text);//смена ть на ся в конце слов

int main()
{
	system("chcp 1251");
	system("cls");
	FILE *File = fopen("Text #1.txt", "r");
	checkfile(File);
	FILE *NewFile = fopen("Text #2.txt", "w");
	char text[MAX_LENGTH];
	int stop;
	stop = thenumberofcharacters(File);
	fclose(File);
	FILE *SourceFile = fopen("Text #1.txt", "r");
	checkfile(SourceFile);
	fileintoanarray(stop,text, SourceFile);
	replacement(text);
	for (int i = 0; i < stop; i++) // запись массива в файл
	{
		fprintf(NewFile, "%c", text[i]);
	}
	fclose(NewFile);
	fclose(SourceFile);
	return 0;
}

int checkfile(FILE *File)
{
	if (File == NULL) {
		printf("Ошибка.Файл не найден!");
		_getch();
		exit(0);
	}

}
int thenumberofcharacters(FILE *SourceFile)
{
	int stop = 0;
	for (int i = 0; fgetc(SourceFile) != EOF ;i++)
		stop = stop + 1;
	return stop;
}

int fileintoanarray(int stop,char *text, FILE *SourceFile)
{
	for (int i = 0; i < stop; i++)
	{
		text[i] = fgetc(SourceFile);
	}
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