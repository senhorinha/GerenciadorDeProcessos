#ifndef RELOGIO_H_
#define RELOGIO_H_

#include <iostream>
#include <chrono>
#include <ctime>

class Relogio {

	std::chrono::time_point<std::chrono::system_clock> inicio;

public:
	Relogio();
	virtual ~Relogio();

	void iniciar();
	double getTempoPercorridoEmMilisegundos();
	double getTempoPercorridoEmSegundos();
	bool cronometrarEmMilisegundos(double tempo);
	bool cronometrarEmSegundos(double tempo);

private:
	long funcaoParaTomarTempo();

};

#endif /* RELOGIO_H_ */
