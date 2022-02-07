#include <iostream>
#include <fstream>

using namespace std;


int main () {

	ifstream fin("isheap.in");
	ofstream fout("isheap.out");

	int n;
	bool m = true;
	fin >> n;
	int* mas = new int[n];

	for (int i = 1; i <= n; i++) {
		fin >> mas[i];
	}

	for (int i = 1; i <= (n-1)/2; i++) {
		if (mas[i] > mas[2 * i] || mas[i] > mas[2 * i + 1]) {
			m = false;
			break;
		}
	}

	fout << ((m) ? "YES" : "NO");
    
	fin.close();
	fout.close();

    return 0;
}


