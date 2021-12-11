#include <iostream>
#include <iomanip>
#include <iostream>
#include <iomanip>
#include <clocale>
#include <time.h>

using namespace std;

// заполнение матрицы случайными значениями
void FillMatrix(int* matrix, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			matrix[i * m + j] = rand() % (15 - 11) / 2;
	}
}

// вывод матрицы
void PrintMatrix(int* matrix, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << setw(4) << matrix[i * m + j] << " ";
		cout << endl;
	}
}
void Zero(int* matrix, int n, int m) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + j < m) {
				if (matrix[i * m + j] == 0) {
					count++;
				}
			}
		}
	}
	cout << endl << " Количество нулей  области = " << count << endl;
}



int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int n, m;
	cout << "Ввести размер строк от 1 до 99: ";
Input:
	cin >> n;
	if (!cin || n > 99 || n < 0)
	{
		cout << "Неверный ввод!Повторите" << endl;
		cin.clear();
		while (cin.get() != '\n');
		goto Input;
	}

	cout << "Ввести размер строк от 1 до 99: ";
Input1:
	cin >> m;
	if (!cin || m > 99 || m < 0)
	{
		cout << "Неверный ввод!Повторите" << endl;
		cin.clear();
		while (cin.get() != '\n');
		goto Input1;
	}
	int* matrix = new int[n * m]; // выделяем память под матрицу
	FillMatrix(matrix, n, m); // генерируем матрицу
	cout << "Массив:" << endl;
	PrintMatrix(matrix, n, m); // выводим матрицу
	Zero(matrix, n, m);
	system("pause");
	return(0);
}
