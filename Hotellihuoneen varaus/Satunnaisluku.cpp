
// ALiohjelma huoneiden määrän muodostamiseen. Luo parillisen satunnaisluvun väliltä 40-80.


#include <iostream>
#include <time.h>

using namespace std;


int Satunnaisluku(int* yhden_hengen_huoneiden_maara, int* kahden_hengen_huoneiden_maara) {

	// Muuttuja jolle satunnaisluku arvotaan.
	int Huoneiden_maara;

	// Satunnaislukugeneraattorin algoritmin määritys
	srand(time(0));

	/* Do while silmukassa satunnaisten lukujen muodostaminen.
	Toistetaan niin kauan kunnes saadaan parillinen luku halutulta väliltä. */
	do {
		Huoneiden_maara = rand() % 40 + 40;

	} while (Huoneiden_maara % 2 != 0);

	//yhden ja kahden hengen huoneiden määrän palautus
	*yhden_hengen_huoneiden_maara = Huoneiden_maara / 2;
	*kahden_hengen_huoneiden_maara = Huoneiden_maara / 2;

	//*yhden_hengen_huoneiden_maara = 4;
		//* kahden_hengen_huoneiden_maara = 4;


	// Huoneiden kokonaismäärän palautus pääohjelmalle
	return Huoneiden_maara;
}