#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {

	ifstream fin("input.txt");
	ofstream fout("output.txt");
	 
	int n;

	fin >> n;

	vector<vector<int>> matrix;
	matrix.assign(n, vector<int>(n));


	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			fin >> matrix[i][j];

	bool check = true;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (matrix[i][j] != matrix[j][i] || (matrix[i][j] == 1 && i == j)) {
				check = false;
				break;
			}

	if (check)
		fout << "YES";
	else
		fout << "NO";

	fin.close();
	fout.close();

	return 0;
}


/*	int n, m;

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
	}*/