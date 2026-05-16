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

void Asanagi()
{
    string s;
    cin >> s;
    int n = s.size();
    if (n == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        bool found = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                found = true;
                break;
            }
        }
        cout << (found ? 1 : n) << endl;
    }
}

signed main()
{
    IOS;
    int t;
    // t = 1 ;
    cin >> t;
    while (t--)
    {
            Asanagi();
        }
    return 0;
}