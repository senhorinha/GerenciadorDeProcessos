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
	relogio.iniciar();
	p.estado.estadoAtual = p.estado.Criado;
	criados.adicionar(p);
	totalProcessos++;
}

bool GerenciadorDeProcessos::carregarEmMemoria() {
	Processo p;
	bool existeProcessoEscalonavel = false;
	for (unsigned int i = 0; i < criados.getTamanho(); i++){
		p = criados.mostra(i);
		if (p.control.entradaNoSistema <= relogio.getTempoAtual() && prontos.tamanho() <= NumeroMaximoDeProcessosNaMemoria) {
			criados.remover(p);
			p.estado.estadoAtual = p.estado.Pronto;
			prontos.adicionar(p);
			existeProcessoEscalonavel = true;
		}
	}
	return existeProcessoEscalonavel;
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
		cout << "\n--> Processo bloqueado <--" << endl;
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

	for (unsigned int i = 0; i < aux.getTamanho(); ++i) {
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
	executando.remover(p);
	prontos.reduzirPrioridade(p, quantum - 1);
}

/*void GerenciadorDeProcessos::printarCriados() {
 queue<Processo> aux;

 size_t tamFila = criados.fila.size();
 for (size_t i = 0; i < tamFila; i++) {
 Processo p = criados.fila.front();
 aux.push(p);
 criados.fila.pop();
 cout << "id: " << p.id.id << "\nnome: " << p.id.nome << "\nusuario: "
 << p.id.usuario << "\nchegada: " << p.control.entradaNoSistema
 << "\nduração: " << p.control.tempoNecessarioDeCPU << endl;
 }

 tamFila = aux.size();
 for (size_t i = 0; i < tamFila; i++) {
 criados.fila.push(aux.front());
 aux.pop();
 }
 }*/

void GerenciadorDeProcessos::printarProntos() {
	for (size_t i = 0; i < prontos.lista.size(); ++i) {
		queue<Processo> aux;
		Processo p;

		size_t tamFila = prontos.lista[i].fila.size();

		for (size_t j = 0; j < tamFila; j++) {
			p = prontos.lista[i].fila.front();
			aux.push(p);
			prontos.lista[i].fila.pop();
			cout << "id: " << p.id.id << "\nnome: " << p.id.nome << "\nusuario: " << p.id.usuario << "\nchegada: " << p.control.entradaNoSistema << "\nduração: " << p.control.tempoNecessarioDeCPU << "\nprioridade: " << i << endl;
		}
		tamFila = aux.size();
		for (size_t j = 0; j < tamFila; ++j) {
			prontos.lista[i].fila.push(aux.front());
			aux.pop();
		}
	}
}

void GerenciadorDeProcessos::simular() {
	Processo p;
	bool existemProcessos = false;
	while (terminados.getTamanho() != totalProcessos) {
		existemProcessos = carregarEmMemoria() || prontos.tamanho()>0;
		simularDesbloqueio();
		if(!existemProcessos){
			relogio.percorrerTempoEm(1);
			continue;
		}
		atualizarQuantum();
		p = escalonarProximo();
		p.estado.estadoAtual = p.estado.Executando;
		if(p.control.numeroDeVezesNaCPU == 0)
			p.control.tempoDeResposta = relogio.getTempoAtual();
		unsigned long tempoParaFinalizarExecucao = p.control.tempoNecessarioParaFinalizarExecucao;
		if (tempoParaFinalizarExecucao > quantum) {
			relogio.percorrerTempoEm(quantum);
			p.control.adicionarTempoAcumuladoDeCPU(quantum);
		} else {
			relogio.percorrerTempoEm(tempoParaFinalizarExecucao);
			p.control.adicionarTempoAcumuladoDeCPU(tempoParaFinalizarExecucao);
		}
		terminal.imprimirTempo(relogio.getTempoAtual());
		terminal.imprimirProcesso(p, quantum - 1);
		if (p.control.isProcessoFinalizado()) {
			cout << "\n--> Processo finalizado <--" << endl;
			terminar(p);
			p.control.turnaround = relogio.getTempoAtual();
			p.control.fracaoDeTempo = p.control.tempoAcumuladoUsoDeCPU / relogio.getTempoAtual();
			continue;
		} else if (simularBloqueio(p))
			continue;
		preemptar(p);
		cout << "num prontos: " << prontos.tamanho()<<endl;
		cout << "\n--> Processo preemptado <--" << endl;
	}
}

