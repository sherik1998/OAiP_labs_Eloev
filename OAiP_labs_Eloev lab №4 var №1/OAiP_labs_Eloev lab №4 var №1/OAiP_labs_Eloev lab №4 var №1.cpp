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


void checkFile(FILE *File);//проверка нахождения файла
int getNumberOfCharacters(FILE *File);//счет количества символов в файле
void readFileInArray(int length,char *text, FILE *SourceFile);//запись символов из файла в массив
void replacement(char *text);//смена ть на ся в конце слов
void writeFile(FILE *File, int length, char *text);//Запись в файл 

int main()
{
	system("chcp 1251");
	system("cls");
	FILE *File = fopen("Text #1.txt", "r");
	checkFile(File);
	FILE *NewFile = fopen("Text #2.txt", "w");
	char text[MAX_LENGTH];
	int length;
	length = getNumberOfCharacters(File);
	fclose(File);
	FILE *SourceFile = fopen("Text #1.txt", "r");
	readFileInArray(length,text, SourceFile);
	replacement(text);
	writeFile(NewFile, length, text);
	fclose(NewFile);
	fclose(SourceFile);
	return 0;
}

void checkFile(FILE *File)
{
	if (File == NULL) {
		printf("Ошибка.Файл не найден!\n");
		printf("Создаём файл!\nПожадуста заполните его!\nИ перезапустите программу!");
		FILE *New = fopen("Text #1.txt", "w");
		fclose(New);
		_getch();
		exit(0);
	}
}

int getNumberOfCharacters(FILE *SourceFile)
{
	int length = 0;
	while (fgetc(SourceFile) != EOF)
	{
		length = length + 1;
	}
	return length;
}

void readFileInArray(int length,char *text, FILE *SourceFile)
{
	for (int i = 0; i < length; i++)
	{
		text[i] = fgetc(SourceFile);
	}
}

void replacement(char *text)
{
	for (int i = 2; text[i] != '\0'; i++)
	{
		if ((text[i] == SYMBOL || text[i] == '\n') && text[i - 1] == 'ь' && text[i - 2] == 'т')
		{
			text[i - 1] = 'я';
			text[i - 2] = 'с';
		}
	}
}

void writeFile(FILE *File, int length, char *text) 
{
	for (int i = 0; i < length; i++) // запись массива в файл
	{
		fprintf(File, "%c", text[i]);
	}
}