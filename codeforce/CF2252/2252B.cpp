#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define PII pair<int,int>
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;

void Asanagi()
{
    int n ;
    cin >> n ;
    string s;
    cin >> s ;
    unordered_map<char , int> ump ;
    unordered_map<char , int> cpm ;
    for (auto &it : s) 
    {
        ump[it]++ ;
    }
    int d = ump['1'] - ump['0'] ;
    if (abs(d) > 2)
    {
        cout << -1 << endl; 
        return ;
    }
    string str = "" ;
    str+=s[0] ;
    for (int i = 1 ; i < n ; i ++)
    {
        if (s[i] != s[i-1]) str+=s[i] ;
    }
    for (auto &it : str)
    {
        cpm[it]++ ;
    }
    // cout << str << endl ;
    int d1 = cpm['1'] - cpm['0'] ;
    int ans = (n - str.size()) + max(0LL, abs(d1 - d) - 1);
    cout << ans <<endl ;
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
