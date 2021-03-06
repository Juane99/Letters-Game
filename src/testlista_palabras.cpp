#include "bolsa_letras.hpp"
#include "ConjuntoLetras.hpp"
#include "lista_palabras.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main(int argc, char * argv[]){
	if (argc!=2){
		cout<<"Los parametros son: "<<endl;
		cout<<"1.- El fichero con las palabras" << endl;
		return 0;
	}
	ifstream f(argv[1]);
	if (!f){
		cout<<"No puedo abrir el fichero"<<argv[1]<<endl;
		return 0;
	}
	lista_palabras D;
	cout<<"Cargando lista_palabras...."<<endl;
	f>>D;

	cout<<"Leido el lista_palabras..."<<endl;
	cout<<D;

	int longitud;
	cout<<"Dime la longitud de las palabras que quieres ver: ";
	cin>>longitud;
	vector<string> v=D.palabras_longitud(longitud);
	cout<<"Palabras de Longitud"<<longitud<<endl;
	for (unsigned int i=0;i<v.size();i++)
		cout<<v[i]<<endl;
	string p;
	cout<<"Dime una palabra: ";
	cin>>p;
	if (D.Esta(p)) cout<< "Sí, esa palabra existe" << endl;
	else cout<<"Esa palabra no existe" << endl;
}
