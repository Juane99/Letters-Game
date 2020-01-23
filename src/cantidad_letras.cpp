#include "lista_palabras.hpp"
#include "ConjuntoLetras.hpp"
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//					FUNCION
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void calculaCantidades(ConjuntoLetras & conjunto, lista_palabras & lista, vector<int> & cantidades, ofstream & flujo_salida){

	int ascii;
	double num_letras = 0.0;

	for(lista_palabras::iterator palabra = lista.begin(); palabra != lista.end(); ++palabra){
		for (ConjuntoLetras::iterator pos = conjunto.begin(); pos != conjunto.end(); ++pos){	

			for (int i=0; i<(*palabra).size(); i++){

				if ((*palabra)[i] == tolower((*pos).getLetra())){
					ascii = tolower((*pos).getLetra());
					cantidades[ascii]++;
					num_letras++;
				}
			}
		}
	}


	flujo_salida << "#Letra	Cantidad" << endl;


	for (ConjuntoLetras::iterator pos = conjunto.begin(); pos != conjunto.end(); ++pos){
		ascii = tolower((*pos).getLetra());
		flujo_salida << (*pos).getLetra() << '\t' << (cantidades[ascii] / num_letras)*100.0 << endl;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//					MAIN
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv){

	if (argc != 4){
		cerr << "NUMERO DE ARGUMENTOS INCORRECTO" << endl;
		exit(1);
	}

	//DECLARACIONES

	lista_palabras lista;
	ConjuntoLetras conjunto;
	ifstream flujo_letras, flujo_palabras;
	ofstream flujo_salida;
	vector<int> cantidades(123,0); //Vector que usaremos para comprobar el numero de apariciones
	

	//OPERACIONES DE FLUJO

	flujo_palabras.open(argv[1]); 

	if (!flujo_palabras){
		cerr << "No se pudo abrir el fichero " << argv[1] << endl;
		exit(1);
	}

	flujo_letras.open(argv[2]);

	if (!flujo_letras){
		cerr << "No se pudo abrir el fichero " << argv[2] << endl;
		exit(1);
	}

	flujo_salida.open(argv[3]);

	if (!flujo_salida){
		cerr << "No se pudo crear el fichero " << argv[3] << endl;
		exit(1);
	}

	//PROGRAMA PRINCIPAL

	flujo_palabras >> lista;
	flujo_letras >> conjunto;

	calculaCantidades(conjunto,lista,cantidades, flujo_salida); //Calculamos el numero de apariciones de cada letra

	flujo_salida.close();
	flujo_palabras.close();
	flujo_letras.close();

	cout << "EL FICHERO DE SALIDA HA SIDO CREADO CORRECTAMENTE" << endl;
	return(0);
}

	

	
