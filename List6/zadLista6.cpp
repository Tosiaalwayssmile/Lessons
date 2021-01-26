// autor: Paweł Gronowski 210195

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <limits>

#define ARRAY_SIZE 5

using namespace std;

int** allocMatrix(int rows, int cols)
{
	int** mat = new int*[rows];
	for (int i = 0; i < rows; i++)
		mat[i] = new int[cols];

	return mat;
}

void deleteMatrix(int rows, int** mat)
{
	for (int i = 0; i < rows; i++)
		delete[] mat[i];
	delete[] mat;
}

void draw(int** a, int m, int n, int min, int max)
{
	for (int r = 0; r < m; r++)
		for (int c = 0; c < n; c++)
		{
			a[r][c] = (rand() % (max - min + 1)) + min;
		}
}

void wypisz(int** mat, int m, int n)
{
	cout << setw(4) << " " << " ";
	for (int i = 0; i < n; i++)
		cout << setw(4) << i << " ";
	cout << endl;

	cout << setw(4) << " " << " ";
	for (int i = 0; i < n; i++)
		cout << setw(5) << setfill('=') << "=";
	cout << setfill(' ') << endl;

	for (int r = 0; r < m; r++)
	{
		cout << setw(4) << r << "|";
		for (int c = 0; c < n; c++)
		{
			cout << setw(4) << mat[r][c] << " ";
		}
		cout << setw(1) << endl;
	}
}

int sumUnderDiagonal(int** mat, int rows, int cols)
{
	int sum = 0;
	for (int y = 0; y < cols; y++)
	{
		for (int x = y + 1; x < rows; x++)
		{
			sum += mat[x][y];
		}
	}

	return sum;
}


void sortArray(int* t, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 1; j < n - i; j++)
		{
			if (t[j] > t[j - 1])
				std::swap(t[j], t[j - 1]);
		}
}

void sortMatrix(int** Y, int rows, int cols)
{
	for (int r = 0; r < rows; r++)
	{
		sortArray(Y[r], cols);
	}
}

int** createC(int** X, int rows, int cols)
{
	int** C = allocMatrix(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int minXik = X[i][0];
			for (int c = 1; c < cols; c++)
				if (X[i][c] < minXik)
					minXik = X[i][c];

			int minXpj = X[0][j];
			for (int c = 1; c < rows; c++)
				if (X[c][j] < minXpj)
					minXpj = X[c][j];

			C[i][j] = minXik * minXpj;
		}
	}

	return C;
}

#include <cassert>

void unittest()
{
	int r0[] = { -3, -2, 5 };
	int r1[] = { 3,  4, 0 };
	int r2[] = { -1, 1, 5 };

	int* mat[3] =
	{
		&r0[0],
		&r1[0],
		&r2[0]
	};

	int sum = sumUnderDiagonal(mat, 3, 3);
	assert(sum == 3 + 1 - 1);

	int** C = createC(mat, 3, 3);
	assert(C[0][0] == -3 * -3);
	assert(C[0][1] == -3 * -2);
	assert(C[0][2] == -3 * 0);

	assert(C[1][0] == 0 * -3);
	assert(C[1][1] == 0 * -2);
	assert(C[1][2] == 0 * 0);

	assert(C[2][0] == -1 * -3);
	assert(C[2][1] == -1 * -2);
	assert(C[2][2] == -1 * 0);

	sortMatrix(mat, 3, 3);

	assert(mat[0][0] == 5);
	assert(mat[0][1] == -2);
	assert(mat[0][2] == -3);

	assert(mat[1][0] == 4);
	assert(mat[1][1] == 3);
	assert(mat[1][2] == 0);

	assert(mat[2][0] == 5);
	assert(mat[2][1] == 1);
	assert(mat[2][2] == -1);

	delete[] C;
}

void zad1()
{
	const int rows = ARRAY_SIZE;
	const int cols = ARRAY_SIZE;

	int** X = allocMatrix(rows, cols);
	int** Y = allocMatrix(rows, cols);

	draw(X, rows, cols, -5, 5);
	draw(Y, rows, cols, -5, 5);

	cout << "Tablica X:\n";
	wypisz(X, rows, cols);
	cout << "\n\nTablica Y:\n";
	wypisz(Y, rows, cols);

	int xsum = sumUnderDiagonal(X, rows, cols);
	int ysum = sumUnderDiagonal(Y, rows, cols);

	cout << "\nSuma elementow lezacych pod przekatna tablicy X wynosi: " << xsum << endl;
	cout << "Suma elementow lezacych pod przekatna tablicy Y wynosi: " << ysum << endl;

	int** C = createC(X, rows, cols);

	cout << "\n\nTablica C:\n";
	wypisz(C, rows, cols);

	sortMatrix(Y, rows, cols);
	cout << "\n\nPosortowana malejaco tablica Y:\n";
	wypisz(Y, rows, cols);

	deleteMatrix(rows, C);
	deleteMatrix(rows, X);
	deleteMatrix(rows, Y);
}


int main()
{
	srand(time(NULL));

	unittest();

	string powtorz;
	do
	{
		zad1();

		cout << "Powtorzyc? (t/n): ";
		cin >> powtorz;
	} while (powtorz == "t");

	return 0;
}

