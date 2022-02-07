#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<vector<int>> answer;
vector<int> numbers;

void Tree(int id) {
    answer[id][0] = 0;
    answer[id][1] = numbers[id];

    for (int i : tree[id])
        Tree(i);

    for (int i : tree[id]) {
        answer[id][0] += max(answer[i][0], answer[i][1]);
        answer[id][1] += answer[i][0];
    }
}

int main() {
    ifstream fin("selectw.in");
    ofstream fout("selectw.out");

    int n, root;
    fin >> n;
    
    tree.resize(n);
    answer.assign(n, vector<int>(2, 0));
    numbers.assign(n, 0);

    int temp;
    for (int i = 0; i < n; ++i) {
        fin >> temp >> numbers[i];

        if (temp != 0)
            tree[temp - 1].push_back(i);
        else
            root = i;
    }

    Tree(root);
    fout << max(answer[root][0], answer[root][1]);
}