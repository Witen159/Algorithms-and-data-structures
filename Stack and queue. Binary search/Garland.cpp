#include <iostream>
#include <fstream>

using namespace std;


int main() {
	
	ifstream fin("garland.in");
	ofstream fout("garland.out");
	
	int n;
	double left, right, mid, prev, curr, next, last, h1;
	bool up;
	fin >> n;
	fin >> h1;
	left = 0;
	right = h1;
	last = -1;
	while ((right - left) > 0.001 / (n - 1)) {
		mid = (left + right) / 2;
		prev = h1;
		curr = mid;
		up = curr >= 0;

		for (int i = 2; i < n; i++) {
			next = 2 * curr - prev + 2;
			up &= next >= 0;
			prev = curr;
			curr = next;
		}

		if (up) {
			right = mid;
			last = curr;
		}
		else {
			left = mid;
		}
	}

	fout.precision(2);
	fout << fixed << last;


	fin.close();
	fout.close();

	return 0;
}