/*
 * Processo.h
 *
 *  Created on: Apr 25, 2014
 *      Author: decio
 */

#ifndef PROCESSO_H_
#define PROCESSO_H_

#include "DadosDeEstado.h"
#include "DadosDeIdentificacao.h"
#include "DadosDeControle.h"

#include "Priorizavel.h"

class Processo {

	DadosDeEstado estado;
	DadosDeIdentificacao id;
	DadosDeControle control;

	Priorizavel<Processo> prioridade;

	Processo * pai;

public:
	Processo(Processo & pai);
	virtual ~Processo();
	Processo * getPai();

	bool operator< (Processo & p){
		return prioridade.compareTo(p);
	}

};

#endif /* PROCESSO_H_ */
