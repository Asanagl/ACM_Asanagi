#include<bits/stdc++.h>
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
using ll = long long;



const int N = 1005;

bool d[N][N];
int in[N], out[N], num[N];

void Asanagi()
{
    int n, i, ans = 0, a;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> num[i];
        cin >> out[num[i]];
        for(int j = 1; j <= out[num[i]]; j++)
        {
            cin >> a;
            d[num[i]][a] = 1;
            in[a]++;
        }
    }
    for(int k = 1; k <= n; k++)
    {
        for(i = 1; i <= n && in[num[i]]; i++);
        if(i == n + 1) break;
        i = num[i];
        ++ans;
        in[i] = -1;
        for(int j = 1; j <= n; j++)
        {
            if(d[i][num[j]])
            {
                d[i][num[j]] = 0;
                in[num[j]]--;
            }
        }
    }
    ans = n - ans;
    if(!ans) cout << "YES" << endl;
    else cout << ans << endl;
}

signed main()
{
    IOS;
    int t = 1;
    while(t--)
    {
        Asanagi();
    }
    return 0;
}