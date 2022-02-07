#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

class Top{
public:
	Top (){
		mark = 1;
	}

	int number;
	vector<int> near_tops;
	bool mark;
	int component;
};

int main() {

	ifstream fin("components.in");
	ofstream fout("components.out");
	 
	int n, m;
	fin >> n >> m;

	vector<Top> tops(n);

	for (int i = 0; i < n; i++)
		tops[i].number = i;

	int a, b;
	for (int i = 0; i < m; i++) {
		fin >> a >> b;
		tops[a-1].near_tops.push_back(b);
		tops[b-1].near_tops.push_back(a);
	}

	int comp_number = 0;
	int temp;
	for (int i = 0; i < n; i++)
		if (tops[i].mark) {
			queue <Top> Q;
			comp_number++;
			tops[i].mark = 0;
			tops[i].component = comp_number;
			Q.push(tops[i]);

			while (!Q.empty()) {
				temp = Q.front().number;
				Q.pop();
				for (int j = 0; j < tops[temp].near_tops.size(); j++) 
					if (tops[tops[temp].near_tops[j] - 1].mark) {
						tops[tops[temp].near_tops[j] - 1].mark = 0;
						tops[tops[temp].near_tops[j] - 1].component = comp_number;
						Q.push(tops[tops[temp].near_tops[j] - 1]);
					}
			}
		}

	fout << comp_number << endl;

	for (int i = 0; i < n; i++)
		fout << tops[i].component << ' ';
	
	fin.close();
	fout.close();

	return 0;
}