#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> DigitalSort(vector<string> mass, int n, int m, int k) {
	vector<string> array = mass;
	int symbols[256];
	int number;

	for (int i = 0; i < k; i++) {

		for (int i = 0; i < 256; i++) {
			symbols[i] = 0;
		}

		for (int j = 0; j < n; j++) {
			symbols[mass[j][m - i - 1]]++;
		}

		for (int j = 1; j < 256; j++) {
			symbols[j] += symbols[j - 1];
		}
		
		for (int j = n-1; j >= 0; j--) {
			array[symbols[mass[j][m - i - 1]] - 1] = mass[j];
			symbols[mass[j][m - i - 1]]--;
		}

		for (int j = 0; j < n; j++) {
			mass[j] = array[j];
		}

	}

	return mass;
}

int main() {

	ifstream fin("radixsort.in");
	ofstream fout("radixsort.out");

	int n, m, k;
	fin >> n >> m >> k;
	vector<string> mass(n);

	for (int i = 0; i < n; i++) {
		fin >> mass[i];
	}

	mass = DigitalSort(mass, n, m, k);

	for (int i = 0; i < n; i++) {
		fout << mass[i] << endl;
	}

	fin.close();
	fout.close();

	return 0;
}