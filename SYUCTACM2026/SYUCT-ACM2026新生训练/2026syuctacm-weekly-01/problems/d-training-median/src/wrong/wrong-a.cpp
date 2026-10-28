#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    if (!(cin >> n) || n < 1 || n % 2 == 0) {
        return 0;
    }
    vector<long long> values(n);
    for (long long& value : values) {
        cin >> value;
    }

    long long median = values[n / 2];
    long long distance = 0;
    for (long long value : values) {
        distance += llabs(value - median);
    }
    cout << median << ' ' << distance << '\n';
    return 0;
}
