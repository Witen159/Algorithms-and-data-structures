#include <iostream>
#include <vector>
#include <fstream>

#define INF INT64_MAX

using namespace std;

class edge {
public:
    long long from;
    long long to;
    long long weight;
};

int main() {
    ifstream fin("negcycle.in");
    ofstream fout("negcycle.out");

    long long n;
    fin >> n;

    vector<edge> graph;
    vector<long long> dist(n, INF);
    vector<long long> parents(n, -1);

    int temp;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            fin >> temp;
            graph.push_back({i, j, temp});
        }

    dist[0] = 0;
    long long flag;
    for (int i = 0; i < n; i++) {
        flag = -1;
        for (edge j : graph)
            if (dist[j.to] > dist[j.from] + j.weight) {
                dist[j.to] = dist[j.from] + j.weight;
                parents[j.to] = j.from;
                flag = j.to;
            }
    }

    if (flag == -1)
        fout << "NO";
    else {
        fout << "YES" << endl;
        vector<long long> cycle;
        long long temp = flag;

        for (long long i = 0; i < n; ++i)
            temp = parents[temp];

        for (long long i = temp; i != temp || cycle.empty(); i = parents[i])
            cycle.push_back(i);

        cycle.push_back(temp);
        fout << cycle.size() << endl;

        for (long long i = cycle.size() - 1; i >= 0; --i)
            fout << cycle[i] + 1 << " ";
    }
}