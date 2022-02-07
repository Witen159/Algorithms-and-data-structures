#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>

using namespace std;

class Edge {
public:
    long long from;
    long long to;
    long long weight;
};

const long long INF = 9e18;

void visiting(vector<Edge>& graph, vector<bool>& used, int v) {
    used[v] = true;
    for (Edge edge : graph) {
        if (edge.from == v)
            if (!used[edge.to])
                visiting(graph, used, edge.to);
    }
}

void neg_cycle(vector<Edge>& graph, vector<bool>& negative, int v) {
    negative[v] = true;
    for (Edge edge : graph) {
        if (edge.from == v)
            if (!negative[edge.to])
                neg_cycle(graph, negative, edge.to);
    }
}

int main() {

    ifstream fin("path.in");
    ofstream fout("path.out");

    long long n, m, s;
    fin >> n >> m >> s;

    vector<Edge> graph;
    vector<long long> dist(n, INF);
    vector<bool> visited(n, false);
    vector<bool> negative(n, false);

    long long a, b, c;
    for (long long i = 0; i < m; ++i) {
        fin >> a >> b >> c;
        graph.push_back({ a - 1, b - 1, c });
    }

    visiting(graph, visited, s - 1);

    dist[s-1] = 0;
    long long flag;
    for (long long i = 0; i < n; i++) {
        for (Edge j : graph)
            if (dist[j.from] < INF)
                if (dist[j.to] > dist[j.from] + j.weight) {
                    dist[j.to] = max(dist[j.from] + j.weight, -INF);
                    if (visited[j.from] && i == n - 1)
                        neg_cycle(graph, negative, j.from);
                }
    }
    
    
    

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            fout << "*\n";
        else if (negative[i] || dist[i] <= -INF)
            fout << "-\n";
        else
            fout << dist[i] << endl;
    }

    fin.close();
    fout.close();

    return 0;
}