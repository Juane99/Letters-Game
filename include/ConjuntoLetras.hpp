#include<utility>
#include<iostream>
#include "Letra.hpp"
#include<set>
using namespace std;
///
///@file ConjuntoLetras.hpp
///@brief fichero de cabecera del TDA ConjuntoLetras
///
///Se crea un set con el conjunto de letras
///
#ifndef _CONJUNTOLETRAS_HPP_
#define _CONJUNTOLETRAS_HPP_

///
///@brief functor para definir el orden del set
class orden{
public:
	///
	///@brief sobrecarga del operador () tipica de los functor
	///@param l1 es la primera letra a comparar
	///@param l2 es la segunda letra a comparar
	bool operator() (const Letra & l1, const Letra & l2);

};


///
///@brief TDA ConjuntoLetras
///
class ConjuntoLetras{
private:
	///
	///@brief conjunto es el conjunto de letras
	set<Letra, orden> conjunto;

public:	
  ///
  ///@brief typedef que se utiliza para usar iteradores
  typedef typename set<Letra,orden>::iterator iterator;
  ///Constructores
  ///
  ///@brief Constructor por defecto
  ConjuntoLetras();
  ///
  ///@brief Constructor por parametros
  ///@param otro es el set de letras a usar
  ConjuntoLetras(set<Letra,orden> otro);
  ///
  ///@brief Constructor por copia
  ///@param original es el ConjuntoLetras del que se hace copia
  ConjuntoLetras(const ConjuntoLetras & original);
  //Otros métodos
  ///
  ///@brief Obtener tamanio del conjunto
  int size() const;
  ///
  ///@brief Obtener el set de letras
  set<Letra,orden> getConjunto() const;
  ///
  ///@brief Cambiar el set en cuestion
  ///@param a_cambiar es el set de letras a cambiar
  void setConjunto(set<Letra,orden> a_cambiar);
  ///
  ///@brief Sobrecarga del operador de lectura de flujo
  ///@param in es el flujo de entrada
  ///@param c es el conjunto a introducir con el operador >>
  friend istream & operator >> (istream &in, ConjuntoLetras & c);
  ///
  ///@brief Sobrecarga del operador de escritura de flujo
  ///@param out es el flujo de salida
  ///@param c es el conjunto a imprimir con el operador <<
  friend ostream & operator << (ostream &out, const ConjuntoLetras & c);
  ///
  ///@brief Iterador no constante end()
  iterator end();
  ///
  ///@brief Iterador no constante begin()
  iterator begin();

};
#endif
 
