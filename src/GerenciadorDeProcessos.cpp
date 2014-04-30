/*
 * GerenciadorDeProcessos.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: decio
 */

#include "include/GerenciadorDeProcessos.h"
#include <cstdlib>
#include <iostream>

GerenciadorDeProcessos::GerenciadorDeProcessos() {
	totalProcessos = 0;
}

GerenciadorDeProcessos::GerenciadorDeProcessos(size_t cores) {
	numeroDeCores = cores;
}

GerenciadorDeProcessos::~GerenciadorDeProcessos() {
}

void GerenciadorDeProcessos::criar(Processo p) {
	p.estado.estadoAtual = p.estado.Criado;
	criados.fila.push(p);
	totalProcessos++;
	cout << criados.fila.size() << endl;
}

void GerenciadorDeProcessos::carregarEmMemoria() {
	Processo p;
	while (prontos.tamanho() < NumeroMaximoDeProcessosNaMemoria) {
		p = criados.fila.front();
		criados.fila.pop();
		prontos.adicionar(p);
		p.estado.estadoAtual = p.estado.Pronto;
	}
}

Processo GerenciadorDeProcessos::escalonarProximo() {
	Processo p;
	p = prontos.removerMaisPrioritario();
	executando.adicionar(p);
	p.estado.estadoAtual = p.estado.Executando;
	return p;
}

void GerenciadorDeProcessos::atualizarQuantum() {
	quantum = prontos.maiorPrioridade() + 1;
}

bool GerenciadorDeProcessos::simularBloqueio(Processo p) {
	if (rand() % 100 < 2.5) {
		bloqueados.adicionar(p);
		executando.remover(p);
		return true;
	}
	return false;
}

void GerenciadorDeProcessos::simularDesbloqueio() {
	Lista<Processo> aux;
	Processo p;
	for (int i = 0; i < bloqueados.getTamanho(); ++i) {
		p = bloqueados.removerDoInicio();
		aux.adicionar(p);
		if (rand() % 100 < 2.5) {
			prontos.adicionar(p);
			aux.removerDoInicio();
		}
	}

	for (int i = 0; i < aux.getTamanho(); ++i) {
		bloqueados.adicionar(aux.removerDoInicio());
	}

}

void GerenciadorDeProcessos::terminar(Processo p) {
	p.estado.estadoAtual = p.estado.Terminado;
	terminados.adicionar(p);
	executando.remover(p);
}

void GerenciadorDeProcessos::preemptar(Processo p) {
	p.estado.estadoAtual = p.estado.Pronto;
	prontos.reduzirPrioridade(p, quantum - 1);
	executando.remover(p);
}

void GerenciadorDeProcessos::printarCriados() {
	queue<Processo> aux;

	size_t tamFila = criados.fila.size();
	for (size_t i = 0; i < tamFila; i++) {
		Processo p = criados.fila.front();
		aux.push(p);
		criados.fila.pop();
		cout << "id: " << p.id.id << "\nnome: " << p.id.nome << "\nusuario: " << p.id.usuario << "\nchegada: "
				<< p.control.entradaNoSistema << "\nduração: " << p.control.tempoNecessarioDeCPU << endl;
	}

	tamFila = aux.size();
	for (size_t i = 0; i < tamFila; i++) {
		criados.fila.push(aux.front());
		aux.pop();
	}
}

void GerenciadorDeProcessos::simular() {
	Processo p;
	atualizarQuantum();
	while (terminados.getTamanho() != totalProcessos) {
		carregarEmMemoria();
		simularDesbloqueio();
		p = escalonarProximo();
		p.estado.estadoAtual = p.estado.Executando;
		long tempoParaFinalizarExecucao =
				p.control.tempoNecessarioParaFinalizarExecucao;
		if (tempoParaFinalizarExecucao > quantum) {
			relogio.percorrerTempoEm(quantum);
			p.control.adicionarTempoAcumuladoDeCPU(quantum);
		} else {
			relogio.percorrerTempoEm(tempoParaFinalizarExecucao);
			p.control.adicionarTempoAcumuladoDeCPU(tempoParaFinalizarExecucao);
		}
		terminal.imprimirTempo(relogio.getTempoAtual());
		terminal.imprimirProcesso(p);
		if (simularBloqueio(p)) {
			if (p.control.isProcessoFinalizado())
				terminar(p);
			break;
		}
		preemptar(p);
	}
}

