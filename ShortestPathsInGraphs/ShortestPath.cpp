#include <iostream>
#include <vector>
#include <set>
#include <fstream>

#define INF INT64_MAX

using namespace std;

int main() {
	ifstream fin("pathmgep.in");
	ofstream fout("pathmgep.out");

	long long n, s, f;
	fin >> n >> s >> f;
	s--;
	f--;
	vector<vector<pair<long long, long long>>> graph(n);

	long long temp;
	for (long long i = 0; i < n; i++)
		for (long long j = 0; j < n; j++) {
			fin >> temp;
			if (temp > 0)
				graph[i].push_back(make_pair(temp, j));
		}

	vector<long long> dist(n, INF);

	dist[s] = 0;

	set <pair<long long, long long>> Q;
	Q.insert(make_pair(dist[s], s));
	
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

	if (dist[f] == INF)
		fout << -1;
	else
		fout << dist[f];

	fin.close();
	fout.close();

	return 0;
}