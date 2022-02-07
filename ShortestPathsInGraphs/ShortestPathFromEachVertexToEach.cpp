#include <iostream>
#include <vector>
#include <set>
#include <fstream>

#define INF INT64_MAX

using namespace std;

int main() {
	ifstream fin("pathsg.in");
	ofstream fout("pathsg.out");

	long long n, m;
	fin >> n >> m;
	vector<vector<pair<long long, long long>>> graph(n);

	long long a, b, c;
	for (long long i = 0; i < m; i++) {
		fin >> a >> b >> c;
		graph[a - 1].push_back(make_pair(c, b - 1));
	}

	vector<long long> dist(n);
	set <pair<long long, long long>> Q;
	long long vertex, first, second;

	for (int j = 0; j < n; j++) {

		for (int i = 0; i < n; i++) {
			dist[i] = INF;
		}
		Q.clear();

		dist[j] = 0;
		Q.insert(make_pair(dist[j], j));

		
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

		fout << endl;

	}

	fin.close();
	fout.close();

	return 0;
}