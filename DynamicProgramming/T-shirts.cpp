//#include <fstream>
#include <vector>
#include <iostream>

const int INF = 1e9;

int main() {
	//std::ifstream fin("knight2.in");
	//std::ofstream fout("knight2.out");

	long long n;
	std::cin >> n;

	std::vector <long long> line(n);
	std::vector <std::vector<long long>> dp(n, std::vector<long long>(n, 0));

	for (long long i = 0; i < n; ++i) {
		std::cin >> line[i];
		dp[i][i] = 1;
	}

	long long len;
	for (long long i = 1; i < n; ++i)
		for (long long j = 0; j + i < n; ++j) {
			len = i + j;

			if (line[j] == line[len]) {
				dp[j][len] = dp[j + 1][len] + dp[j][len - 1] + 1;
				while (dp[j][len] < 0)
					dp[j][len] = INF + dp[j][len];
				dp[j][len] = dp[j][len] % INF;
			}
			else {
				dp[j][len] = dp[j + 1][len] + dp[j][len - 1] - dp[j + 1][len - 1];
				while (dp[j][len] < 0)
					dp[j][len] = INF + dp[j][len];
				dp[j][len] = dp[j][len] % INF;
			}
		}

	std::cout << dp[0][n - 1];
	return 0;
}