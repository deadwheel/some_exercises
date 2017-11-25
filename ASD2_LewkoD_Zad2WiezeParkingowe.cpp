#include <iostream>

using namespace std;

int main() {


	int ileTestow, start, czas, pomoc, pomoc_xd, war_kon, testPoziomy, testPas;
	bool krec;


	cin >> ileTestow;


	for (int testy = 0; testy<ileTestow; testy++) {



		start = 1;
		czas = 0;
		krec = 1;

		cin >> testPoziomy;
		cin >> testPas;

		int ** tab = new int *[testPoziomy];
		int ** tab_pom = new int *[testPoziomy];

		for (int t_i = 0; t_i<testPoziomy; t_i++) {

			tab[t_i] = new int[testPas];
			tab_pom[t_i] = new int[testPas];

		}



		for (int i = 0;i<testPoziomy;i++) {


			for (int j = 0;j<testPas;j++) {

				cin >> tab[i][j];

			}


		}



		while (krec == 1) {


			for (int i = 0;i<testPoziomy;i++) {


				for (int j = 0;j<testPas;j++) {


					if (tab[i][j] == start) {


						if (j < testPas - j || j == testPas - j) {
							// w lewo


							czas = czas + j * 5;
							if (i>0) czas = czas + 2 * i * 10;
							pomoc = j;
							pomoc_xd = 0;


							for (int k = 0;k<(testPas - j);k++) {

								tab_pom[i][k] = tab[i][pomoc];
								pomoc++;

							}


							for (int m = (testPas - j);m<testPas;m++) {

								tab_pom[i][m] = tab[i][pomoc_xd];
								pomoc_xd++;

							}




							for (int k = 0;k<testPas;k++) {

								tab[i][k] = tab_pom[i][k];

							}


							tab[i][0] = -1;



						}


						else if (j > testPas - j) {
							//w prawo

							czas = czas + (testPas - j) * 5;
							if (i>0) czas = czas + 2 * i * 10;
							pomoc = j;
							pomoc_xd = 0;


							for (int k = 0;k<(testPas - j);k++) {

								tab_pom[i][k] = tab[i][pomoc];
								pomoc++;

							}


							for (int m = (testPas - j);m<testPas;m++) {

								tab_pom[i][m] = tab[i][pomoc_xd];
								pomoc_xd++;

							}




							for (int k = 0;k<testPas;k++) {

								tab[i][k] = tab_pom[i][k];

							}


							tab[i][0] = -1;

						}


						start++;


					}




				}


			}



			war_kon = 0;


			for (int la = 0;la<testPoziomy;la++)
				for (int tink = 0;tink<testPas;tink++)
					if (tab[la][tink] == -1) war_kon++;


			if (war_kon == testPoziomy*testPas) krec = 0;



		}


		cout << czas;

		if (testy != ileTestow - 1) cout << endl;


		for (int t_i = 0; t_i<testPoziomy; t_i++) {

			delete[] tab[t_i];
			delete[] tab_pom[t_i];

		}


		delete[] tab;
		delete[] tab_pom;


	}


}
