#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <conio.h>

using namespace std;

const int ROWS = 9;
const int COLUMNS = 9;
int arr[ROWS][COLUMNS];
int duplicate[ROWS][COLUMNS];
int rem = 0;

bool validPosition(int a[][9], int, int, int);
void displayGame();

int main()
{
	srand(time(0));
	int n;
	bool a1, a2, a3, a4, a5, a6, a7, a8, a9;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			a1 = false, a2 = false, a3 = false, a4 = false, a5 = false, a6 = false, a7 = false, a8 = false, a9 = false;
			do
			{
				n = rand() % 9 + 1;
				if (n == 1)
					a1 = true;
				else if (n == 2)
					a2 = true;
				else if (n == 3)
					a3 = true;
				else if (n == 4)
					a4 = true;
				else if (n == 5)
					a5 = true;
				else if (n == 6)
					a6 = true;
				else if (n == 7)
					a7 = true;
				else if (n == 8)
					a8 = true;
				else if (n == 9)
					a9 = true;
				if (!validPosition(arr, i, j, n) && a1 == true && a2 == true && a3 == true && a4 == true && a5 == true && a6 == true && a7 == true && a8 == true && a9 == true)
				{
					n = 0;
					break;
				}
			} while (!validPosition(arr, i, j, n));
			arr[i][j] = n;
			if (arr[i][j] == 0)
			{
				for (int k = 0; k < 9; k++)
				{
					for (int l = 0; l < 9; l++)
						arr[l][k] = 0;
				}
				i = -1;
				break;
			}
		}
	}

    for (int i = 0; i < 9; i++) 
	{
		for (int j = 0; j < 9; j++) 
		{
			int space = rand() % 2;
			if (space == 1)
			{
				duplicate[i][j] = arr[i][j];
			}
			else if (space == 0)
			{
				rem += 1;
				duplicate[i][j] = 0;
			}
		}
	}

	displayGame();
	system("cls");
	displayGame();

	int row, column, number;
	char r, c, no;
	while (rem > 0) 
	{
		cout << "\033[33m" << "Row = ";
		do {
			r = _getch();
		} while (!(r >= '1' && r <= '9') && cout << "\033[33m" << "\rRow = ");
		row = (int)r - 49;
		cout << "\rRow = " << r;
		cout << endl;
		cout << "\033[33m" << "Column = ";
		do {
			c = _getch();
		} while (!(c >= 'A' && c <= 'I') && cout << "\033[33m" << "\rColumn = ");
		column = (int)c - 65;
		cout << "\rColumn = " << c;
		cout << endl;
		if (duplicate[row][column] == 0)
		{
			cout << "\033[36m" << "Number = ";
			do
			{
				no = _getch();
				number = (int)no - 48;
			} while (number != arr[row][column] && cout << "\033[36m" << "\rNumber = ");
			cout << "\rNumber = " << number << endl;
			rem -= 1;
			duplicate[row][column] = number;
			system("cls");
			displayGame();
		}
		else
		{
			cout << "\033[31m" << "In this index you would not be able to enter, try different row or column\n";
		}
	}
    
	system("pause");
	return 0;
}

bool validPosition(int a[][9], int r, int c, int no)
{
	int sr = r - r % 3;
	int sc = c - c % 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (no == a[i + sr][j + sc])
				return false;
		}
	}
	for (int m = 0; m < 9; m++)
	{
		if (no == a[r][m])
			return false;
	}
	for (int m = 0; m < 9; m++)
	{
		if (no == a[m][c])
			return false;
	}
	return true;
}

void displayGame()
{
	cout << "\033[36m" << "------------------------------------------\n";
	cout << "\033[36m" << "|" << setw(25) << "SUDUKO GAME" << setw(17) << "|\n";
	cout << "\033[36m" << "------------------------------------------\n\n";
	cout << "\033[31m" << setw(34) << "c c c     c c c     c c c\n";
	cout << "\033[31m" << setw(34) << "A B C     D E F     G H I\n";
	cout << "\033[35m" << setw(35) << "==========================\n\n";
	for (int i = 0; i < 9; i++)
	{
		if (i == 3 || i == 6)
			cout << "\033[33m" << setw(35) << "--------------------------\n";
		cout << "\033[31m" << setw(4) << "r" << i + 1 << "\033[35m" << "|  ";
		for (int j = 0; j < 9; j++)
		{
			if (j == 3 || j == 6)
				cout << "\033[33m" << " |  ";
			if (duplicate[i][j] == 0)
				cout << "\033[37m" << ". ";
			else
				cout << "\033[32m" << duplicate[i][j] << " ";
		}
		cout << "\n";
	}
	cout << endl;
}