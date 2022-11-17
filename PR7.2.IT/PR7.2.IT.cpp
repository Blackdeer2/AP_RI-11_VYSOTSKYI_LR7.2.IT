#include <iostream>
#include <iomanip>
using namespace std;

void Create(int** mas, const int rowCount, int  colCount, int A, int B) {

	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			mas[i][j] = A + rand() % (B - A + 1);
		}
	}
}
void Print(int** mas, const int rowCount, int  colCount) {

	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			cout << setw(4) << mas[i][j];
		}
		cout << endl;
	}
}

void Trans(int** mas, const int rowCount, const int  colCount, int& test) {
	int t = 0;
	for (int i = 0; i < colCount; i++) {
		for (int j = i + 1; j < colCount; j++) {
			t = mas[i][j];
			mas[i][j] = mas[j][i];
			mas[j][i] = t;
			test = mas[j][i];
		}
	}
}
int main()
{
	srand((unsigned)time(NULL));

	int n;
	cout << "n = "; cin >> n;
	int rowCount = n;
	int colCount = rowCount;

	int** T = new int* [rowCount];
	for (int i = 0; i < rowCount; i++) {
		T[i] = new int[colCount];
	}
	Create(T, rowCount, colCount, -17, 14);
	cout << "T =" << endl << "{ " << endl;
	Print(T, rowCount, colCount);
	cout << "             }" << endl;
	int test = 0;
	Trans(T, rowCount, colCount, test);
	cout << "transponovane T = { " << endl;
	Print(T, rowCount, colCount);
	cout << "    }" << endl;
	cout << "test =" << test;
	for (int i = 0; i < rowCount; i++)
		delete[]T[i];
	delete[]T;

	return 0;
}