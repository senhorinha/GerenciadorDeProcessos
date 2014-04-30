/*
 * DadosDeControle.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: decio
 */

#include "include/DadosDeControle.h"

DadosDeControle::DadosDeControle(long tempoNecessarioDeExeucao, long entrada) {
	tempoNecessarioDeCPU = tempoNecessarioDeExeucao;
	tempoNecessarioParaFinalizarExecucao = tempoNecessarioDeCPU;
	entradaNoSistema = entrada;
	numeroDeVezesNaCPU = 0;
}

DadosDeControle::DadosDeControle() {
}

bool DadosDeControle::isProcessoFinalizado() {
	if (tempoNecessarioDeCPU <= tempoAcumuladoUsoDeCPU) {
		return true;
	} else {
		return false;
	}
}
void DadosDeControle::adicionarTempoAcumuladoDeCPU(long tempo) {
	tempoAcumuladoUsoDeCPU += tempo;
	incrementarNumeroDeVezesNaCPU();
	atualizarTempoNecessarioParaFinalizarExecucao();
}

void DadosDeControle::incrementarNumeroDeVezesNaCPU() {
	numeroDeVezesNaCPU += 1;
}

void DadosDeControle::atualizarTempoNecessarioParaFinalizarExecucao() {
	tempoNecessarioParaFinalizarExecucao = tempoNecessarioDeCPU
			- tempoAcumuladoUsoDeCPU;
	if (tempoNecessarioParaFinalizarExecucao <= 0) {
		tempoNecessarioParaFinalizarExecucao = 0;
	}
}

