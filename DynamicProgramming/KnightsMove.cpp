#include <fstream>
#include <vector>

int n, m;

int move(std::vector<std::vector<int>>& temp, int i, int j) {
    if (((i >= 0) && (i < n)) && ((j >= 0) && (j < m))) {
        if (temp[i][j] == 0) {
            temp[i][j] = move(temp, i + 2, j + 1) + move(temp, i + 2, j - 1) +
                move(temp, i + 1, j + 2) + move(temp, i - 1, j + 2);
        }
    }
    else
        return 0;
    return temp[i][j];
}

int main() {
    std::ifstream fin("knight2.in");
    std::ofstream fout("knight2.out");

    fin >> n >> m;
    std::vector<std::vector<int>> matrix (n, std::vector<int>(m, 0));
    matrix[n - 1][m - 1] = 1;

    fout << move(matrix, 0, 0);

    return 0;
}