#include <iostream>

using namespace std;

int main()
{


	long long * tablica;

	int ile = 0;

	int ile_el = 0;

	int pozycja_element = 0;

	long long element = 0;

	int parent = 0;

	int mmm = 0;

	cin >> ile;


	for (int i = 0; i < ile; i++) {


		cin >> ile_el;

		tablica = new long long[ile_el + 1];



		for (int j = 1; j <= ile_el; j++) {



			cin >> tablica[j];


		}



		for (int m = 2; m <= ile_el; m++) {


			pozycja_element = m;
			parent = pozycja_element / 2;
			element = tablica[m];


			while ((parent > 0) && (tablica[parent] < element)) {


				tablica[pozycja_element] = tablica[parent];
				pozycja_element = parent;
				parent = pozycja_element / 2;


			}



			tablica[pozycja_element] = element;



		}


		for (int m = 1; m <= ile_el; m++) {


			cout << tablica[m] << " ";


		}
		cout << endl;



		for (int m = ile_el; m > 1; m--) {


			swap(tablica[1], tablica[m]);
			pozycja_element = 1;
			parent = 2;


			while (parent < m) {



				if ((parent + 1 < m) && (tablica[parent + 1] > tablica[parent])) mmm = parent + 1;
				else mmm = parent;



				if (tablica[mmm] <= tablica[pozycja_element]) break;
				swap(tablica[pozycja_element], tablica[mmm]);

				pozycja_element = mmm;
				parent = pozycja_element + pozycja_element;



			}


			if (m != 2) {


				for (int il = 1; il < m; il++) {
					
					cout << tablica[il] << " ";
				
				}

			
				cout << endl;
			}



		}




		for (int faf = 1; faf <= ile_el; faf++) cout << tablica[faf] << " ";


			if(i != ile-1)
			cout << endl << endl;




		if (tablica) delete[] tablica;




	}


	return 0;
}

