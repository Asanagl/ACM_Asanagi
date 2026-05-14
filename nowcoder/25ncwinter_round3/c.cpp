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

void ARForest()
{
    string s;
    cin >> s;
    int n = s.size();
    bool tri = true;
    for (int i = 0; i < n - 1; ++i)
    {
        if (s[i] == s[i + 1])
        {
            tri = false;
            break;
        }
    }
    if (tri)
    {
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i <= 1; ++i)
    {
        vector<int> x(n, 0);
        x[0] = i;
        for (int j = 0; j < n - 1; ++j)
        {
            if (s[j] == s[j + 1])
            {
                x[j + 1] = x[j] ^ 1;
            }
            else
            {
                x[j + 1] = x[j];
            }
        }
        vector<int> slidei;
        for (int j = 0; j < n; ++j)
        {
            if (x[j] == 1)
                slidei.push_back(j);
        }

        if (slidei.empty())
            continue;
        bool yon_valid = true;
        for (int j = 0; j < (int)slidei.size() - 1; ++j)
        {
            if (s[slidei[j]] == s[slidei[j + 1]])
            {
                yon_valid = false;
                break;
            }
        }

        if (yon_valid)
        {
            cout << 1 << endl;
            return;
        }
    }
    cout << 2 << endl;
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