#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

class Top {
public:
	Top() {
		mark = 1;
	}

	int dist;
	int number;
	vector<int> near_tops;
	bool mark;
};

int main() {

	ifstream fin("pathbge1.in");
	ofstream fout("pathbge1.out");

	int n, m;
	fin >> n >> m;

	vector<Top> tops(n);

	for (int i = 0; i < n; i++)
		tops[i].number = i;

	int a, b;
	for (int i = 0; i < m; i++) {
		fin >> a >> b;
		tops[a - 1].near_tops.push_back(b);
		tops[b - 1].near_tops.push_back(a);
	}

	int temp;
	queue <Top> Q;
	tops[0].mark = 0;
	tops[0].dist = 0;
	Q.push(tops[0]);

	while (!Q.empty()) {
		temp = Q.front().number;
		Q.pop();
		for (int j = 0; j < tops[temp].near_tops.size(); j++)
			if (tops[tops[temp].near_tops[j] - 1].mark) {
				tops[tops[temp].near_tops[j] - 1].mark = 0;
				tops[tops[temp].near_tops[j] - 1].dist = tops[temp].dist + 1;
				Q.push(tops[tops[temp].near_tops[j] - 1]);
			}
	}
	
	for (int i = 0; i < n; i++)
		fout << tops[i].dist << ' ';


	fin.close();
	fout.close();

	return 0;
}