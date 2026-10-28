#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    int linear = n * (n + 1) / 2;
    int square = n * (n + 1) * (2 * n + 1) / 6;
    cout << linear + square << '\n';
    return 0;
}
