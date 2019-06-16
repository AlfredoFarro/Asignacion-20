#include<iostream>
using namespace std;
void generar(int **matriz, int filas, int columnas) {
	for (int fila = 0; fila < filas; fila++)
	{
		for (int columna = 0; columna < columnas; columna++)
		{
			cout << "Ingrese el digito de la " << fila << " columna " << columna << " : ";
			cin >> matriz[fila][columna];
		}
	}
}
void mostrar(int **matriz, int filas, int columnas) {
	for (int fila = 0; fila < filas; fila++)
	{
		for (int columna = 0; columna < columnas; columna++)
		{
			if (matriz[fila][columna]<10)
			{
				cout << matriz[fila][columna] << "  ";
			}
			else
			{
				cout << matriz[fila][columna] << " ";
			}
		}
		cout << endl;
	}
}
int verificar(int **matriz, int filas, int columnas) {
	int con = 1;
	for (int fila = 0; fila < filas; fila++)
	{
		for (int columna = 0; columna < fila; columna++)
		{
			if (matriz[fila][columna] == matriz[columna][fila])
			{
				con = 1;
			}
			else 
			{
				con = 0;
				
			}
			con = con*con;
		}
	}
	return con;
}
int main() {
	setlocale(LC_CTYPE, "spanish");
	int **matriz;
	int n;
	int con;
	do
	{
	cout << "Ingrese el tamaño de la matriz: ";
	cin >> n;
	} while (n<=1);
	int filas = n, columnas = n;
	matriz = new int*[filas];
	for (int fila = 0; fila < filas; fila++)
	{
		matriz[fila] = new int[columnas];
	}
	generar(matriz, filas, columnas);
	mostrar(matriz, filas, columnas);
	cout << endl;
	verificar(matriz, filas, columnas);
	if (verificar(matriz, filas, columnas) ==1)
	{
		cout << "La matriz es simétrica" << endl << endl;
	}
	else
	{
		cout << "La matriz no es simétrica" << endl << endl;
	}
	system("pause");
}