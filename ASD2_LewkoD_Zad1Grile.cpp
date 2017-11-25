#include <iostream>


using namespace std;


int main(int argc, char *argv[]) {



	bool ** tablica;
	bool ** tablica_pom;
	char ** tablica_char;




	int ile=0;

	cin >> ile;


	while (ile != 0) {

		

		if (ile > 1) {


			tablica = new bool *[ile];
			tablica_pom = new bool *[ile];
			tablica_char = new char *[ile];


			for (int i = 0; i < ile; i++)
				tablica[i] = new bool[ile];

			for (int i = 0; i < ile; i++)
				tablica_pom[i] = new bool[ile];

			for (int i = 0; i < ile; i++)
				tablica_char[i] = new char[ile];


		}







		char ke;

		if (ile == 1) {


			char pom;
			cin >> ke;
			cin >> pom;

			if (ke == 'O') cout << pom << pom << pom << pom;



		}


		if (ile > 1) {


			for (int i = 0;i < ile;i++) {


				for (int j = 0;j < ile;j++) {


					cin >> ke;

					if (ke == '#') tablica[i][j] = 1;
					else tablica[i][j] = 0;



				}


			}



			for (int i = 0;i < ile;i++) {


				for (int j = 0;j < ile;j++) {


					cin >> tablica_char[i][j];


				}


			}







			for (int pet = 0;pet < 4;pet++) {



				if (pet > 0) {



					for (int i = 0; i < ile; i++) {
						
						
						for (int j = 0; j < ile; j++) {


							tablica_pom[j][i] = tablica[ile - 1 - i][j];


						}


					}





					for (int i = 0; i < ile; i++) {
						
						
						for (int j = 0; j < ile; j++) {


							tablica[j][i] = tablica_pom[j][i];


						}


					}





				}






				for (int i = 0;i < ile;i++) {


					for (int j = 0;j < ile;j++) {


						if (tablica[i][j] == 0) cout << tablica_char[i][j];

					}


				}





			}












			for (int i = 0; i < ile; i++)
				delete[] tablica[i];

			for (int i = 0; i < ile; i++)
				delete[] tablica_pom[i];

			for (int i = 0; i < ile; i++)
				delete[] tablica_char[i];

			delete[] tablica;
			delete[] tablica_pom;
			delete[] tablica_char;


		}



		
		cin >> ile;


		if(ile !=0) cout << endl;



	}



	return 0;


}