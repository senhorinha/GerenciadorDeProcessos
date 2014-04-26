#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>

#include "include/GerenciadorDeProcessos.h"
#include "include/Processo.h"
#include "include/DadosDeControle.h"
#include "include/DadosDeEstado.h"
#include "include/DadosDeIdentificacao.h"

using namespace std;

vector<string> split(string str, string sep = " ");
void printMessage();
string getUserInput();
string getCommandUserInput(string input);

GerenciadorDeProcessos g;

void execute(string command, string input) {
	if (command == "p") {

	} else if (command == "") {

	} else if (command == "exit" || command == "quit") {
		exit(1);
	} else {
		cout << "'" << command << "' was not found." << endl;
	}
}

int main() {

	printMessage();

	/*while (true) {
	 string input = getUserInput();
	 string command = getCommandUserInput(input);

	 execute(command, input);
	 }*/
}

vector<string> split(string str, string sep) {
	char* cstr = const_cast<char*>(str.c_str());
	char* current;
	vector<string> arr;
	current = strtok(cstr, sep.c_str());
	while (current != NULL) {
		arr.push_back(current);
		current = strtok(NULL, sep.c_str());
	}
	return arr;
}

string getCommandUserInput(string input) {
	int index = input.find(" ", 0);
	return index != 0 ? input.substr(0, index) : input;
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
	cout << "Entre com os processos no seguinte formato: " << endl;
	cout << "Nome GrandezaDeTempo(s ou ms) TempoDeChegada Duração Prioridade"
			<< endl;
	cout << "Exemplo: p1 s 10 20 2" << endl;
	cout
			<< "No exemplo acima o processo tem nome p1 entrará no sistema aos 10 segundos, irá utilizar 20 segundos para execução e tem prioridade 2"
			<< endl;
}
