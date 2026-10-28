#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) {
        return 0;
    }
    int value;
    cin >> value;
    cout << value;
    for (int k = 1; k < n * m; ++k) {
        cin >> value;
        cout << ' ' << value;
    }
    cout << '\n';
    return 0;
}
