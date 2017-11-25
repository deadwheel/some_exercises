#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct krawedzie {

	int wierzch_1;
	int wierzch_2;
	int waga;

};

bool operator<(const krawedzie& a, const krawedzie& b)
{
	return a.waga < b.waga;
}


class MST {

	protected:
		vector <krawedzie> test;
		vector <krawedzie> final_test;
		unordered_map <int, string> vectors;
		unordered_map <int, int> PARENT;
		unordered_map <int, int> RANK;
		int ilosc_wierzch;
		int ilosc_krawedzi;


	public:
		int find_parentid(int ajdi) {

			if (PARENT[ajdi] == ajdi)
				return PARENT[ajdi];
			else
				return find_parentid(PARENT[ajdi]);

		}

		void zaladuj() {

			krawedzie jeden;
			krawedzie next_edge;
			int h_iden;
			string h_name;
			int h_wierzch = 0;
			int h_kraw = 0;


			cin >> ilosc_wierzch;


			for (int i = 0;i < ilosc_wierzch;i++) {

				cin >> h_iden >> h_name;

				vectors[h_iden] = h_name;
				PARENT[h_iden] = h_iden;
				RANK[h_iden] = 0;

			}


			cin >> ilosc_krawedzi;


			for (int i = 0;i < ilosc_krawedzi;i++) {

				cin >> jeden.wierzch_1 >> jeden.wierzch_2 >> jeden.waga;
				test.push_back(jeden);

			}



			sort(test.begin(), test.end());



			// PO POSORTOWANIU

			//for (int i = 0;i < test.size();i++) {

			//	cout << test[i].wierzch_1 << test[i].wierzch_2 << test[i].waga << endl;


			//}

			//cout << endl << endl;


			while (h_wierzch < ilosc_wierzch-1) {

				next_edge = test[h_kraw];
				h_kraw++;


				int x = find_parentid(next_edge.wierzch_1);
				int y = find_parentid(next_edge.wierzch_2);


				if (x != y)
				{

					final_test.push_back(next_edge);
					h_wierzch++;


					if (RANK[x] > RANK[y]) {
						PARENT[y] = x;
						RANK[x]++;
					}


					else {
						PARENT[x] = y;
						RANK[y]++;
					}
				
				
				}




			}





			for (int i = 0;i < final_test.size();i++) {


				cout << vectors[final_test[i].wierzch_1] << " " << vectors[final_test[i].wierzch_2] << " " << final_test[i].waga << endl;


			}





		}

};

int main() {

	MST pir;
	pir.zaladuj();

	return 0;

}