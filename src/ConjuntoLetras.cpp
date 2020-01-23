#include "ConjuntoLetras.hpp"
#include "Letra.hpp"
#include <set>
#include <iostream>
using namespace std;

bool orden::operator() (const Letra & l1, const Letra & l2){
		
	return l1.getLetra() < l2.getLetra();
}


ConjuntoLetras::ConjuntoLetras(){

	conjunto;
}

ConjuntoLetras::ConjuntoLetras(set<Letra,orden> otro){
	
	conjunto = otro;	
}

ConjuntoLetras::ConjuntoLetras(const ConjuntoLetras & original){

	conjunto = original.conjunto;
}


int ConjuntoLetras::size() const{
	return (conjunto.size());
}

set<Letra,orden> ConjuntoLetras::getConjunto() const{

	return (conjunto);
}

void ConjuntoLetras::setConjunto(set<Letra,orden> a_cambiar){

	conjunto = a_cambiar;
}


istream & operator >> (istream &in, ConjuntoLetras & c){
	
	string cadena;
	char caracter;
	int cantidad, puntos;

	ConjuntoLetras::iterator pos = c.conjunto.end();

	getline(in,cadena,'\n'); //La cadena inicial


	while (!in.eof()){
		in >> caracter;		

		in >> cantidad >> puntos;

		Letra nueva_letra;

		nueva_letra.setLetra(caracter);
		nueva_letra.setApariciones(cantidad);
		nueva_letra.setPuntos(puntos);

		c.conjunto.insert(pos, nueva_letra);
	}

}





ostream & operator << (ostream &out, const ConjuntoLetras & c){

	out << "#Letra Cantidad Puntos" << endl;
	
	ConjuntoLetras::iterator pos;
	
	for (pos = c.conjunto.begin(); pos != c.conjunto.end(); ++pos)
		out << (*pos).getLetra() << '\t' << (*pos).getApariciones() << '\t' << (*pos).getPuntos() << endl;

}


ConjuntoLetras::iterator ConjuntoLetras::end(){

	return conjunto.end();
}

ConjuntoLetras::iterator ConjuntoLetras::begin(){

	return conjunto.begin();
}

