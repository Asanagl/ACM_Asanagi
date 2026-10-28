#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    if (!(std::cin >> s)) {
        std::cout << "0 0 0 0 0\n";
        return 0;
    }

    long long cnt[5] = {0, 0, 0, 0, 0};

    for (char ch : s) {
        char l = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
        switch (l) {
            case 'a': ++cnt[0]; break;
            case 'e': ++cnt[1]; break;
            case 'i': ++cnt[2]; break;
            case 'o': ++cnt[3]; break;
            case 'u': ++cnt[4]; break;
            default: break;
        }
    }

    std::cout << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << ' '
              << cnt[3] << ' ' << cnt[4] << '\n';
    return 0;
}
