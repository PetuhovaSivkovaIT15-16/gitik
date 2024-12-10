#include <iostream>
#include<string>
#include<ctime>
#include<iomanip>
using namespace std;
//размер игрового поля
const int n = 4;
//заполнение поле числами от 1 до 15, 0-пустая клетка
void zapolnenie(int pole[n][n], int& pstr, int& pstl)
{
	int number = 1;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (number < 16)
			{
				pole[i][j] = number;
				number++;
			}
			else
			{
				pole[i][j] = 0;
				pstr = i;
				pstl = j;
			}
		}
	}

}
//перемешивание чисел на игровом поле
void peremeshivanie(int pole[n][n], int& pstr, int& pstl)
{
	int mas[n * n - 1];
	int index = 0;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (i* n + j < n * n - 1)
				mas[index++] = pole[i][j];
		}
	}
	srand(time(0));
	for (int i = n * n - 2;i > 0;i--)
	{
		int j = rand() % (i + 1);
		if (j != i)
		{
			int dop = mas[i];
			mas[i] = mas[j];
			mas[j] = dop;
		}
	}
	index = 0;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0; j < n;j++)
		{
			if (i * n + j < n * n - 1)
				pole[i][j] = mas[index++];
			else
			{
				pole[i][j] = 0;
				pstr = i;
				pstl = j;
			}
		}
	}
}
//Перемещение плитки
bool peremechenie(int pole[n][n], int& pstr, int& pstl, int number)
{
	int rstr, rstl;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (pole[i][j] == number)
			{
				rstr = i;
				rstl = j;
				break;
			}
		}
	}
	//Проверка можно ли переместить плитку
	if ((rstr == pstr && abs(rstl - pstl) == 1) || (rstl == pstl && abs(rstr - pstr) == 1))
	{
		int dop = pole[rstr][rstl];
		pole[rstr][rstl] = pole[pstr][pstl];
		pole[pstr][pstl] = dop;
		pstr = rstr;
		pstl = rstl;
		return true;
	}
	else
		return false;
}
//вывод игрового поля
void vavod(int pole[n][n])
{
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (pole[i][j] == 0)
				cout << "   " << " ";
			else
				cout << setw(3) << pole[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int pole[n][n];
	int pstr, pstl;
	zapolnenie(pole, pstr, pstl);
	cout << "Начальное игровое поле: " << endl;
	vavod(pole);
	peremeshivanie(pole, pstr, pstl);
	cout << "Перемешанное игровое поле: " << endl;
	vavod(pole);
}