#include<iostream>
using namespace std;
void ingresar_Mostrar(int **matriz, int n, int m) {
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "Ingrese el valor de la fila " << i << " y columna " << j << ": ";
			cin >> matriz[i][j];
		}
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matriz[i][j];
		}
			cout << endl;
	}
	cout << endl;
}
void suma_filas(int **matriz, int n, int m) {
	int suma;
	int min = 10000000000;
	for (int i = 0; i < n; i++)
	{
		suma = 0;
		for (int j = 0; j < m; j++)
		{
			suma += matriz[i][j];
		}
		cout << "La suma de la fila " << i << " es: " << suma << endl;
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matriz[i][j]<min)
			{
				min = matriz[i][j];
			}
		}
		cout << "El menor valor almacenado de la fila " << i << " es: " << min << endl;
		min = 10000000000;
	}
	cout << endl;
}
void prom_filas(int **matriz, int n, int m) {
	double suma1;
	double prom;
	int mayor = 0;
	for (int j = 0; j < m; j++)
	{
		suma1 = 0;
		prom = 0;
		for (int i = 0; i < n; i++)
		{
			suma1 += matriz[i][j];
			prom = suma1 / n;
		}
		cout << "El promedio de la columna " << j << " es: " << prom << endl;
	}
	cout << endl;
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (matriz[i][j]>mayor)
			{
				mayor = matriz[i][j];
			}
		}
		cout << "El mayor valor almacenado de la columna " << j << " es: " << mayor << endl;
		mayor = 0;
	}
	cout << endl;	
}
void encontrar_mayor(int **matriz, int n, int m) {
	int posif, posic;
	int mayor = matriz[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matriz[i][j]>mayor)
			{
				mayor = matriz[i][j];
				posif = i;
				posic = j;
			}
		}
	}
	cout << "El mayor valor almacenado en la matriz es: " << mayor << "\nSe encuentra en la fila: " << posif << " y columna: " << posic << endl<<endl;
}
int main() {
	int n, m;
	do
	{
		cout << "Ingrese el valor de n: ";
		cin >> n;
	} while (n<=0||n>=10);
	do
	{
		cout << "Ingrese el valor de m: ";
		cin >> m;
	} while (n<=0||m>=10);
	int**matriz;
	matriz= new int*[n];
	for (int i = 0; i < n; i++)
	{
		matriz[i] = new int[m];
	}
	ingresar_Mostrar(matriz, n, m);
	suma_filas(matriz, n, m);
	prom_filas(matriz, n, m);
	encontrar_mayor(matriz, n, m);
	system("pause");
}