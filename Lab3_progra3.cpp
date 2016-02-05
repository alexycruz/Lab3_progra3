#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setw;

void Arreglar_Score(int[], int, int);
void llenar_arreglo(int[], int);

int main(int argc, char*argv[]){
	srand(time(NULL));
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
	
		 if (opcion == 1){
		 		int Opcion_juego1 = 1;

		 		while(Opcion_juego1 == 1){
					int Intento_User;
					int acum_intentos = 0;

					int Azar = (rand()% 100 - 500);
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
		 		int Row = 4;
		 		int Col = 3;
		 		int Matriz[Row][Col];
		 		int J1_Ataque, J1_Defensa, J1_Velocidad, J2_Ataque, J2_Defensa, J2_Velocidad;

		 		for (int i = 0; i < Row; i++){
		 			for (int j = 0; j < Col; j++){
		 				if (j == 0){
		 					int Azar = rand()% 30 + 85;
		 					Matriz[i][j] = Azar;
		 				}else if (j == 1){
		 					int Azar = rand()% 25 + 50;
		 					Matriz[i][j] = Azar;
		 				}else if (j == 2){
		 					int Azar = rand()% 50 + 150;
		 					Matriz[i][j] = Azar;
		 				}
		 			}
		 		}

		 		cout << "        Ataque      Defensa      Velocidad" << endl;   
		 		for (int i = 0; i < Row; i++){
		 			for (int j = 0; j < Col; j++){
		 				cout << setw(12) << Matriz[i][j];
		 			}
		 			cout << endl;
		 		}

		 		cout << endl;

		 		for (int i = 0; i < 2; i++){
		 			int Asignar_valores = (1 + rand()% 3);
		 			int temp = Matriz[Asignar_valores][0];
		 			if (i == 0){
		 				J1_Ataque = temp;
		 			}else{
		 				J2_Ataque = temp;
		 			}
		 		}


		 		for (int i = 0; i < 2; i++){
		 			int Asignar_valores = (1 + rand()% 3);
		 			int temp = Matriz[Asignar_valores][1];
		 			if (i == 0){
		 				J1_Defensa = temp;
		 			}else{
		 				J2_Defensa = temp;
		 			}
		 		}

		 		for (int i = 0; i < 2; i++){
		 			int Asignar_valores = (1 + rand()% 3);
		 			int temp = Matriz[Asignar_valores][2];
		 			if (i == 0){
		 				J1_Velocidad = temp;
		 			}else{
		 				J2_Velocidad = temp;
		 			}
		 		}

		 		cout << endl;
		 		cout << "El ataque del jugador 1 es: " << J1_Ataque << endl;
		 		cout << "El ataque del jugador 2 es: " << J2_Ataque << endl;
		 		cout << "La defensa del jugador 1 es: " << J1_Defensa << endl;
				cout << "La defensa del jugador 2 es: " << J2_Defensa << endl;
		 		cout << "La velocidad del jugador 1 es: " << J1_Velocidad << endl;
		 		cout << "La velocidad del jugador 2 es: " << J2_Velocidad << endl;
		 		cout << endl;

		 		int valor1 = J1_Ataque - J2_Defensa;
		 		int valor2 = J2_Ataque - J1_Defensa;
		 		if (valor1 > valor2){
		 			cout << "El jugador 1 ha ganado" << endl;
		 		}else if (valor1 < valor2){
		 			cout << "El jugador 2 ha ganado" << endl;
		 		}else if (valor1 == valor2){
		 			if (J1_Velocidad > J2_Velocidad){
		 				cout << "El jugador 1 ha ganado por velocidad" << endl;
		 			}else if (J1_Velocidad < J2_Velocidad){
		 				cout << "El jugador 2 ha ganado por velocidad" << endl;
		 			}else if (J1_Velocidad == J2_Velocidad){
		 				cout << "Ha habido un empate por velodidad" << endl;
		 			}
		 		}
		 	}
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