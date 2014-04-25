/*
 * ListaDeProcessos.h
 *
 *  Created on: Apr 25, 2014
 *      Author: decio
 */

#ifndef LISTADEPROCESSOS_H_
#define LISTADEPROCESSOS_H_

#include <list>
#include "Processo.h"

class ListaDeProcessos {

	list<Processo> lista;

public:
	ListaDeProcessos();
	virtual ~ListaDeProcessos();
};

#endif /* LISTADEPROCESSOS_H_ */
