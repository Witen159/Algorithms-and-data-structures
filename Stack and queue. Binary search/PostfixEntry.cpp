#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main() {
	
	ifstream fin("postfix.in");
	ofstream fout("postfix.out");
	
	char c;
	int last;
	int *stack = new int[100];

	for (int i = 0; i < 100; i++){
		stack[i] = 0;
	}

	last = 0;

	while (fin >> c) {
		if (c == '+') {
			last--;
			stack[last - 1] = stack[last - 1] + stack[last];
		} else
		if (c == '-') {
			last--;
			stack[last - 1] = stack[last - 1] - stack[last];
		} else
		if (c == '*') {
			last--;
			stack[last - 1] = stack[last - 1] * stack[last];
		} else
		if (c == '/') {
			last--;
			stack[last - 1] = stack[last - 1] / stack[last];
		}else 
		if (c!=' '){
			stack[last] = c - '0';
			last++;
		}
	}

	fout << stack[0];
	

	fin.close();
	fout.close();

	delete[] stack;
	return 0;
}