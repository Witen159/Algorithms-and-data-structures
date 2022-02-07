#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    long long n;
    cin >> n;

    vector<long long> seq(n), dinamic(n), parents(n);
    for (long long i = 0; i < n; ++i)
        cin >> seq[i];

    for (long long i = 0; i < n; ++i) {
        dinamic[i] = 1;
        parents[i] = -1;
        for (long long j = 0; j < i; ++j)
            if ((seq[j] < seq[i]) && (1 + dinamic[j] > dinamic[i])) {
                dinamic[i] = 1 + dinamic[j];
                parents[i] = j;
            }
    }

    long long length = dinamic[0], pos = 0;
    for (long long i = 0; i < n; ++i)
        if (dinamic[i] > length) {
            length = dinamic[i];
            pos = i;
        }

    vector<long long> answer;
    while (pos != -1) {
        answer.push_back(seq[pos]);
        pos = parents[pos];
    }

    reverse(answer.begin(), answer.end());

    cout << answer.size() << endl;
    for (long long i : answer)
        cout << i << " ";
}