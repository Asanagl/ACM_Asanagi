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

void Asanagi() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    if (a == b) {
        cout << 0 << '\n';
        return ;
    }
    int cntA = 0, cntB = 0;
    for (int x : a)
        cntA += x;
    for (int x : b)
        cntB += x;
    if (cntA == 0) {
        cout << -1 << '\n';
        return ;
    }
    if (cntB == n) {
        cout << -1 << '\n';
        return ;
    }
    int ANS = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1 && b[i] == 0)
            ANS++;
    }
    cout << (ANS % 2 == 1 ? 1 : 2) << endl;
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
