#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <set>

using namespace std;

const int INF = 10000000000000;

class Top {
public:
    Top() {
        key = INF;
    }

    vector <pair<int, long long>> lenth;
    long long key;
};



int main() {
    std::ifstream fin("spantree3.in");
    std::ofstream fout("spantree3.out");

    int n, m;
    fin >> n >> m;
    vector<Top> matrix(n);

    int a, b;
    long long c;
    for (int i = 0; i < m; i++) {
        fin >> a >> b >> c;
        matrix[a - 1].lenth.push_back(make_pair(b - 1, c));
        matrix[b - 1].lenth.push_back(make_pair(a - 1, c));
    }

    matrix[0].key = 0;
    set < pair<long long, int> > Q;
    Q.insert(make_pair(0, 0));

    int temp, second_top;
    long long weight = 0, cost;
    for (int z = 0; z < n; z++) {
        temp = Q.begin()->second;
        Q.erase(Q.begin());

        for (int j = 0; j < matrix[temp].lenth.size(); j++) {
            second_top = matrix[temp].lenth[j].first;
            cost = matrix[temp].lenth[j].second;

            if (cost < matrix[second_top].key) {
                Q.erase(make_pair(matrix[second_top].key, second_top));
                matrix[second_top].key = cost;
                weight += cost;
                Q.insert(make_pair(cost, second_top));
            }
        }
    }

    fout << weight;

    fin.close();
    fout.close();

    return 0;
}