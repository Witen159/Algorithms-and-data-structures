#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int maximum = 0;

class Top {
public:
	Top() {
		buf_color = -1;
	}
	vector<int> children;
	int buf_color; // 1 - проигрышная вершина, 2 - выигрышная
};

void game(vector<Top>& G, int num) {

	int temp;
	for (int i = 0; i < G[num].children.size(); i++) {
		temp = G[num].children[i];

		if (G[temp].buf_color == -1) {
			game(G, temp);
		}
	}

	if (G[num].children.size() == 0)
		G[num].buf_color = 1;

	bool chek = false;
	for (int i = 0; i < G[num].children.size(); i++)
		if (G[G[num].children[i]].buf_color == 1) {
			chek = true;
			break;
		}

	if (chek)
		G[num].buf_color = 2;
	else
		G[num].buf_color = 1;
}

int main() {

	ifstream fin("game.in");
	ofstream fout("game.out");

	int n, m, s;
	fin >> n >> m >> s;
	s--;

	vector<Top> tops(n);

	int a, b;
	for (int i = 0; i < m; i++) {
		fin >> a >> b;
		tops[a - 1].children.push_back(b - 1);
	}

	game(tops, s);

	if (tops[s].buf_color == 1)
		fout << "Second player wins";
	else 
		fout << "First player wins";

	fin.close();
	fout.close();

	return 0;
}