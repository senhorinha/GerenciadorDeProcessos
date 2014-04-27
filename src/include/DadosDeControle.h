/*
 * DadosDeControle.h
 *
 *  Created on: Apr 25, 2014
 *      Author: decio
 */

#ifndef DADOSDECONTROLE_H_
#define DADOSDECONTROLE_H_

class DadosDeControle {

	double tempoNecessarioDeCPU;
	double tempoAcumuladoUsoDeCPU;
	double tempoNecessarioParaFinalizarExecucao;

public:
	DadosDeControle(double tempoNecessarioDeCPU);
	DadosDeControle();
	void adicionarTempoAcumuladoDeCPU(double tempo);
	double getTempoNecessarioParaFinalizarExecucao();
	bool isProcessoFinalizado();

};

#endif /* DADOSDECONTROLE_H_ */
