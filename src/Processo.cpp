/*
 * Processo.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: decio
 */

#include "include/Processo.h"

Processo::Processo(Processo & p) {
	pai = &p;
}

Processo::~Processo() {
}

Processo * Processo::getPai() {
	return pai;
}

