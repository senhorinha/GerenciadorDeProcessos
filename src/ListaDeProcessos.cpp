/*
 * ListaDeProcessos.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: decio
 */

#include "include/ListaOrdenadaDeProcessos.h"

#include <iostream>

using namespace std;

ListaDeProcessos::ListaDeProcessos() {
	for (size_t i = maxPriority; i < minPriority; ++i)
		lista.push_back(FilaDeProcessos(i));
}

ListaDeProcessos::~ListaDeProcessos() {
}

void ListaDeProcessos::adicionar(Processo p) {
	lista[0].fila.push(p);
}

void ListaDeProcessos::printar() {
	string a = lista[0].fila.front().id.usuario;
	cout << a << endl;
}

int ListaDeProcessos::tamanho() {
	return lista.size();
}

Processo ListaDeProcessos::removerMaisPrioritario() {
	Processo p;
	for (size_t i = 0; i < lista.size(); ++i) {
		if (!lista[i].fila.empty()) {
			p = lista[i].fila.front();
			lista[i].fila.pop();
			return p;
		}
	}
}

size_t ListaDeProcessos::maiorPrioridade() {
	for (size_t i = 0; i < lista.size(); ++i) {
		if (!lista[i].fila.empty()) {
			return i;
		}
	}
}

void ListaDeProcessos::reduzirPrioridade(Processo p, int pAtual) {
	lista[pAtual+1].fila.push(p);
}
