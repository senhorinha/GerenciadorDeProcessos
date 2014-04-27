#ifndef RELOGIO_H_
#define RELOGIO_H_

#include <iostream>

class Relogio {

	size_t tempoAtual;

public:
	Relogio();
	virtual ~Relogio();

	void iniciar();
	void tictac();
	long getTempoAtual();
};

#endif /* RELOGIO_H_ */
