#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Sportsman {
    string country;
    string name;
};

vector<Sportsman> merge (vector<Sportsman> left, vector<Sportsman> right) {
    vector<Sportsman> output;
	int pointer1, pointer2;
	
	pointer1 = 0;
	pointer2 = 0;

    while (pointer1 < left.size() && pointer2 < right.size()) {
        if (left[pointer1].country <= right[pointer2].country) {
            output.push_back(left[pointer1]);
            pointer1++;
        } 
		else {
            output.push_back(right[pointer2]);
			pointer2++;
        }
    }

    for(; pointer1 < left.size(); pointer1++)
        output.push_back(left[pointer1]);

    for(; pointer2 < right.size(); pointer2++)
        output.push_back(right[pointer2]);

    return output;
}

vector<Sportsman> merge_sort(vector<Sportsman> input) {
	if (input.size() <= 1) {
		return input;
	}

	vector<Sportsman> left, right;

	for (int i = 0; i < input.size() / 2; i++) {
		left.push_back(input[i]);
	}

	for (int i = input.size() / 2; i < input.size(); i++) {
		right.push_back(input[i]);
	}

	return merge(merge_sort(left), merge_sort(right));
}

int main () {

	ifstream fin("race.in");
	ofstream fout("race.out");

    int n;
    fin >> n;

    vector<Sportsman> input(n);

    for (int i = 0; i < n; i++) {
        Sportsman sportsman;

		fin >> sportsman.country >> sportsman.name;

        input[i] = sportsman;
    }

    input = merge_sort(input);

    string curr_country;

    for (const auto& now : input) {
        if (now.country != curr_country) {
            fout << "=== " << now.country << " ===" << endl;
            curr_country = now.country;
        }
        fout << now.name << endl;
    }

	fin.close();
	fout.close();

    return 0;
}


