#include <bits/stdc++.h> 
using namespace std ;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back 
using ll = long long ;
const int INF = 1e9+10 ;
const int LINF = 1e12+10 ;
void Asanagi ()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v) cin >> it ;
    sort(v.begin(), v.end());
    int mid = (n - 1) / 2;        
    int m = v[mid];
    int L = 0, E = 0, G = 0;
    for (auto &it : v) {
        if (it < m) ++L;
        else if (it == m) ++E;
        else ++G;
    }
    if (L == 0 && G == 0) {
        cout << -1 << endl;
    } else {
        int unans = max(2 * L, 2 * G - 1);
        cout << n - unans << endl;
    }。
}
signed main ()
{
    IOS;
    int t ;
    t = 1 ;
    while (t--)
    {
        Asanagi ();
    }
}
