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

#include "Relogio.h"

class Processo : public Priorizavel<Processo>{

public:

	DadosDeEstado estado;
	DadosDeIdentificacao id;
	DadosDeControle control;

	Processo * pai;

	Relogio relogio;

	int duracao;

	Processo(DadosDeEstado de, DadosDeIdentificacao di, DadosDeControle dc, int duracao);
	Processo();
	virtual ~Processo();
	Processo * getPai();

	bool operator< (Processo & p){
		return compareTo(p);
	}

};

#endif /* PROCESSO_H_ */
