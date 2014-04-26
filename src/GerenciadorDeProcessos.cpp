/*
 * GerenciadorDeProcessos.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: decio
 */

#include "include/GerenciadorDeProcessos.h"
#include <cstdlib>

GerenciadorDeProcessos::GerenciadorDeProcessos() {
	totalProcessos = 0;
}

GerenciadorDeProcessos::GerenciadorDeProcessos(int cores) {
	numeroDeCores = cores;
}

GerenciadorDeProcessos::~GerenciadorDeProcessos() {
}

void GerenciadorDeProcessos::criar(Processo p) {
	criados.fila.push(p);
	totalProcessos++;
}

void GerenciadorDeProcessos::carregarEmMemoria() {
	Processo p;
	while (prontos.tamanho() < NumeroMaximoDeProcessosNaMemoria) {
		p = criados.fila.front();
		criados.fila.pop();
		prontos.adicionar(p);
	}
}

Processo GerenciadorDeProcessos::escalonarProximo() {
	Processo p;
	p = prontos.removerMaisPrioritario();
	executando.push_back(p);
	return p;
}

void GerenciadorDeProcessos::atualizarQuantum() {
	quantum = prontos.maiorPrioridade() + 1;
}

bool GerenciadorDeProcessos::simularBloqueio(Processo p) {
	if (rand() % 100 < 2.5) {
		bloqueados.push_back(p);
		executando.remove(p);
		return true;
	}
	return false;
}

void GerenciadorDeProcessos::simularDesbloqueio() {
	list<Processo> aux;
	Processo p;
	for (int i = 0; i < bloqueados.size(); ++i) {
		p = bloqueados.front();
		aux.push_back(p);
		bloqueados.pop_front();
		if (rand() % 100 < 2.5) {
			prontos.adicionar(p);
			aux.pop_back();
		}
	}

	for (int i = 0; i < aux.size(); ++i) {
		bloqueados.push_back(aux.front());
		aux.pop_front();
	}

}

void GerenciadorDeProcessos::terminar(Processo p) {
	terminados.push_back(p);
	executando.remove(p);
}

void GerenciadorDeProcessos::preemptar(Processo p) {
	prontos.reduzirPrioridade(p, quantum - 1);
	executando.remove(p);
}

void GerenciadorDeProcessos::simular() {
	Processo p;
	int tempoGastoAtual = 0;
	atualizarQuantum();
	while (terminados.size() != totalProcessos) {
		carregarEmMemoria();
		simularDesbloqueio();
		p = escalonarProximo();
		while (tempoGastoAtual <= quantum) {
			p.relogio.tictac();
			relogio.tictac();
			tempoGastoAtual++;
			if(simularBloqueio(p))
				break;
			if (tempoGastoAtual >= p.duracao)
				terminar(p);
		}
		preemptar(p);
	}
}
