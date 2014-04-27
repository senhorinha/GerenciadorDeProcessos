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

public:
	DadosDeControle(long tempoNecessarioDeCPU);
	void adicionarTempoAcumuladoDeCPU(long tempo);
	double getTempoNecessarioParaFinalizarExecucao();
	bool isProcessoFinalizado();

};

#endif /* DADOSDECONTROLE_H_ */
