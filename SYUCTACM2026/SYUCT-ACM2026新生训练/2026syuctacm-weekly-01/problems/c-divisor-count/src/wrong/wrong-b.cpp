#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n = 0;
    cin >> n;
    long long answer = 0;
    for (long long i = 1; i <= n; ++i) {
        if (n % i == 0) {
            ++answer;
        }
    }
    cout << answer << '\n';
    return 0;
}
