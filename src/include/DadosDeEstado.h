/*
 * DadosDeEstado.h
 *
 *  Created on: Apr 25, 2014
 *      Author: decio
 */

#ifndef DADOSDEESTADO_H_
#define DADOSDEESTADO_H_

class DadosDeEstado {


public:

	enum Estado{
		Criado, Pronto, Executando, Bloqueado, Terminado
	};

	DadosDeEstado();
	virtual ~DadosDeEstado();
	Estado estadoAtual;
	int programCounter;
};

#endif /* DADOSDEESTADO_H_ */
