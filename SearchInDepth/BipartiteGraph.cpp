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
		number = -1;
		mark = 0;
		buf_color = '0';
	}

	int parent;
	int number;
	vector<int> children;
	char color;
	char buf_color;
	bool mark;
};

bool top_sort(vector<Top> &G, int num) {

	if (G[num].parent == -1)
		G[num].buf_color = '1';

	G[num].color = 'g';

	int temp;
	for (int i = 0; i < G[num].children.size(); i++) {
		temp = G[num].children[i] - 1;

		if (G[temp].buf_color == G[num].buf_color) {
			return 1;
		}

		if (G[num].buf_color == '1')
			G[temp].buf_color = '2';
		else
			G[temp].buf_color = '1';

		if (G[temp].color == 'w') {
			G[temp].parent = num;
			if (top_sort(G, temp))
				return 1;
		}
	}

	G[num].color = 'b';
	return 0;
}

int main() {

	ifstream fin("bipartite.in");
	ofstream fout("bipartite.out");

	int n, m;
	fin >> n >> m;

	vector<Top> tops(n);

	for (int i = 0; i < n; i++)
		tops[i].number = i+1;

	int a, b;
	for (int i = 0; i < m; i++) {
		fin >> a >> b;
		tops[a - 1].children.push_back(b);
		tops[b - 1].children.push_back(a);
	}

	
	for (int i = 0; i < n; i++)
		if (tops[i].color == 'w')
			if (top_sort(tops, i)) {
				fout << "NO" << endl;

				return 0;
			}

	fout << "YES";

	fin.close();
	fout.close();

	return 0;
}