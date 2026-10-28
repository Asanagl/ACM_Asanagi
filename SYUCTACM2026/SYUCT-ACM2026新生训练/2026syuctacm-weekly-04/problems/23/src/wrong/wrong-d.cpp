// 【已从 wrongSolutions 移除，仅作记录保留，不参与验题】
// 本实现原本打算作为"复杂度层"超时错解：每修复一对就重新扫描整串判断回文。
// 但实测表明它是正确的——失配对的修复顺序由外向内，isPalindrome 只有在全部
// 失配对修完后才返回真，因此 break 不会提前触发，答案与主解一致。
// 其最坏复杂度 O(n^2)，在 n=2e5 的上限用例上约 1.29s，低于本地验题器
// 3 倍时限（3000ms）的超时阈值，无法稳定击杀，故不注册为错解。
#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(const string& s) {
    int n = static_cast<int>(s.size());
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    if (!(cin >> n >> s)) {
        return 0;
    }

    int answer = 0;
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - 1 - i]) {
            s[n - 1 - i] = s[i];
            ++answer;
            if (isPalindrome(s)) {
                break;
            }
        }
    }
    cout << answer << '\n';
    return 0;
}
