#include "ConjuntoLetras.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
///
///@file bolsa_letras.hpp
///@brief fichero de cabecera del TDA bolsa_letras
///
///Se crea un vector con la bolsa de letras a usar en cada partida
///
#ifndef _bolsa_letras_hpp_
#define _bolsa_letras_hpp_


///
///@brief TDA bolsa_letras
///
class bolsa_letras{
    private:
 	///
  	///@brief Vector contenedor de las letras a usar
        vector<char> bolsa;

    public:
 	///
  	///@brief Constructor por parametro
	///@param cl es el ConjuntoLetras a partir del que se construye la bolsa
        bolsa_letras(ConjuntoLetras cl);
 	///
  	///@brief metodo que saca las letras aleatorias en cada partida
	///@param cantidad es el numero de letras a sacar
        vector<char> sacarLetras(int cantidad);

    private:
 	///
  	///@brief metodo que se usa en sacarLetras para que salgan de forma aleatoria
        void desordenar();

};

#endif
