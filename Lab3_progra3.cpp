#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

void Arreglar_Score(int[], int, int);
void llenar_arreglo(int[], int);

int main(int argc, char*argv[]){
	int opcion;
	const int SIZE = 10;
	int Score[SIZE];
	llenar_arreglo(Score, SIZE);

	cout << "1.- Ejercicio 1" << endl
		 << "2.- Ejercicio 2" << endl
		 << "3.- Salir" << endl
		 << "Ingrese el ejercicio al que desea ingresar: ";
		 cin >> opcion;
		 cout << endl;

	while(opcion != 3){
	
		 if (opcion == 1){
		 		int Opcion_juego1 = 1;

		 		while(Opcion_juego1 == 1){
		 			srand(time(NULL));
					int Intento_User;
					int acum_intentos = 0;

					int Azar = (-501 + rand()% 501);
					cout << Azar << endl;

					cout << "Ingrese un numero: " << endl;
					cin >> Intento_User;
					acum_intentos++;
					cout << endl;

					while(Azar != Intento_User){
						if (Intento_User < Azar){
							cout << "El numero que ingresaste es menor" << endl;
							cout << "Ingrese un numero: " << endl;
							cin >> Intento_User;
							cout << endl;
						} else if (Intento_User > Azar){
							cout << "El numero que ingresaste es mayor" << endl;
							cout << "Ingrese un numero: " << endl;
							cin >> Intento_User;
							cout << endl;
						}
						acum_intentos++;
					}

					cout << "Felicidades, has adivinado el numero en: " << acum_intentos << " intentos" << endl;
					Arreglar_Score(Score, SIZE, acum_intentos);
					cout << endl;
					cout << "La tabla de score es: " << endl;
					for (int i = SIZE - 1; i > -1; i--){
						cout << Score[i] << endl;
					}	

		 			cout << "1.- Seguir jugando" << endl;
		 			cout << "2.- Salir" << endl;
		 			cout << "Ingrese una opcion: " << endl;
		 			cin >> Opcion_juego1;
		 			cout << endl;
		 		}
		 	}

		 	if (opcion == 2){
		 		
		 	}

	cout << "1.- Ejercicio 1" << endl
		 << "2.- Ejercicio 2" << endl
		 << "3.- Salir" << endl
		 << "Ingrese el ejercicio al que desea ingresar: ";
		 cin >> opcion;	 		
		 cout << endl;
	}//fin del while
}

void llenar_arreglo(int Score[], int SIZE){
	for (int i = 0; i < SIZE; i++){
		Score[i] = 0;
	}
}

void Arreglar_Score(int Score[], int SIZE, int acum_intentos){
	if (acum_intentos > Score[9]){
		Score[9] = acum_intentos;
	}

	for (int i = SIZE - 1; i > 0; i--){
		if (Score[i] > Score[i -1]){
			int mayor = Score[i];
			Score[i] = Score[i - 1];
			Score[i - 1] = mayor;
		}
	}

}