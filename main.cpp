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
	cout << "Entre com os processos no seguinte formato: " << endl;
	cout << "Nome TempoDeChegada Duração Prioridade" << endl;
}
