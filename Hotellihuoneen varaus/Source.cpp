#include <iostream>
#include "Aliohjelmat.h"
#include "Windows.h"
#include <time.h>


using namespace std;


int main() {
	// Ääkkösten asettaminen
	setlocale(LC_ALL, "fi-FI");


	int Hinta_alku = 0;
	int Alennus_pros;
	int Hinta_loppu;
	int Kysymys = 1;
	int Huone_numero;

	bool virhe = false;

	int yhden_hengen_huoneiden_maara;
	int kahden_hengen_huoneiden_maara;

	// Alkuvalmistelut

	  // Kutsutaan aliohjelmaa Satunnaisluku, joka palauttaa huoneiden kokonaismäärän muuttujaparametrina
	  // ja eri huonetyyppien määrät arvoparametreinä
	int Huoneiden_maara = Satunnaisluku(&yhden_hengen_huoneiden_maara, &kahden_hengen_huoneiden_maara);



	// Alkutervehdys
	cout << "Tervetuloa hotellihuoneen varaukseen!" << endl;

	do {
		// Kutsutaan aliohjlemaa Huoneet, joka palauttaa hinnan ennen alennusta
		  // 
		Hinta_alku = Huoneet(&Huoneiden_maara, &yhden_hengen_huoneiden_maara, &kahden_hengen_huoneiden_maara);

		// Kutsutaan aliohjelmaa Alennus, joka laskee varauksen lopullisen hinnan
		Hinta_loppu = Alennus(Hinta_alku, &Alennus_pros);

		// Varauksen tietojen esitäminen riippuen alennuksen suuruudesta
		if (Alennus_pros == 1) {

			cout << "Tarjoamme 10% alennuksen juuri sinulle!" << endl;

			// Satunnaisen huonenumeron muodostaminen
			srand(time(0));
			Huone_numero = rand() % 80 + 1;


			cout << "Varauksenne hinta on: " << Hinta_loppu << " euroa." << endl;
			cout << "Huoneenne numero on: " << Huone_numero;
			cout << " " << endl;
		}
		else if (Alennus_pros == 2) {

			cout << "Tarjoamme 20% alennuksen juuri sinulle!" << endl;


			srand(time(0));
			Huone_numero = rand() % 80 + 1;


			cout << "Varauksenne hinta on: " << Hinta_loppu << " euroa." << endl;
			cout << "Huoneenne numero on: " << Huone_numero;
			cout << " " << endl;
		}
		else {


			srand(time(0));
			Huone_numero = rand() % 80 + 1;


			cout << "Varauksenne hinta on: " << Hinta_loppu << " euroa." << endl;
			cout << "Huoneenne numero on: " << Huone_numero;
			cout << " " << endl;
		}

		cout << " " << endl;


		// Varauksen jälkeen kysymys varauksien jatkamisesta
		do {
			// Käyttäjän syötteen tarkistus
			try {
				cout << "Haluatteko varata lisaa huoneita?" << endl;
				cout << "1 Kyllä" << endl;
				cout << "2 Ei" << endl;
				cin >> Kysymys;

				if (Kysymys == 1 || Kysymys == 2) {


					virhe = false;

				}
				else if (cin.fail() == true) {

					throw 1;
					virhe = true;

				}
				else if (Kysymys < 1 || Kysymys > 2) {

					throw 1;
					virhe = true;

				}
				else {

					throw 1;
					virhe = true;
				}
			}
			catch (...) {
				system("CLS");
				cout << "Virheellinen syöte" << endl;
				cin.clear();
				cin.ignore(80, '\n');
				virhe = true;

			}



		} while (virhe == true);



		// Ruudun tyhjennys seuraavaa varausta tai lopputervehdystä varten
		system("CLS");

		// Syötteen tarkistus ohjelman lopettamisesta
		if (Kysymys == 2) {

			Hinta_alku = 0;
		}

	} while (Hinta_alku > 0);

	// Lopputervehdys suljettaessa
	cout << "Tervetuloa uudestaan!" << endl;


	return 0;
}