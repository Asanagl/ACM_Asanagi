#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        long long sum = 0;

        for (int j = 0; j < m; ++j) {
            long long x;
            cin >> x;
            sum += x;
        }

        cout << sum << '\n';
    }

    return 0;
}
