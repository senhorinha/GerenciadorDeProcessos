#ifndef RELOGIO_H_
#define RELOGIO_H_

class Relogio {

private:
	long tempoAtual;

public:
	Relogio();
	void iniciar();
	long getTempoAtual();
	void tictac();
	void percorrerTempoEm(long tempo);
};

#endif /* RELOGIO_H_ */
