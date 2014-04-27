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

public:

	int id;
	string usuario;
	string nome;

	DadosDeIdentificacao(int i, string us, string nome);
	DadosDeIdentificacao();
	virtual ~DadosDeIdentificacao();
};

#endif /* DADOSDEIDENTIFICACAO_H_ */
