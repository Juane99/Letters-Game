#include <iostream>
#include <vector>
#include <string>
#include "lista_palabras.hpp"
using namespace std;

lista_palabras::lista_palabras(){
	datos;
}

int lista_palabras::size() const{
	return datos.size();
}

void lista_palabras::aniade(string palabra){
	lista_palabras::iterator pos = end();
	datos.insert(pos,palabra);
}

vector<string> lista_palabras::palabras_longitud(int longitud){
	vector <string> a_devolver;
	lista_palabras::iterator pos;
	for (pos = begin(); pos != end(); pos++){
		if ((*pos).size() == longitud)
			a_devolver.push_back(*(pos));
	}
	return a_devolver;
}

bool lista_palabras::Esta(string palabra){
	lista_palabras::iterator it;

	it = datos.find(palabra);
	
	return (it != datos.end());

}

istream& operator>>(istream & is, lista_palabras &D){
	string s;
	is >> s;
	while(!is.eof()){	
		D.aniade(s);
		is >> s;
	}
	
	return is;
}

ostream& operator<<(ostream & os, const lista_palabras &D){

	lista_palabras::const_iterator it;

	for(it = D.begin(); it != D.end(); ++it)
		os << *it << endl;
	
	return os;
}

lista_palabras::iterator lista_palabras::begin(){
	return datos.begin();
}

lista_palabras::const_iterator lista_palabras::begin() const{
	return datos.begin();
}


lista_palabras::iterator lista_palabras::end(){
	return datos.end();
}

lista_palabras::const_iterator lista_palabras::end() const{
	return datos.end();
}

