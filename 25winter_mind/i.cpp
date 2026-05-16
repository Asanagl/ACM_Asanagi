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
    int cnt1 = 0, cnt2 = 0;

    int n;
    cin >> n;
    vector<int> odd(n + 1), even(n + 1);
    for (int i = 0; i < n * 2; i++)
    {
        int x;
        cin >> x;
        if (x % 2 == 0)
            even[++cnt2] = i + 1;
        else
            odd[++cnt1] = i + 1;
    }
    if (cnt1 % 2 == 0)
    {
        if (cnt1 > cnt2)
            cnt1 -= 2;
        else
            cnt2 -= 2;
    }
    for (int i = 1; i < cnt1; i += 2)
    {
        cout << odd[i] << ' ' << odd[i + 1] << endl;
    }
    for (int i = 1; i < cnt2; i += 2)
    {
        cout << even[i] << ' ' << even[i + 1] << endl;
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