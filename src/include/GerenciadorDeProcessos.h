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
#include "Lista.h"
#include "Terminal.h"

using namespace std;

#define NumeroMaximoDeProcessosNaMemoria 50

class GerenciadorDeProcessos {

	Relogio relogio;
	Terminal terminal;
	FilaDeProcessos criados;
	ListaDeProcessos prontos;

	Lista<Processo> executando;
	Lista<Processo> bloqueados;
	Lista<Processo> terminados;


	size_t numeroDeCores;
	size_t totalProcessos;

	size_t quantum;

public:
	GerenciadorDeProcessos();
	GerenciadorDeProcessos(size_t cores);
	virtual ~GerenciadorDeProcessos();

	void criar(Processo p);
	void carregarEmMemoria();
	Processo escalonarProximo();
	void preemptar(Processo p);
	void atualizarQuantum();
	bool simularBloqueio(Processo p);
	void simularDesbloqueio();
	void terminar(Processo p);

	void printarCriados(); //debugar

	size_t getTotalProcessos(){
		return totalProcessos;
	}

	void simular();
};

#endif /* GERENCIADORDEPROCESSOS_H_ */
