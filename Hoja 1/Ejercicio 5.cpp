#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;
void generar(int **matriz) {
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			matriz[i][j] = rand() % 101;
		}
	}
}

void mostrarmesa(int mesa) {
	switch (mesa) {
	case 0:
		cout << "Mesa 1";
		break;
	case 1: 
		cout << "Mesa 2";
		break;
	case 2:
		cout << "Mesa 3";
		break;
	case 3:
		cout << "Mesa 4";
		break;
	default:
		break;
	}
}
void mostrar(int **matriz) {
	cout << "\t\t\t\t\t\t\tCANDIDATOS\n\n";
	cout << "\t\t";
	for (int j = 0; j < 5; j++)
	{
		cout << "Candidato " << j + 1 << "\t\t";
	}
	cout << endl;
	for (int i = 0; i < 4; i++)
	{
		mostrarmesa(i);
		cout << "\t\t";
		for (int j = 0; j < 5; j++)
		{
			cout<<matriz[i][j]<<"\t\t\t";
		}
		cout << endl;
	}
}
int SumaTotalCandidato(int** matriz, int candidato) {
	int suma = 0;
	for (int i = 0; i < 4; i++) {
		suma = suma + matriz[i][candidato];
	}
	return suma;
}
int SumaVotos(int**matriz) {
	int suma1 =0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			suma1 =suma1+ matriz[i][j];
		}
	}
	return suma1;
}
int main() {
	srand(time(NULL));
	setlocale(LC_CTYPE, "spanish");
	system("MODE 130,35");
	int **matriz;
	matriz = new int*[4];
	for (int i = 0; i < 4; i++)
	{
		matriz[i] = new int[5];
	}
	generar(matriz);
	mostrar(matriz);
	cout << endl;
	float max = 0;
	int posi;
	int ganador=0;
	int posig;
	int sumita;
	float *sumato = new float[5];
	float *sumac = new float[5];
	float *pro = new float[5];
	int posmayor1, posmayor2;
	int mayor1 = pro[0], mayor2 = pro[1];
	for (int i = 0; i < 5; i++)
	{
		sumato[i] = SumaVotos(matriz);
		sumac[i] = SumaTotalCandidato(matriz, i);
		pro[i] = sumac[i] / sumato[i] * 100;
		cout << "El candidato " << i + 1 << " obtuvo: " << sumac[i]<<" votos y obtuvo un "<< pro[i]<<"%"<<endl;
		
		if (pro[i]>max)
		{
			max = pro[i];
			posi = i;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (pro[i] >= 50)
		{
			sumita = 0;
			posig = i;
		}
		else if (pro[i] < 50)
		{
			sumita = 1;
		}
		ganador += sumita;
	}
	for (int i = 0; i < 5; i++)
	{
		if (mayor1 < pro[i])
		{
			mayor1 = pro[i];
			posmayor1 = i;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (mayor2 < pro[i]&&posmayor1!=i)
		{
			mayor2 = pro[i];
			posmayor2 = i;
		}
	}
	cout << endl<<"El candidato más votado es el " << posi + 1 << " con: " << max << "%" << endl << endl;
	if (ganador<5)
	{
		cout << "El candidato ganador es el: " << posig+1 << endl << endl;
	}
	if (ganador==5)
	{
		cout << "El candidato " << posmayor1+1 << " y el candidato " << posmayor2+1 << " irán a segunda vuelta" << endl << endl;
	}
	system("pause");
}