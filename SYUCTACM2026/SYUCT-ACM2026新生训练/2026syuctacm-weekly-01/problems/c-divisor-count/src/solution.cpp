#include <bits/stdc++.h>

using namespace std;

bool read_n(unsigned long long &n) {
    long long value = 0;
    if (!(cin >> value) || value < 1 || value > 1000000000000LL) {
        return false;
    }
    n = static_cast<unsigned long long>(value);
    return true;
}

unsigned long long count_divisors(unsigned long long n) {
    unsigned long long answer = 0;
    for (unsigned long long divisor = 1; divisor <= n / divisor; ++divisor) {
        if (n % divisor != 0) {
            continue;
        }
        answer += divisor == n / divisor ? 1 : 2;
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    try {
        unsigned long long n = 0;
        if (!read_n(n)) {
            return 0;
        }
        cout << count_divisors(n) << '\n';
    } catch (const exception &) {
        return 0;
    }
    return 0;
}
