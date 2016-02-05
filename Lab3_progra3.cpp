#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

void Arreglar_Score(int[], int, int);
void llenar_arreglo(int[], int);

int main(int argc, char*argv[]){
	srand(time(NULL));
	int Intento_User;
	int acum_intentos = 0;
	const int SIZE = 10;
	int Score[SIZE];

	int Azar = (-501 + rand()% 501);
	cout << Azar << endl;

	cout << "Ingrese un numero: " << endl;
	cin >> Intento_User;
	acum_intentos++;

	while(Azar != Intento_User){
		if (Intento_User < Azar){
			cout << "El numero que ingresaste es menor" << endl;
			cout << "Ingrese un numero: " << endl;
			cin >> Intento_User;
		} else if (Intento_User > Azar){
			cout << "El numero que ingresaste es mayor" << endl;
			cout << "Ingrese un numero: " << endl;
			cin >> Intento_User;
		}
		acum_intentos++;
	}

	cout << "Felicidades, has adivinado el numero en: " << acum_intentos << " intentos" << endl;
	llenar_arreglo(Score, SIZE);
	Arreglar_Score(Score, SIZE, acum_intentos);
	for (int i = 0; i < SIZE; i++){
		cout << Score[i] << endl;
	}

	return 0;
}

void llenar_arreglo(int Score[], int SIZE){
	for (int i = 0; i < SIZE; i++){
		Score[i] = 0;
	}
}

void Arreglar_Score(int Score[], int SIZE, int acum_intentos){
	for (int i = 0; i < SIZE; i++){
		if (acum_intentos > Score[i]){
			int mayor = acum_intentos;
			acum_intentos = Score[i + 1];
			Score[i] = mayor;
		}
	}
}