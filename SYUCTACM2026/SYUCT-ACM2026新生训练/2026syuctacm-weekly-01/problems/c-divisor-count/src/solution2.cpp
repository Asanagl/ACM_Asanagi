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

unsigned long long count_by_factorization(unsigned long long n) {
    unsigned long long remaining = n;
    unsigned long long answer = 1;
    for (unsigned long long prime = 2; prime <= remaining / prime; ++prime) {
        if (remaining % prime != 0) {
            continue;
        }
        unsigned long long exponent = 0;
        while (remaining % prime == 0) {
            remaining /= prime;
            ++exponent;
        }
        answer *= exponent + 1;
    }
    if (remaining > 1) {
        answer *= 2;
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
        cout << count_by_factorization(n) << '\n';
    } catch (const exception &) {
        return 0;
    }
    return 0;
}
