#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int tt;
    std::cin >> tt;

    while (tt--) {
        int n;
        std::cin >> n;

        std::string s;
        std::cin >> s;

        int cnt = std::count(s.begin(), s.end(), '0');
        if (cnt == 0 || cnt == 1 && s.back() != '0') {
            std::cout << -1 << "\n";
        } else {
            std::vector<int> link = {1}, circle;
            for (int i = 0; i < n - 2; i++) {
                if (s[i] == '1') {
                    link.push_back(i + 2);
                } else {
                    circle.push_back(i + 2);
                }
            }
            link.push_back(n);

            std::set<std::array<int, 2>> ans;
            for (int i = 0; i + 1 < link.size(); i++) {
                ans.insert({link[i], link[i + 1]});
            }
            for (int i = 0; i + 1 < circle.size(); i++) {
                ans.insert({circle[i], circle[i + 1]});
            }
            ans.insert({1, circle.front()});
            ans.insert({1, circle.back()});

            std::cout << ans.size() << "\n";
            for (auto [u, v] : ans) {
                std::cout << u << " " << v << "\n";
            }
        }
    }
}