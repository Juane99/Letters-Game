#ifndef __lista_palabras_hpp__
#define __lista_palabras_hpp__
#include <vector>
#include <set>
#include <string>

using namespace std;

/**
@brief TDA lista_palabras
**/
class lista_palabras{
public:
	/**
	@brief typedef que se utiliza para usar iteradores
	**/
	typedef typename set<string>::iterator iterator;
	/**
	@brief typedef que se utiliza para usar iteradores constantes
	**/
	typedef typename set<string>::const_iterator const_iterator;
	/**
	@brief Construye un lista_palabras vacía.
	**/
	lista_palabras();
	/**
	@brief Devuelve el numero de palabras en el lista_palabras
	**/
	int size() const;
	/**
	@brief Obtiene todas las palabras en el lista_palabras de una longitud dada
	@param longitud la longitud de las palabras de salida
	@return un vector con las palabras de longitud especificada en el parámetro de entrada
	**/
	vector<string> palabras_longitud(int longitud);
	/**
	@brief añade una palabra nueva a la lista
	@param palabra es la palabra a añadir
	**/
	void aniade(string palabra);
	/**
	@brief Indica si una palabra está en el lista_palabras o no
	@param palabra la palabra que se quiere buscar
	@return true si la palabra esta en el lista_palabras. false en caso contrario
	**/
	bool Esta(string palabra);
	/**
	@brief Lee de un flujo de entrada un lista_palabras
	@param is flujo de entrada
	@param D el objeto donde se realiza la lectura.
	@return el flujo de entrada
	**/
	friend istream & operator>>(istream & is, lista_palabras &D);
	/**
	@brief Escribe en un flujo de salida un lista_palabras
	@param os flujo de salida
	@param D el objeto lista_palabras que se escribe
	@return el flujo de salida
	**/
	friend ostream & operator<<(ostream & os, const lista_palabras &D);
	/**
	@brief Iterador no constante begin()
	**/
	iterator begin();
	/**
	@brief Iterador no constante end()
	**/
	iterator end();
	/**
	@brief Iterador constante begin()
	**/
	const_iterator begin() const;
	/**
	@brief Iterador constante end()
	**/
	const_iterator end() const;

	private:
	
	/**
	@brief set que almacena los datos del diccionario
	**/
	set<string> datos;

};

#endif
