/*
 * DadosDeControle.h
 *
 *  Created on: Apr 25, 2014
 *      Author: decio
 */

#ifndef DADOSDECONTROLE_H_
#define DADOSDECONTROLE_H_

class DadosDeControle {

	long tempoNecessarioDeCPU;
	long tempoAcumuladoUsoDeCPU;
	long tempoNecessarioParaFinalizarExecucao;
	long entradaNoSistema;

private:
	// quantas vezes deteve o controle da cpu;
	int numeroDeVezesNaCPU;

public:
	DadosDeControle(long tempoNecessarioDeCPU, long entradaNoSistema);
	DadosDeControle();
	void adicionarTempoAcumuladoDeCPU(long tempo);
	double getTempoNecessarioParaFinalizarExecucao();
	bool isProcessoFinalizado();
	void incrementarNumeroDeVezesNaCPU();
	int getNumeroDeVezesNaCPU();
};

#endif /* DADOSDECONTROLE_H_ */
