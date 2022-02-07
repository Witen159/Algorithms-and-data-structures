#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {

	ifstream fin("antiqs.in");
	ofstream fout("antiqs.out");

	int size, t;
	fin >> size;

	vector<int> mass(size);

	for (int i = 0; i < size; i++) {
		mass[i] = i+1;
	}

	for (int i = 1; i < size; i++) {
		t = mass[i];
		mass[i] = mass[i / 2];
		mass[i / 2] = t;
	}

	for (int i = 0; i < size; i++) {
		fout << mass[i] << ' ';
	}

	fin.close();
	fout.close();
}