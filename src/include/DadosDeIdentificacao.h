/*
 * DadosDeIdentificacao.h

 *
 *  Created on: Apr 25, 2014
 *      Author: decio
 */

#ifndef DADOSDEIDENTIFICACAO_H_
#define DADOSDEIDENTIFICACAO_H_

#include <string>

using namespace std;

class DadosDeIdentificacao {

	int id;
	string usuario;

public:
	DadosDeIdentificacao();
	virtual ~DadosDeIdentificacao();
};

#endif /* DADOSDEIDENTIFICACAO_H_ */
