#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {

	ifstream fin("input.txt");
	ofstream fout("output.txt");
	 
	int n, m;

	fin >> n >> m;

	vector<vector<int>> matrix;
	matrix.assign(n, vector<int>(n));
	
	int a, b;
	for (int i = 0; i < m; i++) {
		fin >> a >> b;
		matrix[a-1][b-1]++;
		if (a==b)
			matrix[a-1][b-1]++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			fout << matrix[i][j] << " ";
		fout << endl;
	}

	return 0;
}