#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

class Top {
public:
	Top() {
		mark = 1;
		prev = -1;
		dist = -1;
	}

	int prev;
	int dist;
	int number;
	vector<int> near_tops;
	bool mark;
	int i;
	int j;
};

int main() {

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n, m;
	fin >> n >> m;

	vector<vector<int>> maze;
	maze.assign(n, vector<int>(m));

	int count = 0;
	int S, T;
	char buf;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			fin >> buf;

			if (buf == 'T')
				T = count;
			if (buf == 'S')
				S = count;

			if (buf == '.' || buf == 'T' || buf == 'S') {
				maze[i][j] = count;
				count++;
			}
			else
				maze[i][j] = -1;
		}

	vector<Top> tops(count);

	int index;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			index = maze[i][j];
			if (index >= 0) {
				tops[index].number = index;
				tops[index].i = i;
				tops[index].j = j;

				if (i > 0 && maze[i - 1][j] >= 0) //Сверху
					tops[index].near_tops.push_back(maze[i - 1][j]);
				if ((i < n - 1 && maze[i + 1][j] >= 0)) //снизу
					tops[index].near_tops.push_back(maze[i + 1][j]);
				if ((j < m - 1 && maze[i][j + 1] >= 0)) //справа
					tops[index].near_tops.push_back(maze[i][j + 1]);
				if ((j > 0 && maze[i][j - 1] >= 0)) //слева
					tops[index].near_tops.push_back(maze[i][j - 1]);
			}
		}

	int temp;
	queue <Top> Q;
	tops[T].mark = 0;
	tops[T].dist = 0;
	Q.push(tops[T]);

	while (!Q.empty()) {
		temp = Q.front().number;
		Q.pop();
		for (int j = 0; j < tops[temp].near_tops.size(); j++)
			if (tops[tops[temp].near_tops[j]].mark) {
				tops[tops[temp].near_tops[j]].mark = 0;
				tops[tops[temp].near_tops[j]].dist = tops[temp].dist + 1;
				tops[tops[temp].near_tops[j]].prev = temp;
				Q.push(tops[tops[temp].near_tops[j]]);
			}
	}

	temp = S;
	if (tops[temp].dist == -1)
		fout << -1;
	else {
		fout << tops[S].dist << endl;

		while (tops[temp].dist > 0) {
			if (tops[tops[temp].prev].j == tops[temp].j + 1)
				fout << 'R';
			if (tops[tops[temp].prev].j == tops[temp].j - 1)
				fout << 'L';
			if (tops[tops[temp].prev].i == tops[temp].i + 1)
				fout << 'D';
			if (tops[tops[temp].prev].i == tops[temp].i - 1)
				fout << 'U';

			temp = tops[temp].prev;
		}
	}


	fin.close();
	fout.close();

	return 0;
}