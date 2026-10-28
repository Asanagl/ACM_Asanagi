#include <bits/stdc++.h>

using namespace std;

bool read_n(long long &n) {
    if (!(cin >> n)) {
        return false;
    }
    return 1 <= n && n <= 1000000;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    try {
        long long n = 0;
        if (!read_n(n)) {
            return 0;
        }

        const __int128 value = static_cast<__int128>(n);
        const __int128 answer = value * (value + 1) * (value + 2) / 3;
        if (answer > numeric_limits<long long>::max()) {
            return 0;
        }
        cout << static_cast<long long>(answer) << '\n';
    } catch (const exception &) {
        return 0;
    }
    return 0;
}
