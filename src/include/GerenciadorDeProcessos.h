/*
 * GerenciadorDeProcessos.h
 *
 *  Created on: Apr 25, 2014
 *      Author: decio
 */

#ifndef GERENCIADORDEPROCESSOS_H_
#define GERENCIADORDEPROCESSOS_H_

#include "Relogio.h"

class GerenciadorDeProcessos {

	Relogio relogio;

	ListaDeProcessos criados;
	ListaDeProcessos prontos;
	ListaDeProcessos executando;
	ListaDeProcessos bloqueados;
	ListaDeProcessos terminados;

public:
	GerenciadorDeProcessos();
	virtual ~GerenciadorDeProcessos();
};

#endif /* GERENCIADORDEPROCESSOS_H_ */
