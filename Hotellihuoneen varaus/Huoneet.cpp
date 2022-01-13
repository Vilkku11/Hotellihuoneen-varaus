#include <iostream>
#include <time.h>

using namespace std;


int Huoneet(int* Huoneiden_maara, int* yhden_hengen_huoneiden_maara, int* kahden_hengen_huoneiden_maara) {



	setlocale(LC_ALL, "fi-FI");
	int Huonetyyppi;
	int yo_maara;
	int Hinta_alku = 0;
	int Asiakkaan_hyvaksyminen;
	bool virhe = false;




	cout << "Vapaita huoneita loytyy yhteensä " << *Huoneiden_maara << endl;

	// Tarkistus onko huoneita vielä jäljellä
	if (*Huoneiden_maara <= 0) {
		system("CLS");
		cout << "Valitettavasti vapaita huoneita ei ole tällä hetkellä saatavilla." << endl;
		exit(0);

	}// Tarkistetaan onko yksittäisiä huoneita jäljellä
	if (*kahden_hengen_huoneiden_maara == 0) {

		cout << "Valitettavasti vain 1 hengen huoneita jäljellä" << endl;

		// Syötteen tarkistus
		do {
			try {
				cout << "Onko 1 hengen huoneen varaaminen mahdollista?" << endl;
				cout << "1 kyllä" << endl;
				cout << "2 ei" << endl;
				cin >> Asiakkaan_hyvaksyminen;

				if (Asiakkaan_hyvaksyminen == 1 || Asiakkaan_hyvaksyminen == 2) {

					virhe = false;

				}
				else if (cin.fail() == true) {

					throw 1;
					virhe = true;

				}
				else if (Asiakkaan_hyvaksyminen < 1 || Asiakkaan_hyvaksyminen > 2) {

					throw 1;
					virhe = true;

				}
				else {

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

		} while (virhe);

		// Tarkistus asiakkaan hyväksymisestä tai kieltäytymisestä.
		// Jos hyvöksytään, ohjelma jatkaa normaalisti. Jos kieltydytään, niin virheilmoitus ettei vapaita huoneit saatavilla
		if (Asiakkaan_hyvaksyminen == 1) {

			do {
				try {
					cout << "Hienoa! Kuinka monta yötä haluaisitte viettää?" << endl;
					cin >> yo_maara;

					if (yo_maara <= 0) {

						throw 1;
						virhe = true;

					}
					else if (cin.fail() == true) {

						throw 1;
						virhe = true;

					}
					else {
						virhe = false;
					}
				}
				catch (...) {

					system("CLS");
					cout << "virheellinen syöte" << endl;
					cin.clear();
					cin.ignore(80, '\n');
					virhe = true;

				}


			} while (virhe);

			// Huoneen hinta * öiden määrällä
			Hinta_alku = 100 * yo_maara;
			// Vähennetään huoneiden kokonaismäärää ja yksittäisen huonetyypin määrää
			*Huoneiden_maara = *Huoneiden_maara - 1;
			*yhden_hengen_huoneiden_maara = *yhden_hengen_huoneiden_maara - 1;
			cout << "Kahden hengen huone ja " << yo_maara << " yötä" << endl;
		}
		else {

			cout << "Valitettavasti lisää huoneita ei ole saatavilla" << endl;
			exit(0);
		}

	}
	else if (*yhden_hengen_huoneiden_maara == 0) {

		cout << "Valitettavasti vain 2 hengen huoneita jäljellä" << endl;


		do {
			try {
				cout << "Onko 2 hengen huoneen varaaminen mahdollista?" << endl;
				cout << "1 kyllä" << endl;
				cout << "2 ei" << endl;
				cin >> Asiakkaan_hyvaksyminen;

				if (Asiakkaan_hyvaksyminen == 1 || Asiakkaan_hyvaksyminen == 2) {

					virhe = false;

				}
				else if (cin.fail() == true) {

					throw 1;
					virhe = true;

				}
				else if (Asiakkaan_hyvaksyminen < 1 || Asiakkaan_hyvaksyminen > 2) {

					throw 1;
					virhe = true;

				}
				else {

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

		} while (virhe);

		if (Asiakkaan_hyvaksyminen == 1) {


			do {
				try {
					cout << "Hienoa! Kuinka monta yötä haluaisitte viettää?" << endl;
					cin >> yo_maara;

					if (yo_maara <= 0) {

						throw 1;
						virhe = true;

					}
					else if (cin.fail() == true) {

						throw 1;
						virhe = true;

					}
					else {
						virhe = false;
					}
				}
				catch (...) {

					system("CLS");
					cout << "virheellinen syöte" << endl;
					cin.clear();
					cin.ignore(80, '\n');
					virhe = true;

				}


			} while (virhe);




			Hinta_alku = 150 * yo_maara;

			*Huoneiden_maara = *Huoneiden_maara - 1;
			*kahden_hengen_huoneiden_maara = *kahden_hengen_huoneiden_maara - 1;
			cout << "Kahden hengen huone ja " << yo_maara << " yötä" << endl;
		}
		else {

			cout << "Valitettavasti lisää huoneita ei ole saatavilla" << endl;
			exit(0);
		}


	}
	else {

		cout << "joista vapaita yhden hengen huoneita on " << *yhden_hengen_huoneiden_maara;
		cout << " ja kahden hengen huoneita " << *kahden_hengen_huoneiden_maara;

		cout << " " << endl;


		do {

			try {
				cout << "Paina 1 jos haluat yhden hengen huoneen." << endl;
				cout << "Paina 2 jos haluat kahden hengen huoneen." << endl;
				cin >> Huonetyyppi;

				if (Huonetyyppi == 1 || Huonetyyppi == 2) {

					virhe = false;

				}
				else if (cin.fail() == true) {

					throw 1;
					virhe = true;

				}
				else if (Huonetyyppi < 1 || Huonetyyppi > 2) {

					throw 1;
					virhe = true;

				}
				else {

					virhe = true;
				}
			}
			catch (...) {

				system("CLS");
				cout << "virheellinen syöte" << endl;
				cin.clear();
				cin.ignore(80, '\n');
				virhe = true;

			}

		} while (virhe);

		do {
			try {
				cout << "Hienoa! Kuinka monta yötä haluaisitte viettää?" << endl;
				cin >> yo_maara;

				if (yo_maara <= 0) {

					throw 1;
					virhe = true;

				}
				else if (cin.fail() == true) {

					throw 1;
					virhe = true;

				}
				else {
					virhe = false;
				}
			}
			catch (...) {

				system("CLS");
				cout << "virheellinen syöte" << endl;
				cin.clear();
				cin.ignore(80, '\n');
				virhe = true;

			}


		} while (virhe);


		if (Huonetyyppi == 1) {

			Hinta_alku = 100 * yo_maara;

			*Huoneiden_maara = *Huoneiden_maara - 1;
			*yhden_hengen_huoneiden_maara = *yhden_hengen_huoneiden_maara - 1;
			cout << "Yhden hengen huone ja " << yo_maara << " yötä" << endl;



		}
		else {

			Hinta_alku = 150 * yo_maara;

			*Huoneiden_maara = *Huoneiden_maara - 1;
			*kahden_hengen_huoneiden_maara = *kahden_hengen_huoneiden_maara - 1;
			cout << "Kahden hengen huone ja " << yo_maara << " yötä" << endl;
		}
	}






	// Hinta ennen alennusta palauttaminen
	return Hinta_alku;
}