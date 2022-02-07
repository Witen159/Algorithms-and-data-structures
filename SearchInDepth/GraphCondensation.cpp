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
		//number = -1;
		//mark = 0;
		buf_color = -1;
	}

	int parent;
	//int number;
	vector<int> children;
	char color;
	int buf_color;
	//bool mark;
};

void top_sort(vector<Top> &G, int num, vector<int>& sort) {

	G[num].color = 'g';

	int temp;
	for (int i = 0; i < G[num].children.size(); i++) {
		temp = G[num].children[i] - 1;

		if (G[temp].color == 'w') {
			G[temp].parent = num;
			top_sort(G, temp, sort);
		}
	}

	sort.push_back(num);
	G[num].color = 'b';
}

void DFS(vector<Top>& G, int num, int k) {
	G[num].buf_color = k;

	int temp;
	for (int i = 0; i < G[num].children.size(); i++) {
		temp = G[num].children[i] - 1;

		if (G[temp].buf_color == -1) {
			G[temp].parent = num;
			DFS(G, temp, k);
		}
	}
}

int main() {

	ifstream fin("cond.in");
	ofstream fout("cond.out");

	int n, m;
	fin >> n >> m;

	vector<Top> tops(n);
	vector<Top> tops_reversed(n);

	//for (int i = 0; i < n; i++)
	//	tops[i].number = i+1;

	int a, b;
	for (int i = 0; i < m; i++) {
		fin >> a >> b;
		tops[a - 1].children.push_back(b);
		tops_reversed[b - 1].children.push_back(a);
	}


	vector<int> sort;
	for (int i = 0; i < n; i++)
		if (tops[i].color == 'w')
			top_sort(tops, i, sort);


	int k = 1;
	for (int i = sort.size() - 1; i >= 0; i--)
		if (tops_reversed[sort[i]].buf_color == -1) {
			DFS(tops_reversed, sort[i], k);
			k++;
		}

	fout << k - 1 << endl;
	for (int i = 0; i < n; i++)
		fout << tops_reversed[i].buf_color << ' ';

	fin.close();
	fout.close();

	return 0;
}