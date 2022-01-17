#include <iostream>
#include <time.h>

using namespace std;


int Alennus(int Hinta_alku, int* Alennus_pros) {

	// Luodaan muuttuja lopulliselle hinnalle
	int Hinta_loppu;

	// Satunnaisluvun muodostaminen väliltä 0-3
	srand(time(0));
	*Alennus_pros = rand() % 3;


	if (*Alennus_pros == 0) {

		Hinta_loppu = Hinta_alku;
	}
	else if (*Alennus_pros == 1) {

		Hinta_loppu = Hinta_alku * 0.9;
	}
	else {

		Hinta_loppu = Hinta_alku * 0.8;

	}

	return Hinta_loppu;
}