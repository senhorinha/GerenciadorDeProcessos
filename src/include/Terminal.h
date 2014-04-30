#ifndef TERMINAL_H_
#define TERMINAL_H_

#include "Processo.h"
#include <iostream>
#include <stdlib.h> // system

using namespace std;

class Terminal {

public:
	Terminal();
	void imprimirProcesso(Processo p, int prioridade);
	void imprimirTempo(long tempo);
	void limparTela();
};

#endif /* TERMINAL_H_ */
