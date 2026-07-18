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
int R[10] , S[10] ,P[10] ;  // 0 -> R ; 1 -> S ; 2 -> P
int out[10][3] , nout[10] , hid[4][4];
ld dp[2][205] , memo[205][105] ;
inline int score(int a, int b )
{
    if (a == b ) return 1 ;
    if ((a == 0 && b == 1) || (a == 1 && b == 2 ) || (a == 2 && b == 0) ) return 3 ;
    else return 0 ;
}
inline int trans (int id,int c ,int nc)
{
    int r = R[id] , s = S[id] , p = P[id] ;
    c == 0 ? --r : (c==1 ? --s : --p) ;
    nc == 0 ? ++r : (nc == 1 ? ++s : ++p) ;
    return hid[r][s] ;
}
void Asanagi()
{

    memset(hid, -1, sizeof(hid));
    for (int r = 0, idx = 0; r <= 3; ++r)
        for (int s = 0; s <= 3 - r; ++s)
        {
            int p = 3 - r - s;
            R[idx] = r;
            S[idx] = s;
            P[idx] = p;
            hid[r][s] = idx;
            if (r)
                out[idx][nout[idx]++] = 0;
            if (s)
                out[idx][nout[idx]++] = 1;
            if (p)
                out[idx][nout[idx]++] = 2;
            idx++;
        }

    for (int t = 1; t <= 200; ++t)
    {
        int c = t & 1, p = c ^ 1;
        for (int st = 0; st < 100; ++st)
        {
            int ha = st / 10, hb = st % 10;
            ld best = -1e300;
            for (int i = 0; i < nout[ha]; ++i)
            {
                int ca = out[ha][i];
                ld worst = 1e300;
                for (int j = 0; j < nout[hb]; ++j)
                {
                    int cb = out[hb][j];
                    ld s = 0;
                    for (int na = 0; na < 3; ++na)
                        for (int nb = 0; nb < 3; ++nb)
                            s += dp[p][trans(ha, ca, na) * 10 + trans(hb, cb, nb)];
                    worst = min(worst, score(ca, cb) + s / 9.0);
                }
                best = max(best, worst);
            }
            memo[t][st] = dp[c][st] = best;
        }
    }
    ld C = memo[200][0] - memo[199][0];
    ld off[100];
    for (int i = 0; i < 100; ++i)
        off[i] = memo[200][i] - 200 * C;

    int T;
    cin >> T;
    while (T--)
    {
        int k;
        string a, b;
        cin >> k >> a >> b;
        vector <int> ca (3 , 0) , cb(3 , 0) ;
        for (auto &it : a)
            ++ca[it == 'R' ? 0 : (it == 'S' ? 1 : 2)];
        for (auto &it : b)
            ++cb[it == 'R' ? 0 : (it == 'S' ? 1 : 2)];
        // for (int i = 0 ; i < 3 ; i++) cout << ca[i] << endl ;
        int st = hid[ca[0]][ca[1]] * 10 + hid[cb[0]][cb[1]];
        ld ans = (k <= 200) ? memo[(int)k][st] : k * C + off[st];
        cout << fixed << setprecision(20) << ans << endl;
    }
}

signed main()
{
    IOS;
    Asanagi();
    return 0;
}
