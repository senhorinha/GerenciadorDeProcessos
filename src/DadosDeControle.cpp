/*
 * DadosDeControle.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: decio
 */

#include "include/DadosDeControle.h"

DadosDeControle::DadosDeControle(double tempoNecessarioDeExeucao) {
	tempoNecessarioDeCPU = tempoNecessarioDeExeucao;
}

DadosDeControle::DadosDeControle() {
}

void DadosDeControle::adicionarTempoAcumuladoDeCPU(double tempo) {
	tempoAcumuladoUsoDeCPU += tempo;
}

double DadosDeControle::getTempoNecessarioParaFinalizarExecucao() {
	tempoNecessarioParaFinalizarExecucao = tempoNecessarioDeCPU
			- tempoAcumuladoUsoDeCPU;
	if (tempoNecessarioParaFinalizarExecucao <= 0) {
		return 0;
	} else {
		return tempoNecessarioParaFinalizarExecucao;
	}
}

bool DadosDeControle::isProcessoFinalizado() {
	if (tempoNecessarioDeCPU <= tempoAcumuladoUsoDeCPU)
		return true;
	return false;
}

