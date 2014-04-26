/*
 * Relogio.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: decio
 */

#include "include/Relogio.h"

Relogio::Relogio() {
}

Relogio::~Relogio() {

}

void Relogio::iniciar() {
	inicio = std::chrono::system_clock::now();
}

double Relogio::getTempoPercorridoEmMilisegundos() {
	std::chrono::time_point < std::chrono::system_clock > atual;
	atual = std::chrono::system_clock::now();
	std::chrono::duration<double> tempoPercorrido = (atual - inicio) * 1000;
	return tempoPercorrido.count();
}

double Relogio::getTempoPercorridoEmSegundos() {
	std::chrono::time_point < std::chrono::system_clock > atual;
	atual = std::chrono::system_clock::now();
	std::chrono::duration<double> tempoPercorrido = (atual - inicio);
	return tempoPercorrido.count();
}

bool Relogio::cronometrarEmMilisegundos(double milisegundos) {
	Relogio *r = new Relogio();
	r->iniciar();
	while (r->getTempoPercorridoEmMilisegundos() < milisegundos) {
		funcaoParaTomarTempo();
	}
	return true;
}

bool Relogio::cronometrarEmSegundos(double segundos) {
	Relogio *r = new Relogio();
	r->iniciar();
	while (r->getTempoPercorridoEmSegundos() < segundos) {
		funcaoParaTomarTempo();
	}
	return true;
}

long Relogio::funcaoParaTomarTempo() {
	return 1;
}
