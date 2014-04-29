#include "include/Terminal.h"

Terminal::Terminal() {

}

void Terminal::imprimirProcesso(Processo p) {

	printf("***************************************\n");
	printf("Nome: %s", p.id.nome.c_str());
	printf("Usuário: %s", p.id.usuario.c_str());
	printf("Entrou no sistema em: %lu", p.control.entradaNoSistema);
	printf("Tempo necessário para execução: %lu",
			p.control.tempoNecessarioDeCPU);
	printf("Tempo restante para finalizar execução: %lu",
			p.control.tempoNecessarioParaFinalizarExecucao);
	printf("Número de vezes que já utilizou a CPU: %u",
			p.control.numeroDeVezesNaCPU);
}

