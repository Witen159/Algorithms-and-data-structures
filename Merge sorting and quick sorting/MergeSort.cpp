#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void Merge(vector<int>& A, int first, int middle, int last) {
	int n1, n2, i, j;
	n1 = middle - first + 1;
	n2 = last - middle;
	
	vector< int > massL(n1 + 2);
	vector< int > massR(n2 + 2);
	
	for (int i = 1; i <= n1; i++) {
		massL[i] = A[first + i - 1];
	}
	for (int j = 1; j <= n2; j++) {
		massR[j] = A[middle + j];
	}
	
	i = 1;
	j = 1;

	for (int k = first; k <= last; k++) {
		if (i!=n1+1 && (massL[i] <= massR[j] || j==n2+1)) {
			A[k] = massL[i];
			i++;
		}
		else {
			A[k] = massR[j];
			j++;
		}
	}


	
};

void MergeSort(vector<int>& A, int first, int last) {
	if (first < last) {
		int middle = (first + last) / 2;
		MergeSort(A, first, middle);
		MergeSort(A, middle + 1, last);
		Merge(A, first, middle, last);
	}

};


int main() {

	ifstream fin("sort.in");
	ofstream fout("sort.out");

	int n;
	fin >> n;
	vector< int > A(n+1);

	for (int i = 1; i <= n; i++) {
		fin >> A[i];
	}

	MergeSort(A, 1, n);

	for (int i = 1; i <= n; i++) {
		if (i == n) {
			fout << A[i];
			break;
		}
		fout << A[i] << " ";
	}


	fin.close();
	fout.close();

	return 0;
}