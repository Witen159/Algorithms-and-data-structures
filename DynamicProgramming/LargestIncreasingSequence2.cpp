#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 1e9;

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> seq(n), dinamic(n + 1, INF), parents(n, 0), pos(n + 1, 0);
    dinamic[0] = -INF;
    pos[0] = -1;
    int length = -INF;
    for (int i = 0; i < n; ++i)
        cin >> seq[i];


    for (int i = 0; i < n; i++) {
        int j = int(upper_bound(dinamic.begin(), dinamic.end(), seq[i]) - dinamic.begin());
        if ((dinamic[j - 1] < seq[i]) && (seq[i] < dinamic[j])) {
            dinamic[j] = seq[i];
            parents[i] = pos[j - 1];
            pos[j] = i;
            length = max(length, j);
        }
    }

    vector<int> answer;
    int temp = pos[length];
    while (temp != -1) {
        answer.push_back(seq[temp]);
        temp = parents[temp];
    }

    reverse(answer.begin(), answer.end());

    cout << answer.size() << endl;
    for (int i : answer)
        cout << i << " ";

    return 0;
}