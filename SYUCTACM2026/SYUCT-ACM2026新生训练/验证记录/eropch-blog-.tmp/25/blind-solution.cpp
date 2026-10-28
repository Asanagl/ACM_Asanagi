#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    if (!(std::cin >> s)) {
        return 0;
    }

    const int n = static_cast<int>(s.size());

    for (int L = 1; L <= n; ++L) {
        if (n % L != 0) {
            continue;
        }

        bool ok = true;
        for (int i = L; i < n; ++i) {
            if (s[i] != s[i % L]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            std::cout << L << ' ';
            std::cout.write(s.data(), L);
            std::cout << '\n';
            return 0;
        }
    }

    return 0;
}
