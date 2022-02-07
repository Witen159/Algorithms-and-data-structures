#include <iostream>
#include <vector>
#include <set>
#include <fstream>

#define INF INT64_MAX

using namespace std;

int main() {
	ifstream fin("pathbgep.in");
	ofstream fout("pathbgep.out");

	long long n, m;
	fin >> n >> m;
	vector<vector<pair<long long, long long>>> graph(n);

	long long a, b, c;
	for (long long i = 0; i < m; i++) {
		fin >> a >> b >> c;
		graph[a - 1].push_back(make_pair(c, b - 1));
		graph[b - 1].push_back(make_pair(c, a - 1));
	}

	vector<long long> dist(n, INF);

	dist[0] = 0;

	set <pair<long long, long long>> Q;
	Q.insert(make_pair(dist[0], 0));
	
	long long vertex, first, second;
	while (!Q.empty()) {
		vertex = Q.begin()->second;
		Q.erase(Q.begin());

		for (long long i = 0; i < graph[vertex].size(); i++) {
			first = graph[vertex][i].first;
			second = graph[vertex][i].second;
			if (dist[second] > dist[vertex] + first) {
				Q.erase(make_pair(dist[second], second));
				dist[second] = dist[vertex] + first;
				Q.insert(make_pair(dist[second], second));
			}
		}
	}

	for (long long i = 0; i < n; i++) {
		fout << dist[i] << " ";
	}

	fin.close();
	fout.close();

	return 0;
}