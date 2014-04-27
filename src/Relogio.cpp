#include "include/Relogio.h"

Relogio::Relogio() {
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

