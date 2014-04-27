#include <iostream>

template<typename Tipo>
class Elemento {

public:

	Tipo dado;
	Elemento* proximo;

	Elemento(Tipo d){
		dado = d;
		proximo = 0;
	}

};
