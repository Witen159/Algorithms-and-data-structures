#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

class Top {
public:
	Top() {
		color = 'w';
		parent = -1;
	}

	int parent;
	int number;
	vector<int> children;
	char color;
};

bool top_sort(vector<Top> &G, int num, vector<int> &sort) {
	G[num].color = 'g';

	int temp;
	for (int i = 0; i < G[num].children.size(); i++) {
		temp = G[num].children[i] - 1;

		if (G[temp].color == 'g') {
			return 1;
		}

		if (G[temp].color == 'w') {
			G[temp].parent = num;
			if (top_sort(G, temp, sort))
				return 1;
		}
	}

	sort.push_back(num + 1);
	G[num].color = 'b';
	return 0;
}

int main() {

	ifstream fin("topsort.in");
	ofstream fout("topsort.out");

	int n, m;
	fin >> n >> m;

	vector<Top> tops(n);

	for (int i = 0; i < n; i++)
		tops[i].number = i+1;

	int a, b;
	for (int i = 0; i < m; i++) {
		fin >> a >> b;
		tops[a - 1].children.push_back(b);
	}

	vector<int> sort;

	for (int i = 0; i < n; i++)
		if (tops[i].color == 'w')
			if (top_sort(tops, i, sort)) {
				fout << -1;
				return 0;
			}

	for (int i = sort.size() - 1; i >= 0; i--)
		fout << sort[i] << ' ';

	fin.close();
	fout.close();

	return 0;
}