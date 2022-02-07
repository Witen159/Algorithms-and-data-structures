#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main() {

	ifstream fin("linkedmap.in");
	ofstream fout("linkedmap.out");

	vector<vector<pair<string, string>>> Hesh(1009);
	vector<pair<string, string>> buf;
	string command, key, value;
	int a, number, index;
	bool t;

	while (fin >> command) {
		fin >> key;
		number = 0;

		for (int i = key.length() - 1; i >= 0; i--) {
			number += ((int)(key[i])) * (i+1);
		}

		a = number % 1009;
		t = false;

		for (int i = 0; i < Hesh[a].size(); i++) {
			if (Hesh[a][i].first == key) {
				t = true;
				index = i;
				break;
			}
		}

		if (command == "put") {
			fin >> value;
			if (t) {
				Hesh[a][index].second = value;
				for (int i = 0; i < buf.size(); i++)
					if (buf[i].first == key)
						buf[i].second = value;
			}
			else {
				Hesh[a].push_back(make_pair(key, value));
				buf.push_back(make_pair(key, value));
			}
		}

		if (command == "get") {
			if (t)
				fout << Hesh[a][index].second << endl;
			else
				fout << "none\n";
		}

		if (command == "delete" && t) {
			for (int i = 0; i < buf.size(); i++) 
				if (buf[i].first == key) {
					buf.erase(buf.begin() + i);
					break;
				}
			Hesh[a].erase(Hesh[a].begin() + index);
		}
		
		if (command == "prev") {
			if (t) {
				for (int i = 0; i < buf.size(); i++) {
					if (buf[i].first == Hesh[a][index].first) {
						if (i == 0)
							fout << "none\n";
						else 
							fout << buf[i - 1].second << endl;
						break;
					}
				}
			}
			else
				fout << "none\n";
		}

		if (command == "next") {
			if (t) {
				for (int i = 0; i < buf.size(); i++) {
					if (buf[i].first == Hesh[a][index].first) {
						if (i == buf.size()-1)
							fout << "none\n";
						else
							fout << buf[i + 1].second << endl;
						break;
					}
				}
			}
			else
				fout << "none\n";
		}
	}

	fin.close();
	fout.close();

	return 0;
}