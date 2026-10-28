#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) {
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        vector<int> row(m);
        for (int j = 0; j < m; ++j) {
            cin >> row[j];
        }
        for (int j = m - 1; j >= 0; --j) {
            cout << row[j];
            if (j != 0) {
                cout << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
