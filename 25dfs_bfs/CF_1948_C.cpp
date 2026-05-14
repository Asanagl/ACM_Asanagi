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
int n , m ;

int change(int num) {
    int d4 = num % 10; num /= 10;
    int d3 = num % 10; num /= 10;
    int d2 = num % 10; num /= 10;
    int d1 = num;
    return (d1 - 1) * 729 + (d2 - 1) * 81 + (d3 - 1) * 9 + (d4 - 1);
}

void solve()
{
    cin >> n >> m ;
    
}

signed main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}