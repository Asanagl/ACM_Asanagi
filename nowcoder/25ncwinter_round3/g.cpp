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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    int sum1 = 0, sum2 = 0;
    for (auto &i : a)
    {
        cin >> i;
        sum1 += i;
    }
    for (auto &i : b)
    {
        cin >> i;
        sum2 += i;
    }
    if (sum1 == sum2)
    {
        cout << 1 << endl;
    }
    else if (sum1 > sum2)
    {
        int diff = sum1 - sum2;
        sort(a.begin(), a.end(), greater<int>());
        int temp = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            temp += a[i];
            cnt++;
            if (temp >= diff)
            {
                cout << cnt << endl;
                break;
            }
        }
    }
    else
    {
        int diff = sum2 - sum1;
        sort(b.begin(), b.end(), greater<int>());
        int temp = 0, cnt = 0;
        for (int i = 0; i < m; i++)
        {
            temp += b[i];
            cnt++;
            if (temp >= diff)
            {
                cout << cnt << endl;
                break;
            }
        }
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