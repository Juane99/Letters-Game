#include <algorithm>
#include <random>
#include <chrono>

#include "bolsa_letras.hpp"
#include "ConjuntoLetras.hpp"
#include "Letra.hpp"

using namespace std;

bolsa_letras::bolsa_letras(ConjuntoLetras cl)
{
	int cantidad;
	ConjuntoLetras::iterator it = cl.begin();

	while (it != cl.end()){
		cantidad = (*it).getApariciones();
		for (int i = 0; i< cantidad; i++)
			bolsa.push_back((*it).getLetra());

		++it;
	}

}

void bolsa_letras::desordenar(){

	unsigned seed =	std::chrono::system_clock::now().time_since_epoch().count();
   	std::default_random_engine e(seed);

        std::shuffle(bolsa.begin(), bolsa.end(), e);

}


vector<char> bolsa_letras::sacarLetras(int cantidad){
	vector<char> a_devolver;

	desordenar();

	for (int i=0; i<cantidad; i++)
		a_devolver.push_back(bolsa[i]);
	
	return a_devolver;
}
	

	

	
