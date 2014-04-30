#include "include/Terminal.h"

Terminal::Terminal() {

}

void Terminal::imprimirProcesso(Processo p) {

	printf("\n***************************************");
	printf("\nNome: %s", p.id.nome.c_str());
	printf("\nUsuário: %s", p.id.usuario.c_str());
	printf("\nEntrou no sistema em: %lu", p.control.entradaNoSistema);
	printf("\nTempo necessário para execução: %lu",
			p.control.tempoNecessarioDeCPU);
	printf("\nTempo restante para finalizar execução: %lu",
			p.control.tempoNecessarioParaFinalizarExecucao);
	printf("\nNúmero de vezes que já utilizou a CPU: %u",
			p.control.numeroDeVezesNaCPU);
}

void Terminal::imprimirTempo(long tempo) {
	printf("\n");
	printf("\n###### Relógio ######");
	printf("\nTempo do Sistema: %lu", tempo);
	printf("\n### #### #### ### ###");
}

void Terminal::limparTela() {
	system("clear");
}

