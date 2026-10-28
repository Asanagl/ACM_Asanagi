#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    if (!(cin >> n >> s)) {
        return 0;
    }

    int answer = 0;
    int left = 0;
    int right = n - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            ++answer;
        }
        ++left;
        --right;
    }

    cout << answer << '\n';
    return 0;
}
