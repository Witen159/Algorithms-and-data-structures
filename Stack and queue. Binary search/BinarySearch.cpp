#include <iostream>
#include <fstream>

using namespace std;


int main() {
	
	ifstream fin("binsearch.in");
	ofstream fout("binsearch.out");
	
	int n, m, left, right, key, mid;
	fin >> n;

	int *mass = new int[n];

	for (int i = 0; i < n; i++) {
		fin >> mass[i];
	}

	fin >> m;

	for (int i = 0; i < m; i++) {
		fin >> key;
		
		left = -1;
		right = n;
		while (right > left + 1) {
			mid = (left + right) / 2;
			if (mass[mid] < key)
				left = mid;
			else
				right = mid;
		}

		if (right < n && mass[right] == key)
			fout << right + 1 << ' ';
		else
			fout << -1 << ' ';

		left = -1;
		right = n;
		while (right > left + 1) {
			mid = (left + right) / 2;
			if (mass[mid] > key)
				right = mid;
			else
				left = mid;
		}

		if (left > -1 && mass[left] == key)
			fout << left + 1;
		else
			fout << -1;

		if (i < m - 1)
			fout << endl;
	}
	
	

	fin.close();
	fout.close();
	delete[] mass;

	return 0;
}