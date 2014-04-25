/*
 * Relogio.h
 *
 *  Created on: Apr 25, 2014
 *      Author: decio
 */

#ifndef RELOGIO_H_
#define RELOGIO_H_

class Relogio {

	enum GrandezaDeTempo{
		SEGUNDOS, MILISEGUNDOS
	};

	long tempoZero;

public:
	Relogio();
	virtual ~Relogio();

	void iniciar();
	long getTempoPercorrido(GrandezaDeTempo g, long tempo);
	void cronometrar(GrandezaDeTempo grandeza, long tempo);
};

#endif /* RELOGIO_H_ */
