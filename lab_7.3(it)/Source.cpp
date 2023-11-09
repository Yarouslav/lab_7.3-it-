#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
int CountColumnsWithZero(int** a, const int rowCount, const int colCount);
void LongestSeriesRow(int** a, const int rowCount, const int colCount);

int main()
{
	srand((unsigned)time(NULL));
	int Low = -17;
	int High = 15;
	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);

	int columnsWithZero = CountColumnsWithZero(a, rowCount, colCount);
	cout << "Number of columns with at least one zero element: " << columnsWithZero << endl;

	LongestSeriesRow(a, rowCount, colCount);

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Input(int** a, const int rowCount, const int colCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
		cout << endl;
	}
}

void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

int CountColumnsWithZero(int** a, const int rowCount, const int colCount)
{
	int count = 0;
	for (int j = 0; j < colCount; j++)
	{
		for (int i = 0; i < rowCount; i++)
		{
			if (a[i][j] == 0)
			{
				count++;
				break;
			}
		}
	}
	return count;
}

void LongestSeriesRow(int** a, const int rowCount, const int colCount)
{
	int maxSeriesLength = 0;
	int maxSeriesRow = -1;

	for (int i = 0; i < rowCount; i++)
	{
		int currentLength = 1;
		for (int j = 1; j < colCount; j++)
		{
			if (a[i][j] == a[i][j - 1])
				currentLength++;
			else
				currentLength = 1;

			if (currentLength > maxSeriesLength)
			{
				maxSeriesLength = currentLength;
				maxSeriesRow = i;
			}
		}
	}

	cout << "Row with the longest series of identical elements: " << maxSeriesRow << endl;
}
