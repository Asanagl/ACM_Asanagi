#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto& row : a) {
        for (int& value : row) {
            cin >> value;
        }
        for (int j = 0; j < m; ++j) {
            swap(row[j], row[m - 1 - j]);
        }
    }

    for (const auto& row : a) {
        for (int j = 0; j < m; ++j) {
            if (j != 0) {
                cout << ' ';
            }
            cout << row[j];
        }
        cout << '\n';
    }
    return 0;
}
