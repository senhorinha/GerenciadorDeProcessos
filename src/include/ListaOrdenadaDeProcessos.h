/*
 * ListaDeProcessos.h
 *
 *  Created on: Apr 25, 2014
 *      Author: decio
 */

#ifndef LISTADEPROCESSOS_H_
#define LISTADEPROCESSOS_H_

#define maxPriority 0
#define minPriority 10

#include <vector>
#include "Processo.h"
#include "FilaDeProcessos.h"

class ListaDeProcessos {


	//opção de implementação. Como há exatamente 10 filas,
	//é mais simples implementar com um vetor de filas
	vector<FilaDeProcessos> lista;

public:
	ListaDeProcessos();
	virtual ~ListaDeProcessos();

	void adicionar(Processo p);
	Processo removerMaisPrioritario();
	int maiorPrioridade();
	void reduzirPrioridade(Processo p, int pAtual);
	int tamanho();
	void printar();
};

#endif /* LISTADEPROCESSOS_H_ */
