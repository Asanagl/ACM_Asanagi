#include <bits/stdc++.h>

using namespace std;

// 思路层错解：误解输出语义，输出五个元音的总次数而不是各自的次数。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) {
        return 0;
    }

    long long total = 0;
    for (char c : s) {
        switch (c) {
            case 'a': case 'A':
            case 'e': case 'E':
            case 'i': case 'I':
            case 'o': case 'O':
            case 'u': case 'U':
                ++total;
                break;
            default:
                break;
        }
    }

    cout << total << '\n';
    return 0;
}
