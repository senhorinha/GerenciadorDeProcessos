#ifndef RELOGIO_H_
#define RELOGIO_H_

class Relogio {

private:
	long tempoAtual;

public:
	Relogio();
	void iniciar();
	void tictac();
	long getTempoAtual();
};

#endif /* RELOGIO_H_ */
