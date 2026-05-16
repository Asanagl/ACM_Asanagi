#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;

void Asanagi()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    
    char r = str[0];
    char l = str[str.size() - 1];
    
    // 所有字符都相同
    bool allSame = true;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != r) allSame = false;
    }
    if (allSame) {
        cout << str << endl;
        return;
    }
    
    // 首尾不同，可以删除整个字符串
    if (r != l) {
        cout << "empty" << endl;
        return;
    }
    
    // 首尾相同且为'1'
    if (r == '1') {
        // 检查是否有"00"子串
        bool has00 = false;
        for (int i = 0; i < str.size() - 1; i++) {
            if (str[i] == '0' && str[i+1] == '0') {
                has00 = true;
                break;
            }
        }
        if (has00) {
            cout << "empty" << endl;
            return;
        }
        // 没有"00"，找最短的连续1段
        string ans = "";
        int i = 0;
        while (i < str.size()) {
            if (str[i] == '1') {
                string cur = "";
                while (i < str.size() && str[i] == '1') {
                    cur += str[i];
                    i++;
                }
                if (ans == "" || cur.size() < ans.size()) {
                    ans = cur;
                }
            } else {
                i++;
            }
        }
        cout << ans << endl;
    }
    // 首尾相同且为'0'
    else {
        // 检查是否有"11"子串
        bool has11 = false;
        for (int i = 0; i < str.size() - 1; i++) {
            if (str[i] == '1' && str[i+1] == '1') {
                has11 = true;
                break;
            }
        }
        if (has11) {
            cout << "empty" << endl;
            return;
        }
        // 没有"11"，找最短的连续0段
        string ans = "";
        int i = 0;
        while (i < str.size()) {
            if (str[i] == '0') {
                string cur = "";
                while (i < str.size() && str[i] == '0') {
                    cur += str[i];
                    i++;
                }
                if (ans == "" || cur.size() < ans.size()) {
                    ans = cur;
                }
            } else {
                i++;
            }
        }
        cout << ans << endl;
    }
}

signed main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
    {
        Asanagi();
    }
    return 0;
}
