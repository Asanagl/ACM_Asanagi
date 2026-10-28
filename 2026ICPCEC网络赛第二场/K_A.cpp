#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <chrono>

using namespace std;

// 自定义 Hash 函数，防止在 Codeforces 等平台上被 Hash 双重抗冲测试卡到 O(N^2)
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int n;
    if (!(cin >> n)) return;

    unordered_map<int, int, custom_hash> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    // 1. 求初始 mex
    int mex = 0;
    while (cnt.count(mex)) {
        mex++;
    }

    // 2. 收集前 n + 1 个缺失数
    vector<int> missing;
    missing.reserve(n + 1);
    for (int x = mex; missing.size() <= (size_t)n; x++) {
        if (!cnt.count(x)) {
            missing.push_back(x);
        }
    }

    int q;
    cin >> q;

    unordered_map<int, int, custom_hash> memo; // 记忆化重复的 k 查询
    unordered_map<int, int, custom_hash> used; // 记录单次查询中被借用的配额
    int ans = 0;

    while (q--) {
        int k;
        cin >> k;

        if (memo.count(k)) {
            ans ^= memo[k];
            continue;
        }

        used.clear();
        int res = mex;

        for (int m : missing) {
            int need_val = k - m;
            int available = (cnt.count(need_val) ? cnt[need_val] : 0) - (used.count(need_val) ? used[need_val] : 0);

            // 如果 need_val <= m，由于之前已经消耗了 1 个，需要剩余可用数量 >= 2
            // 如果 need_val > m，只需剩余可用数量 >= 1
            int required = (need_val <= m) ? 2 : 1;

            if (available >= required) {
                used[need_val]++;
            } else {
                res = m;
                break;
            }
        }

        memo[k] = res;
        ans ^= res;
    }

    cout << ans << "\n";
}

int main() {
    // 开启 Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}