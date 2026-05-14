#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define int long long
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
void solve() 
{
    long long l, r;
    cin >> l >> r;
    long long total = r - l + 1;
    long long inti = total / 3;
    long long dick = total % 3;
    long long a = inti, b = inti, c = inti;
    int smod = l % 3;

    if (dick >= 1) 
    {
        if (smod == 1) a++;
        else if (smod == 2) b++;
        else c++; 
    }
    if (dick >= 2) 
    {
        if (smod == 1) b++;
        else if (smod == 2) c++;
        else a++;  
    }
    cout << a << " " << b << " " << c << endl;
}
signed main()
{
    IOS;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}