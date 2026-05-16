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
    int a, b;
    cin >> a >> b;
    if (b == 0)
    {
        cout << string(a, '0') << endl;
        return;
    }
    if (a == 0)
    {
        cout << string(b, '1') << endl;
        return;
    }
    int k = min(b, a + 1);
    int q = b / k;
    int r = b % k;
    int temp = a - (k - 1);
    int q0 = temp / (k + 1);
    int r0 = temp % (k + 1);
    vector<int> diff(k + 1, 0);
    for (int j = 0; j <= k; ++j)
    {
        int ba = (j >= 1 && j <= k - 1) ? 1 : 0;
        int ex = (j < r0) ? 1 : 0;
        diff[j] = ba + q0 + ex;
    }
    string s;
    s.append(diff[0], '0');
    for (int i = 0; i < k; i++)
    {
        s.append(q + (i < r ? 1 : 0), '1');
        s.append(diff[i + 1], '0');
    }
    cout << s << endl;
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