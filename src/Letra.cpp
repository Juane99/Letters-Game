#include "Letra.hpp"
#include <utility>
#include <iostream>
using namespace std;

Letra::Letra(){

	letra.first = char();
	letra.second.first = 0;
	letra.second.second = 0;
}

Letra::Letra(char la_letra, int apariciones, int puntos){
	
	letra.first = la_letra;
	letra.second.first = apariciones;
	letra.second.second = puntos;
	
}

Letra::Letra(const Letra & original){
	letra.first = original.getLetra();
	letra.second.first = original.getApariciones();
	letra.second.second = original.getPuntos();
}

char Letra::getLetra() const{
	return (letra.first);
}

int Letra::getApariciones() const{
	return (letra.second.first);
}

int Letra::getPuntos() const{

	return (letra.second.second);
}

void Letra::setLetra(char l){

	letra.first = l;
}

void Letra::setApariciones(int apariciones){

	letra.second.first = apariciones;
	
}

void Letra::setPuntos(int puntos){


	letra.second.second = puntos;
}
