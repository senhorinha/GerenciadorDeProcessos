#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

#include "include/GerenciadorDeProcessos.h"
#include "include/Processo.h"
#include "include/DadosDeControle.h"
#include "include/DadosDeEstado.h"
#include "include/DadosDeIdentificacao.h"
#include "include/AnalisadorDeComando.h"

using namespace std;

void printMessage();
string getUserInput();
bool executarHelp(string comando);
void criarProcesso(vector<string> comando);

GerenciadorDeProcessos g;
AnalisadorDeComando *analisador = new AnalisadorDeComando();

void execute(string comando) {
	vector<string> partesDoComando = analisador->separarParametros(comando);
	string nomeDoComando = partesDoComando[0];
	if (nomeDoComando == "help") {
		executarHelp(comando);
	} else if (nomeDoComando == "start") {
		//g.carregarEmMemoria();
		//g.printarProntos();
		g.simular();
	} else if (nomeDoComando == "reset") {
		//TODO: Zerar todos os processos e apresentar mensagem inicial novamente
	} else if (nomeDoComando == "add") {
		criarProcesso(partesDoComando);
	} else if (nomeDoComando == "exit") {
		exit(1);
	}
}
void imprimirComandosDisponiveis() {
	vector<string> comandosDisponiveis = analisador->getComandosDisponiveis();
	cout << "Comandos disponíveis: [";
	for (int i = 0; i < comandosDisponiveis.size(); i++) {
		auto& c = comandosDisponiveis[i];
		if (i == comandosDisponiveis.size() - 1) {
			cout << c << "]" << endl;
		} else {
			cout << c << ", ";
		}
	}
}

bool executarHelp(string comando) {
	vector<string> partesDoComando = analisador->separarParametros(comando);
	int numeroDeParametros = partesDoComando.size() - 1;
	if (numeroDeParametros == 0) {
		imprimirComandosDisponiveis();
		cout
				<< "Sintaxe: <help> ou <help> + <comando> ou <comando> + <parametros>"
				<< endl;
		return true;
	} else {
		string comandoNoHelp = partesDoComando[1];
		string descricao;
		string comoUtilizar;
		string parametros;
		string exemploDeUso;
		if (analisador->validarComando(comando)) {
			if (comandoNoHelp == "start") {
				descricao = "Inicia a simulação dos processos";
				comoUtilizar = "start";
				parametros = "nenhum";
				exemploDeUso = "start";
			} else if (comandoNoHelp == "reset") {
				descricao = "Re-inicia o sistema";
				comoUtilizar = "reset";
				parametros = "nenhum";
				exemploDeUso = "reset";
			} else if (comandoNoHelp == "add") {
				descricao = "Adiciona um processo à simulação";
				comoUtilizar = "add p1 p2 p3 p4";
				parametros =
						"p1-> nome do processo\np2-> usuário\np3->tempo de sistema em que o processo será inserido\np4->tempo necessário de execução)";
				exemploDeUso = "add estudar fulano 5 10";
			} else if (comandoNoHelp == "exit") {
				descricao = "Fechar programa";
				comoUtilizar = "exit";
				parametros = "nenhum";
				exemploDeUso = "exit";
			}
			cout << "MANUAL: " << endl;
			cout << comandoNoHelp << ": " << descricao << endl;
			cout << "Como utilizar: " << comoUtilizar << endl;
			cout << "Parâmetros: " << parametros << endl;
			cout << "Exemplo de uso: " << exemploDeUso << endl;
			return true;
		}
		return false;
	}
}

int main() {
	printMessage();
	while (true) {
		string comando = getUserInput();
		bool comandoValido = analisador->validarComando(comando);
		if (comandoValido) {
			execute(comando);
		} else {
			cout << "Comando Inválido, digite help para ajuda" << endl;
		}
	}
}

string getUserInput() {
	string command;
	getline(cin, command);
	return command;
}

void printMessage() {
	// Mensagem em ascii art : Ger. Processos
	cout
			<< "   ____             ____                                                 "
			<< std::endl;
	cout
			<< "  / ___| ___ _ __  |  _ \\ _ __ ___   ___ ___  ___ ___  ___  ___          "
			<< std::endl;
	cout
			<< " | |  _ / _ \\ '__| | |_) | '__/ _ \\ / __/ _ \\/ __/ __|/ _ \\/ __|         "
			<< std::endl;
	cout
			<< " | |_| |  __/ |_   |  __/| | | (_) | (_|  __/\\__ \\__ \\ (_) \\__ \\         "
			<< std::endl;
	cout
			<< "  \\____|\\___|_(_)  |_|   |_|  \\___/ \\___\\___||___/___/\\___/|___/         "
			<< std::endl;
	cout
			<< " 	                                                                        "
			<< std::endl;
	cout << "" << std::endl;
	cout << "Código em: https://github.com/thisenrose/GerenciadorDeProcessos"
			<< endl;
	cout << "Sintaxe: <help> ou <help> + <comando> ou <comando> + <parametros>"
			<< endl;
	cout << endl;
	imprimirComandosDisponiveis();
}

void criarProcesso(vector<string> comando) {
	Processo p;

	p.id.id = g.getTotalProcessos();
	p.id.nome = comando[1];
	p.id.usuario = comando[2];

	long tempoChegada = atol(comando[3].c_str());
	long duracao = atol(comando[4].c_str());

	DadosDeControle d(duracao, tempoChegada);

	p.control = d;

	g.criar(p);
}
