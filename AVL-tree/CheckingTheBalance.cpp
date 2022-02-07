#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct element {
    int key;
    int left;
    int right;
    int height;
    int balance;
};

int main() {

    ifstream fin("balance.in");
    ofstream fout("balance.out");

    int n;
    fin >> n;
    vector <element> tree(n+1);

    for (int i = 1; i <= n; i++) {
        fin >> tree[i].key;
        fin >> tree[i].left;
        fin >> tree[i].right;
    }

    int r, l;
    for (int i = n; i > 0; i--) {
        if (tree[i].left == 0 && tree[i].right == 0) {
            tree[i].height = 0;
            l = -1;
            r = -1;
        }
        else if (tree[i].left == 0) {
            l = -1;
            r = tree[tree[i].right].height;
            tree[i].height = r + 1;
        }
        else if (tree[i].right == 0) {
            l = tree[tree[i].left].height;
            r = -1;
            tree[i].height = l + 1;
        }
        else {
            l = tree[tree[i].left].height;
            r = tree[tree[i].right].height;
            tree[i].height = max(l, r) + 1;
        }

        tree[i].balance = r - l;
    }

    for (int i = 1; i <= n; i++) {
        fout << tree[i].balance << endl;
    }
    
    fin.close();
    fout.close();

    return 0;
}