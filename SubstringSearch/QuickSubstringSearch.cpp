#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const int SIMP = 29;

int main() {
	std::ifstream fin("search2.in");
	std::ofstream fout("search2.out");

	std::string main_str, buf_str, temp_str;

	fin >> buf_str >> main_str;

	size_t s1 = main_str.length(), s2 = buf_str.length();

	std::vector<long long> pows(std::max(s1, s2));
	pows[0] = 1;

	for (size_t i = 1; i < pows.size(); ++i)
		pows[i] = pows[i - 1] * SIMP;

	std::vector<long long> hesh(s1);

	for (size_t i = 0; i < s1; ++i){
		hesh[i] = (main_str[i] - 'a' + 1) * pows[i];
		if (i > 0)  
			hesh[i] += hesh[i - 1];
	}
	
	long long hesh_buff = 0;
	for (size_t i = 0; i < s2; ++i)
		hesh_buff += (buf_str[i] - 'a' + 1) * pows[i];

	long long hesh_curr;
	std::vector<int> occur;
	for (size_t i = 0; i + s2 - 1 < s1; ++i){
		hesh_curr = hesh[i + s2 - 1];

		if (i > 0)  
			hesh_curr -= hesh[i - 1];

		if (hesh_curr == hesh_buff * pows[i])
			occur.push_back(i + 1);
	}

	fout << occur.size() << std::endl;
	for (int i : occur)
		fout << i << ' ';

	return 0;
}