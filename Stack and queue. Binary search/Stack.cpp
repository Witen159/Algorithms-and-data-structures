#include <iostream>
#include <fstream>
using namespace std;

int main() {
	
	ifstream fin("stack.in");
	ofstream fout("stack.out");

	int M, a, last;
	fin >> M;
	a = 8;
	int *stack = new int[M];
	last = 0;
	char c;

	for (int i = 0; i < M; i++) {
		/*if (last > a) {
			int* tmp = new int[a * 2];
			
			for (int j = 0; j < a; ++j) {
				tmp[j] = stack[j];
			}
			
			delete[] stack;
			stack = tmp;
		}*/
		
		fin >> c;
		
		if (c == '+') {
			fin >> stack[last];
			last++;
		}
		
		if (c == '-') {
			last--;
			fout << stack[last] << endl;
		}
	}

	delete[] stack;

	return 0;
}