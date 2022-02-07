#include <iostream>
#include <fstream>
using namespace std;

int main() {
	
	ifstream fin("queue.in");
	ofstream fout("queue.out");

	int M, a, last, first;
	fin >> M;
	int *queue = new int[M];
	last = 0;
	first = 0;
	char c;

	for (int i = 0; i < M; i++) {
		
		fin >> c;
		
		if (c == '+') {
			fin >> queue[last];
			last++;
		}
		
		if (c == '-') {
			fout << queue[first] << endl;
			first++;
		}
	}

	delete[] queue;

	return 0;
}