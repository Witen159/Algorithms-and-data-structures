#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
	std::ifstream fin("search1.in");
	std::ofstream fout("search1.out");

	std::string main_str, buf_str, temp_str;

	fin >> buf_str >> main_str;

	int size_1 = main_str.length();
	int size_2 = buf_str.length();

	std::vector<int> occur;
	for (int i = 0; i <= size_1 - size_2; ++i) {
		for (int j = i; j <= i + size_2 - 1; ++j)
			temp_str += main_str[j];

		if (temp_str == buf_str)
			occur.push_back(i + 1);

		temp_str.clear();
	}

	fout << occur.size() << std::endl;
	for (int i : occur)
		fout << i << " ";

	return 0;
}