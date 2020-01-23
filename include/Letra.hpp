#include<utility>
using namespace std;
///
///@file Letra.hpp
///@brief fichero de cabecera del TDA Letra
///
///Se crea un pair con los elementos de las Letra
///
#ifndef _LETRAS_HPP_
#define _LETRAS_HPP_
///
///@brief TDA Letra
///
class Letra{
private:
	///
	///@brief letra es un pair que guarda la informacion de una letra
	pair<char, pair<int, int> > letra;

public:

  //Constructores
  ///
  ///@brief Constructor por defecto
  Letra();
  ///
  ///@brief Constructor por parametros
  ///@param letra indica la letra en cuestion
  ///@param apariciones indica el numero de aparaciciones de la letra
  ///@param puntos indica el numero de puntos de la letra
  Letra(char letra, int apariciones, int puntos);
  ///
  ///@brief Constructor por copia
  ///@param original es el pair del que se hace copia
  Letra(const Letra & original);
  //Otros métodos
  ///
  ///@brief Obtener la letra en cuestion
  char getLetra() const;
  ///
  ///@brief Obtener apariciones asociados a la letra
  int getApariciones() const;
  ///
  ///@brief Obtener puntos asociados a la letra
  int getPuntos() const;
  ///
  ///@brief Cambiar la letra en cuestion
  ///@param l indica la letra
  void setLetra(char l);
  ///
  ///@brief Cambiar el numero de apariciones de la letra
  ///@param apariciones indica el numero de apariciones de la letra
  void setApariciones(int apariciones);
  ///
  ///@brief Cambiar el numero de puntos de la letra
  ///@param puntos indica el numero de puntos de la letra
  void setPuntos(int puntos);


};
#endif
 
