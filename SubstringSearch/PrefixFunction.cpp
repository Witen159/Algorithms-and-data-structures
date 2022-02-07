#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {

    std::ifstream fin("prefix.in");
    std::ofstream fout("prefix.out");

    std::string str;
    fin >> str;

    int n = str.length(), temp;
    std::vector<int> prefix_function(n, 0);

    for (int i = 1; i < n; ++i) {
        temp = prefix_function[i - 1];

        while (temp > 0 && str[i] != str[temp])
            temp = prefix_function[temp - 1];

        if (str[i] == str[temp])
            ++temp;
        prefix_function[i] = temp;
    }

    for (int i : prefix_function)
        fout << i << ' ';

	return 0;
}