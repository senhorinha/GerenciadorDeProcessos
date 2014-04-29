/*
 * DadosDeControle.h
 *
 *  Created on: Apr 25, 2014
 *      Author: decio
 */

#ifndef DADOSDECONTROLE_H_
#define DADOSDECONTROLE_H_

class DadosDeControle {

public:

	long tempoNecessarioParaFinalizarExecucao;
	long tempoNecessarioDeCPU;
	long tempoAcumuladoUsoDeCPU;
	long entradaNoSistema;
	// quantas vezes deteve o controle da cpu;
	int numeroDeVezesNaCPU;

	DadosDeControle(long tempoNecessarioDeCPU, long entradaNoSistema);
	DadosDeControle();
	void adicionarTempoAcumuladoDeCPU(long tempo);
	bool isProcessoFinalizado();
private:
	void incrementarNumeroDeVezesNaCPU();
	void atualizarTempoNecessarioParaFinalizarExecucao();
};

#endif /* DADOSDECONTROLE_H_ */
