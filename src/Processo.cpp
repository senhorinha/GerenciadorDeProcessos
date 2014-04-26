/*
 * Processo.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: decio
 */

#include "include/Processo.h"

Processo::~Processo() {
}

Processo::Processo(DadosDeEstado de, DadosDeIdentificacao di, DadosDeControle dc, int d) {
	id = di;
	control = dc;
	estado = de;
	duracao = d;
}

Processo::Processo() {
}

Processo * Processo::getPai() {
	return pai;
}

