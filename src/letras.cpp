#include "bolsa_letras.hpp"
#include "ConjuntoLetras.hpp"
#include "lista_palabras.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

bool caracteres_correctos(string palabra_jugador, vector<char> letras_juego){
	bool correcto = true, salir = false;

	for (int i=0; i<palabra_jugador.size() && correcto; i++){
		salir = false;
		for (int j=0; j<letras_juego.size() && !salir; j++){
			if (palabra_jugador[i] == tolower(letras_juego[j]) ){
				letras_juego.erase(letras_juego.begin() + j);
				salir=true;

			}
		}
		if (!salir)
			correcto = false;
	}

	return correcto;
}


int main(int argc, char * argv[]){
	if (argc!=5){
		cout<<"Los parametros son:"<<endl;
		cout<<"1.- El fichero con las palabras"<<endl;
		cout<<"2.- El fichero con las letras"<<endl;
		cout<<"3.- Numero de letras generadas aleatoriamente"<<endl;
		cout<<"4.- Modalidad de juego (L o P)"<<endl;
		return 0;
	}

	ifstream f_palabras(argv[1]);
	if (!f_palabras){
		cout<<"No puedo abrir el fichero de las palabras"<<argv[1]<<endl;
		return 0;
	}

	lista_palabras D;
	f_palabras >> D;

	ifstream f_letras(argv[2]);
	if (!f_letras){
		cout<<"No puedo abrir el fichero de las letras "<<argv[2]<<endl;
		return 0;
	}

	if (atoi(argv[3])<= 1 || atoi(argv[3]) > 8){
		cout<<"Debes introducir un numero valido entre 2 y 8"<<argv[1]<<endl;
		return 0;
	}

	ConjuntoLetras cl;
	f_letras >> cl;

	bolsa_letras bolsa(cl);

	vector<char>letras_juego;
	char continuar = 'S';
	while (continuar == 'S'){
		letras_juego = bolsa.sacarLetras(atoi(argv[3]));

		cout << "Las letras son: ";
		for (int i=0; i<letras_juego.size(); i++)
			cout << letras_juego[i] << " ";

		string palabra_jugador = "";

		do{
		cout << endl << "Dime tu solucion: ";
		cin >> palabra_jugador;
		}while (palabra_jugador.size() > atoi(argv[3]));

		for (int i=0; i<palabra_jugador.size(); i++)
			palabra_jugador[i] = tolower(palabra_jugador[i]);

		if (!caracteres_correctos(palabra_jugador,letras_juego)){
			cout << "Los caracteres no son correctos\t\tPuntuacion: 0" << endl;
		}
				
		//SELECCION DE MODO DE JUEGO	

		//----------------------LONGITUD------------------------------//
		if (strcmp(argv[4],"L")==0){
			string mejor_palabra = "";

			if (D.Esta(palabra_jugador))
				cout << "\n\n" << palabra_jugador << "  Puntuacion: " << palabra_jugador.size() << endl;
			else
				cout << "\n\n" << palabra_jugador << "  Puntuacion: " << 0 << endl;
				

			cout << "Mis soluciones son:" << endl;

			vector<string> soluciones_por_longitud;
				
			bool encontradas = false;
			for (int i=atoi(argv[3]) ; i > 0 && !encontradas; i--){
				soluciones_por_longitud = D.palabras_longitud(i);
				for (int j=0; j < soluciones_por_longitud.size(); j++){
					if (caracteres_correctos(soluciones_por_longitud[j],letras_juego)){
						cout << soluciones_por_longitud[j] << "  Puntuacion: " << soluciones_por_longitud[j].size() << endl;
						encontradas = true;
						mejor_palabra = soluciones_por_longitud[j];
					}
				}
			}
			cout << "La mejor solucion es:  " << mejor_palabra << endl;

		//----------------------PUNTUACION------------------------------//	
		}else{
			int puntuacion = 0, mejor_puntuacion = 0;
			string mejor_palabra = "";
			
			if (!D.Esta(palabra_jugador)){
				cout << "\n\n" << palabra_jugador << "  Puntuacion: " << 0 << endl;
			}else{

				for (int i=0; i<palabra_jugador.size(); i++){
					for (ConjuntoLetras::iterator pos = cl.begin(); pos != cl.end(); ++pos){	

						if (palabra_jugador[i] == tolower((*pos).getLetra()))
							puntuacion += (*pos).getPuntos();
						
					}
				}

				cout << "\n\n" << palabra_jugador << "  Puntuacion: " << puntuacion << endl;

			}

			cout << "Mis soluciones son:" << endl;

			vector<string> soluciones_por_puntuacion;

			for (int i=atoi(argv[3]) ; i > 0; i--){
				soluciones_por_puntuacion = D.palabras_longitud(i);
				for (int j=0; j < soluciones_por_puntuacion.size(); j++){
					puntuacion = 0;
					if (caracteres_correctos(soluciones_por_puntuacion[j],letras_juego)){

						for (int k=0; k<soluciones_por_puntuacion[j].size(); k++){

							for (ConjuntoLetras::iterator pos = cl.begin(); pos != cl.end(); ++pos){	
								
								if (soluciones_por_puntuacion[j][k] == tolower((*pos).getLetra())){
									puntuacion += (*pos).getPuntos();

								}
						
							}
						}

						cout << soluciones_por_puntuacion[j] << "  Puntuacion: " << puntuacion << endl;
				
						if (puntuacion >= mejor_puntuacion){
							mejor_palabra = soluciones_por_puntuacion[j];	
							mejor_puntuacion = puntuacion;
						}					
						
					}

				}
			}

			cout << "La mejor solucion es:  " << mejor_palabra << endl;
			
		}	

		//-------------------SEGUIR JUGANDO---------------------------//
		cout << "\n\n¿Quieres seguir jugando[S/N]?";
		do{
		cin >> continuar;
		}while (continuar != 'S' && continuar != 'N');
	}

	return 0;
}

	
