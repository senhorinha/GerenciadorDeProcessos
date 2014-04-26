/*
 * Relogio.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: decio
 */

#include "include/Relogio.h"

Relogio::Relogio() {
	tempoZero = 0;
	tempoAtual = 0;
}

Relogio::~Relogio() {

}

void Relogio::iniciar() {
	tempoAtual = 0;
}

long Relogio::getTempoAtual(GrandezaDeTempo g) {
	return tempoAtual;
}

void Relogio::tictac(){
	tempoAtual++;
}

long Relogio::getTempoPercorrido(GrandezaDeTempo g, long tempo){
	return tempo;
}

void Relogio::cronometrar(GrandezaDeTempo grandeza, long tempo) {

}
