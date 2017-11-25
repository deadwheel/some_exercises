#include <iostream>
#include <string>
#include <fstream>

using namespace std;


struct element {

	long klucz;
	string tekst;
	bool puste;
	long hash;
	long miejsce;


};


class Tablica {

protected:

	element * tab;

	long hf(long s) {

		return s % wielkosc;

	}

	int wielkosc;

	void relokuj(long miejsce_znal_del);



public:

	Tablica();
	void dodaj(long kl, string tkst);
	void usun(long kl);
	void ustawRozmiar(int rozmiar);
	void wys();


	~Tablica() {

		delete[] tab;
	}






};


int main() {


	fstream plik("same.txt");

	long nr_akt = 0;

	long ilosc_przyp;

	plik >> ilosc_przyp;

	Tablica *test = new Tablica[ilosc_przyp];

	string polecenie;


	while (!plik.eof()) {

		plik >> polecenie;

		if (polecenie == "size") {

			int rozmiar;
			plik >> rozmiar;
			test[nr_akt].ustawRozmiar(rozmiar);


		}

		else if (polecenie == "add")
		{

			long key;
			string slowo;

			plik >> key;
			plik >> slowo;

			test[nr_akt].dodaj(key, slowo);

		}

		else if (polecenie == "print")
		{

			test[nr_akt].wys();

		}

		else if (polecenie == "delete")
		{

			long key;

			plik >> key;

			test[nr_akt].usun(key);

		}

		else if (polecenie == "stop")
		{

			nr_akt++;

		}


	}






	//system("PAUSE");

}

void Tablica::relokuj(long miejsce_znal_del)
{

	bool found = 0;

	cout << endl << endl << "miejsce " << miejsce_znal_del << endl << endl;


	for (long x = miejsce_znal_del;x < wielkosc;x++) {

		if (tab[x].puste == 1) {

			long krok_milowy;

			for (long dlab = x;dlab < wielkosc;dlab++) {



				if ((tab[dlab].hash != tab[dlab].miejsce) && (tab[dlab].puste == 0) && (dlab + 1 <= wielkosc - 1) && tab[dlab].hash <= x) {




					tab[x].hash = tab[dlab].hash;
					tab[x].klucz = tab[dlab].klucz;
					tab[x].miejsce = x;
					tab[x].puste = 0;
					tab[x].tekst = tab[dlab].tekst;
					tab[dlab].puste = 1;



					long wartosc = x + 1; 

					for (long mia = x + 2;mia < wielkosc;mia++) {


						if (mia == tab[x].hash) break;


						if (tab[mia].hash == tab[x].hash && tab[mia].puste == 0 && tab[mia].hash != tab[mia].miejsce) {

							
							
							for (int i = x;i < mia;i++) {


								if (tab[i].puste == 1) {


									tab[i].hash = tab[mia].hash;
									tab[i].klucz = tab[mia].klucz;
									tab[i].miejsce = i;
									tab[i].puste = 0;
									tab[i].tekst = tab[mia].tekst;
									tab[mia].puste = 1;
									break;


								}


							}
							
							


						}




					}


				}



			}



		}



	}




}

Tablica::Tablica()
{

	wielkosc = 10;
	tab = new element[wielkosc];

	for (int i = 0;i < wielkosc;i++) {

		tab[i].klucz = 0;
		tab[i].tekst = "";
		tab[i].puste = 1;
		tab[i].hash = 15878;
		tab[i].miejsce = 875487;

	}

}

void Tablica::dodaj(long kl, string tkst)
{

	long pozycja = hf(kl);

	if (tab[pozycja].puste == 0) {


		long x;
		bool found = 0;



		if (pozycja == wielkosc - 1) {


			for (x = 0;x < pozycja;x++) {


				if (tab[x].puste == 1) {


					tab[x].klucz = kl;
					tab[x].tekst = tkst;
					tab[x].hash = pozycja;
					tab[x].miejsce = x;
					tab[x].puste = 0;
					break;


				}


			}


		}


		else {


			for (x = pozycja + 1;x < wielkosc;x++) {


				if (tab[x].puste == 1) {


					tab[x].klucz = kl;
					tab[x].tekst = tkst;
					tab[x].hash = pozycja;
					tab[x].miejsce = x;
					tab[x].puste = 0;

					found = 1;
					break;


				}


			}



			if (found == 0) {


				for (x = 0;x < pozycja;x++) {

					if (tab[x].puste == 1) {

						tab[x].klucz = kl;
						tab[x].tekst = tkst;
						tab[x].hash = pozycja;
						tab[x].miejsce = x;
						tab[x].puste = 0;
						//found = 1;
						break;


					}


				}


			}


		}



	}


	else {


		tab[pozycja].klucz = kl;
		tab[pozycja].tekst = tkst;
		tab[pozycja].hash = pozycja;
		tab[pozycja].miejsce = pozycja;
		tab[pozycja].puste = 0;


	}



}

void Tablica::usun(long kl)
{


	long indeks = hf(kl);
	bool found = 0;
	long miejsce_znal_del;


	if ((tab[indeks].klucz == kl) && (tab[indeks].puste == 0) && (tab[indeks].tekst != "")) {


		tab[indeks].klucz = 0;
		tab[indeks].tekst = "";
		tab[indeks].puste = 1;
		tab[indeks].hash = 0;
		tab[indeks].miejsce = 0;
		found = 1;
		miejsce_znal_del = indeks;


	}



	else {


		if (indeks == wielkosc - 1) {


			for (long x = 0;x < indeks;x++) {


				if ((tab[x].klucz == kl) && (tab[x].puste == 0) && (tab[x].tekst != "")) {


					tab[x].klucz = 0;
					tab[x].tekst = "";
					tab[x].puste = 1;
					tab[x].hash = 0;
					tab[x].miejsce = 0;
					found = 1;
					miejsce_znal_del = x;
					break;


				}


			}


		}




		else {




			for (long x = indeks + 1;x < wielkosc;x++) {


				if ((tab[x].klucz == kl) && (tab[x].puste == 0) && (tab[x].tekst != "")) {


					tab[x].klucz = 0;
					tab[x].tekst = "";
					tab[x].puste = 1;
					tab[x].hash = 0;
					tab[x].miejsce = 0;
					found = 1;
					miejsce_znal_del = x;
					break;


				}


			}



			if (found == 0) {


				for (long x = 0;x < indeks;x++) {


					if ((tab[x].klucz == kl) && (tab[x].puste == 0) && (tab[x].tekst != "")) {


						tab[x].klucz = 0;
						tab[x].tekst = "";
						tab[x].puste = 1;
						tab[x].hash = 0;
						tab[x].miejsce = 0;
						found = 1;
						miejsce_znal_del = x;
						break;


					}


				}


			}


		}


	}



	if (found == 1) {


		relokuj(miejsce_znal_del);


	}


}

void Tablica::ustawRozmiar(int rozmiar)
{

	wielkosc = rozmiar;

	delete[] tab;

	tab = new element[rozmiar];

	for (int i = 0;i < rozmiar;i++) {


		tab[i].klucz = 0;
		tab[i].tekst = "";
		tab[i].puste = 1;
		tab[i].hash = 0;
		tab[i].miejsce = 0;


	}


}

void Tablica::wys()
{

	fstream out("out.txt", ios::app);

	for (long x = 0;x < wielkosc;x++) {


		if (tab[x].puste == 0) {

			out << x << " " << tab[x].klucz << " " << tab[x].tekst << endl;

		}

	}


	out << endl;


}
