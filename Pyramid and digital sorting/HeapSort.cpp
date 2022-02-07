#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


void heapify(vector<int>& mass, int N, int parent) {
	int max = parent;
	int left_child = 2 * parent + 1;
	int right_child = 2 * parent + 2;

	if (left_child < N && mass[max] < mass[left_child]) {
		max = left_child;
	}

	if (right_child < N && mass[max] < mass[right_child]) {
		max = right_child;
	}

	if (parent != max) {
		swap(mass[parent], mass[max]);
		heapify(mass, N, max);
	}
};

void heap_sort(vector<int>& mass, int N) {
	for (int i = N / 2 - 1; i >= 0; i--) {
		heapify(mass, N, i);
	}

	for (int i = N - 1; i >= 0; i--) {
		swap(mass[0], mass[i]);
		heapify(mass, i, 0);
	}
}

int main() {

	ifstream fin("sort.in");
	ofstream fout("sort.out");

	int N;
	fin >> N;
	vector<int> mass(N);
	
	for (int i = 0; i < N; i++) {
		fin >> mass[i];
	}

	heap_sort(mass, N);

	for (int i = 0; i < N; i++) {
		fout << mass[i] << " ";
	}

	fin.close();
	fout.close();

	return 0;
}
