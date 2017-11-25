#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct elem {

	int pior;
	bool szukane;

};


class druk {

protected:
	vector<elem> elementy;

public:
	bool sprawdz_czy_sa_wieksze(elem fav);
	void dzialaj(int siu, int ile);

};

int main() {

	int testCases;
	int om, kl;
	cin >> testCases;

	druk * tablica = new druk[testCases];

	for (int i = 0;i<testCases;i++) {

		cin >> om >> kl;
		tablica[i].dzialaj(kl, om);

	}


	if (tablica) delete[] tablica;

	return 0;

}

bool druk::sprawdz_czy_sa_wieksze(elem fav) {

	for (unsigned int i = 0; i<elementy.size(); i++) {

		if (fav.pior < elementy[i].pior) {

			return true;

		}

	}


	return false;

}

void druk::dzialaj(int siu, int ile) {

	elem xd;
	int pior;

	for (int i = 0; i < ile; i++) {

		cin >> pior;

		xd.pior = pior;


		if (siu == i) {
			xd.szukane = true;
			elementy.push_back(xd);
		}

		else {
			xd.szukane = false;
			elementy.push_back(xd);
		}

	}


	bool konczto = false;
	int licznik_druk = 0;
	bool found = false;

	while (found == false) {

		konczto = false;

		while (konczto == false) {


			if (sprawdz_czy_sa_wieksze(elementy[0]) == true) {

				rotate(elementy.begin(), elementy.begin() + 1, elementy.end());

			}

			else {

				konczto = true;

			}


		}


		if (elementy[0].szukane == true) {

			licznik_druk++;
			found = true;
			elementy.erase(elementy.begin());

		}


		else {

			licznik_druk++;
			elementy.erase(elementy.begin());

		}



	}


	cout << licznik_druk << endl;


}