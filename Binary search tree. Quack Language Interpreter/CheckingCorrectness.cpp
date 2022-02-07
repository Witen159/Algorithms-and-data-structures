#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int a = 1;

struct element {
	long long key;
	int left;
	int right;
};

vector <element> tree;

/*void check(int number, int prev, char var) {
	if (number > 1) {
		if (var == 'l' && tree[number].key >= prev) {
			a = 0;
		}
		if (var == 'r' && tree[number].key <= prev) {
			a = 0;
		}
	}
	
	if (tree[number].left != 0) {
		check(tree[number].left, tree[number].key, 'l');
	}
	if (tree[number].right != 0) {
		check(tree[number].right, tree[number].key, 'r');
	}
}*/

void check(int number, long long min, long long max) {
	if (tree[number].key <= min || tree[number].key >= max) {
		a = 0;
	}

	if (tree[number].left != 0) {
		check(tree[number].left, min, tree[number].key);
	}
	if (tree[number].right != 0) {
		check(tree[number].right, tree[number].key, max);
	}
}


int main() {
	
	ifstream fin("check.in");
	ofstream fout("check.out");
	
	int n;
	fin >> n;

	if (n == 0) {
		fout << "YES";
	}
	else {
		tree.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			fin >> tree[i].key;
			fin >> tree[i].left;
			fin >> tree[i].right;
		}

		check(1, -1000000000, 1000000000);

		if (a == 0) {
			fout << "NO";
		}
		else {
			fout << "YES";
		}
	}

	fin.close();
	fout.close();

	return 0;
}