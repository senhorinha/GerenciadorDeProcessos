#include "include/Terminal.h"

Terminal::Terminal() {

}

void Terminal::imprimirProcesso(Processo p, int prioridade) {

	printf("\n***************************************");
	printf("\nNome: %s", p.id.nome.c_str());
	printf("\nUsuário: %s", p.id.usuario.c_str());
	printf("\nEntrou no sistema em: %lu", p.control.entradaNoSistema);
	printf("\nTempo necessário para execução: %lu", p.control.tempoNecessarioDeCPU);
	printf("\nTempo restante para finalizar execução: %lu", p.control.tempoNecessarioParaFinalizarExecucao);
	printf("\nNúmero de vezes que já utilizou a CPU: %u", p.control.numeroDeVezesNaCPU);
	printf("\nPrioridade: %u", prioridade);
	printf("\nQuantum: %u", prioridade + 1);
}

void Terminal::imprimirTempo(long tempo) {
	printf("\n###########################################################################");
	printf("\n");
	printf("\n###### Relógio ######");
	printf("\nTempo do Sistema: %lu", tempo);
	printf("\n### #### #### ### ###");
}

void Terminal::imprimirEstatisticas(Processo p) {
	printf("\n***************************************");
	printf("\nNome: %s", p.id.nome.c_str());
	printf("\nUsuário: %s", p.id.usuario.c_str());
	printf("\nEntrou no sistema em: %lu", p.control.entradaNoSistema);
	printf("\nTempo necessário para execução: %lu", p.control.tempoNecessarioDeCPU);
	printf("\nTempo de resposta: %lf", p.control.tempoDeResposta);
	printf("\nTempo de turnaround: %u", p.control.turnaround);
	//printf("\nTaxa de ocupação da CPU: %u", p.control.fracaoDeTempo);
	cout << "\nTempo de ocupação da CPU: " << p.control.fracaoDeTempo << endl;
	printf("\n");
}

void Terminal::limparTela() {
	system("clear");
}

