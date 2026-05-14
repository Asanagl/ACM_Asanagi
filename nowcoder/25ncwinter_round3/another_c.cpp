#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define ll long long
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

//“在十年前，天空降下了众人习以为常的雨水。
// 一滴又一滴，像断了线的珍珠。
// 一场永远下不完的雨，突然笼罩在了上空。
// 如今宇宙普遍将这场不间断的雨称为——无尽之雨。”

vector<char> inverted_world(const string &s, int beginc)
{
    vector<char> res;
    int n = s.size();
    for (int i = 0; i < n; ++i)
    {
        char temp = (i % 2 == 0) ? ('0' + beginc) : ('0' + 1 - beginc);
        if (s[i] != temp)
            res.push_back(s[i]);
    }
    return res;
}
void ARForest()
{
    string s;
    cin >> s;
    auto flips0 = inverted_world(s, 0);
    auto flips1 = inverted_world(s, 1);
    int endl0 = 0, endr0 = 0;
    for (char c : flips0)
    {
        if (c == '0')
        {
            if (endr0)
            {
                --endr0;
                ++endl0;
            }
            else
                ++endl0;
        }
        else
        {
            if (endl0)
            {
                --endl0;
                ++endr0;
            }
            else
                ++endr0;
        }
    }
    int endl1 = 0, endr1 = 0;
    for (auto c : flips1)
    {
        if (c == '0')
        {
            if (endr1)
            {
                --endr1;
                ++endl1;
            }
            else
                ++endl1;
        }
        else
        {
            if (endl1)
            {
                --endl1;
                ++endr1;
            }
            else
                ++endr1;
        }
    }
    cout << min(endl0 + endr0, endl1 + endr1) << endl;
}

signed main()
{
    IOS;
    int t;
    // t = 1 ;
    cin >> t;
    while (t--)
    {
            ARForest();
        }
    return 0;
}