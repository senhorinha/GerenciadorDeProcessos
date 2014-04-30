#include "include/AnalisadorDeComando.h"

AnalisadorDeComando::AnalisadorDeComando() {

}

vector<string> AnalisadorDeComando::separarParametros(string comando) {
	vector<string> tokens;
	std::string delimiter = " ";
	size_t pos = 0;
	std::string token;
	while ((pos = comando.find(delimiter)) != std::string::npos) {
		token = comando.substr(0, pos);
		tokens.push_back(token);
		comando.erase(0, pos + delimiter.length());
	}
	tokens.push_back(comando);
	return tokens;
}

bool AnalisadorDeComando::validarComando(string comando) {
	vector<string> partesDoComando = separarParametros(comando);

	for (string & c : getComandosDisponiveis()) {
		if (c == partesDoComando[0]) {
			if (partesDoComando[0] == "add") {
				if (partesDoComando.size() == 5) {
					if (isNumero(partesDoComando[3])
							&& isNumero(partesDoComando[4])) {
						return true;
					}
				}
				return false;
			} else if (c == "help" && partesDoComando.size() == 2) {
				return true;
			} else if (partesDoComando.size() == 1) {
				return true;
			}
		}
	}
	return false;
}

vector<string> AnalisadorDeComando::getComandosDisponiveis() {
	return comandosDisponiveis;
}

bool AnalisadorDeComando::isNumero(const std::string& s) {
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it))
		++it;
	return !s.empty() && it == s.end();
}

