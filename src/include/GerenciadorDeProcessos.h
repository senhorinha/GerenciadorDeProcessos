/*
 * GerenciadorDeProcessos.h
 *
 *  Created on: Apr 25, 2014
 *      Author: decio
 */

#ifndef GERENCIADORDEPROCESSOS_H_
#define GERENCIADORDEPROCESSOS_H_

#include "Relogio.h"
#include "ListaOrdenadaDeProcessos.h"
#include <list>

#define NumeroMaximoDeProcessosNaMemoria 50

class GerenciadorDeProcessos {

	Relogio relogio;

	FilaDeProcessos criados;
	ListaDeProcessos prontos;
	list<Processo> executando;
	list<Processo> bloqueados;
	list<Processo> terminados;

	int numeroDeCores;
	int totalProcessos;

	int quantum;

public:
	GerenciadorDeProcessos();
	GerenciadorDeProcessos(int cores);
	virtual ~GerenciadorDeProcessos();

	void criar(Processo p);
	void carregarEmMemoria();
	Processo escalonarProximo();
	void preemptar(Processo p);
	void atualizarQuantum();
	bool simularBloqueio(Processo p);
	void simularDesbloqueio();
	void terminar(Processo p);

	void simular();
};

#endif /* GERENCIADORDEPROCESSOS_H_ */
