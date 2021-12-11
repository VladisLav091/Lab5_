#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <clocale>
#include <iostream>
#include <ctype.h>
#include <string.h>
#include <iomanip>
#define N 2     // количество динамических строк
using namespace std;

void vvod(char **p) //функция для ввода строк
{
	char *string;
	cout << "Введите две строки на латинице, содержащие несколько слов. Максимально в одной строке 80 символов." << endl;
	string = new char[256];
	int k;
	for (k = 0; k < 2; k++)
	{
		setlocale(0, "Russian");
		while (1) {
			cin.getline(string, 256);
			if (strlen(string) > 80)
				cout << "Ошибка! Вы ввели более 80 символов. Повторите ввод" << endl;
			else
				break;
		}

		p[k] = (char*)malloc(strlen(string) + 1);
		strcpy_s(p[k], strlen(string) + 1, string);
	}
	cout << "-----------------------------" << endl;
}

void deldigit1(char **p) //функция для удаления цифр из строки
{
	setlocale(0, "Russian");
	int k;
	char* pstr1;
	char* pstr2;
	pstr1 = p[0];
	pstr2 = p[1];
	cout << "Длина строки 1: " << strlen(pstr1) << endl;
	cout << "Длина строки 2: " << strlen(pstr2) << endl;
	if (strlen(pstr1) < strlen(pstr2)) {
		cout << "Изменённая вторая строка: ";
		for (k = 0; k < strlen(pstr2); k++)
			if (!isdigit(pstr2[k]))
				cout << pstr2[k];
		cout << endl;
		cout << "Изменённая первая строка: ";
		for (k = 0; k < strlen(pstr1); k++)
			if (!isdigit(pstr1[k]))
				cout << pstr1[k];
		cout << endl;
	}
	else
	{
		cout << "Изменённая первая строка: ";
		for (k = 0; k < strlen(pstr1); k++)
			if (!isdigit(pstr1[k]))
				cout << pstr1[k];
		cout << "Изменённая вторая строка: ";
		for (k = 0; k < strlen(pstr2); k++)
			if (!isdigit(pstr2[k]))
				cout << pstr2[k];
		cout << endl;
	}

}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	cout << "Функция для удаления цифр из строки." << endl;
	char **dpt;
	dpt = (char**)malloc(sizeof(*dpt)*N);
	vvod(dpt);
	deldigit1(dpt);
	system("pause");
	return 0;
}