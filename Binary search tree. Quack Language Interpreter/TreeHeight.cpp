#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int max = 1;

struct element {
	int key;
	int left;
	int right;
};

vector <element> tree;

void height(int number, int f) {
	if (f > max) {
		max = f;
	}

	if (tree[number].left != 0) {
		height(tree[number].left, f + 1);
	}
	if (tree[number].right != 0) {
		height(tree[number].right, f + 1);
	}
}


int main() {
	
	ifstream fin("height.in");
	ofstream fout("height.out");
	
	int n;
	fin >> n;

	if (n == 0) {
		fout << 0;
	}
	else {
		tree.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			fin >> tree[i].key;
			fin >> tree[i].left;
			fin >> tree[i].right;
		}

		height(1, 1);

		fout << max;
	}
	fin.close();
	fout.close();

	return 0;
}