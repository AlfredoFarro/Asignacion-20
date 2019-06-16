#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <time.h>

using namespace System;
using namespace std;


void GenerarValoresMatriz(int** matriz, int& filas, int& columnas) {
	srand(time(NULL));
	for (int fila = 0; fila < filas; fila++) {
		for (int columna = 0; columna < columnas; columna++) {
			matriz[fila][columna] = rand() % 10 + 1;
		}
	}
}

void MostrarMatriz(int** matriz, int& filas, int& columnas) {

	for (int fila = 0; fila < filas; fila++) {
		for (int columna = 0; columna < columnas; columna++) {
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

void IniciarMatrizCeroInt(int** matriz, int& filas, int&columnas) {
	for (int fila = 0; fila < filas; fila++) {
		for (int columna = 0; columna < columnas; columna++) {
			matriz[fila][columna] = 0;
		}
	}
}

void GenerarTrianguloIngerior(int** matriz, int& filas, int& columnas, int** trianguloInferior) {
	for (int fila = 1; fila < filas; fila++) {
		for (int columna = 0; columna < fila; columna++) {
			trianguloInferior[fila][columna] = matriz[fila][columna] + matriz[columna][fila];
		}
	}
}

int main()
{
	int** matriz;
	int** trinaguloInferior;
	int n;
	do
	{
		cout << "Ingrese n: ";
		cin >> n;
	} while (n<2||n>50);
	cout << endl;
	int filas = n;
	int columnas = n;
	matriz = new int*[filas];
	for (int fila = 0; fila < filas; fila++)
		matriz[fila] = new int[columnas];

	trinaguloInferior = new int*[filas];
	for (int fila = 0; fila < filas; fila++)
		trinaguloInferior[fila] = new int[columnas];


	GenerarValoresMatriz(matriz, filas, columnas);
	cout << "Matriz inicial: " << endl << endl;
	MostrarMatriz(matriz, filas, columnas);

	IniciarMatrizCeroInt(trinaguloInferior, filas, columnas);

	GenerarTrianguloIngerior(matriz, filas, columnas, trinaguloInferior);

	cout << endl;
	cout << "Matriz resultante: " << endl << endl;
	MostrarMatriz(trinaguloInferior, filas, columnas);

	_getch();
	return 0;
}