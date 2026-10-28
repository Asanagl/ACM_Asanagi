#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    if (!(cin >> n) || n < 1 || n % 2 == 0) {
        return 0;
    }
    vector<int> values(n);
    for (int& value : values) {
        cin >> value;
    }
    sort(values.begin(), values.end());

    int median = values[n / 2];
    int distance = 0;
    for (int value : values) {
        distance += abs(value - median);
    }
    cout << median << ' ' << distance << '\n';
    return 0;
}
