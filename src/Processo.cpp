/*
 * Processo.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: decio
 */

#include "include/Processo.h"

Processo::~Processo() {
}

Processo::Processo(DadosDeEstado de, DadosDeIdentificacao di,
		DadosDeControle dc) {
	id = di;
	control = dc;
	estado = de;
}

Processo::Processo() {
}

Processo * Processo::getPai() {
	return pai;
}

