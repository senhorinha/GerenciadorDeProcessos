#ifndef TERMINAL_H_
#define TERMINAL_H_

#include "Processo.h"
#include <iostream>

using namespace std;

class Terminal {

public:
	Terminal();
	void imprimirProcesso(Processo p);
	void imprimirTempo(long tempo);
};

#endif /* TERMINAL_H_ */
