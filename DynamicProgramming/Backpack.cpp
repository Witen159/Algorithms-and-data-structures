#include <fstream>
#include <vector>
#include <iostream>

int main() {
	std::ifstream fin("knapsack.in");
	std::ofstream fout("knapsack.out");

	long long n, s;
	fin >> s >> n;
	
	std::vector <long long> weight(n);
	for (int w = 0; w < n; ++w)
		fin >> weight[w];

	std::vector<long long> backpack(100000, 0);
	backpack[0] = 1;

	for (auto w : weight) {
		for (long long i = s; i >= w; --i) {
			if (backpack[i - w] == 1) {
				backpack[i] = 1;
			}
		}
	}

	for (long long i = s; i >= 0; --i) {
		if (backpack[i] == 1) {
			fout << i;
			break;
		}
	}

	return 0;
}