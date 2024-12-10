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
int main()
{
	setlocale(LC_ALL, "Russian");
	int pole[n][n];
	int pstr, pstl;
	zapolnenie(pole, pstr, pstl);
}