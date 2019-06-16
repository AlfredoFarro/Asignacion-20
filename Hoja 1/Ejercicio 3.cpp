#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
void generar(int **matriz, int m, int n) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matriz[i][j] = rand() % 10+1;
		}
	}
}
void mostrar(int **matriz, int m, int n) {
	cout << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matriz[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
void mostrar1(int**matriz, int m, int n) {
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < m; i++)
		{
			cout << matriz[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
int main() {
	srand(time(NULL));
	int m, n;
	do
	{
		cout << "Ingrese m: ";
		cin >> m;
	} while (m<=0||m>=10);
	do
	{
		cout << "Ingrese n: ";
		cin >> n;
	} while (n<=0||n>=10);
	int **matriz;
	matriz = new int*[m];
	for (int i = 0; i < m; i++)
	{
		matriz[i] = new int[n];
	}
	generar(matriz, m, n);
	mostrar(matriz, m, n);
	mostrar1(matriz, m, n);
	system("pause");
}