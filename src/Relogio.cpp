/*
 * Relogio.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: decio
 */

#include "include/Relogio.h"

Relogio::Relogio() {
}

Relogio::~Relogio(){
}

void Relogio::iniciar() {
	tempoAtual = 0;
}

long Relogio::getTempoAtual() {
	return tempoAtual;
}

void Relogio::tictac() {
	tempoAtual++;
}
