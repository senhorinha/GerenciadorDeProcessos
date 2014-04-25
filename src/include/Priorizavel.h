/*
 * Priorizavel.h
 *
 *  Created on: Apr 25, 2014
 *      Author: decio
 */

#ifndef PRIORIZAVEL_H_
#define PRIORIZAVEL_H_

template<typename T>
class Priorizavel{

	int prioridade;

public:
	int compareTo(T p);
	int getPrioridade();
};

#endif /* PRIORIZAVEL_H_ */
