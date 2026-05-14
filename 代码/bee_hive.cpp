#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 1e4+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

using ll = long long ;

int ans[11];
int n;
void dfs(int row, int col, int d1, int d2) {
    if (row == n) {
        ans[n]++;
        return;
    }
    int vaild = ((1 << n) - 1) & ~(col | d1 | d2);
    while (vaild) 
    {
        int pos = vaild & -vaild; 
        vaild -= pos;                
        dfs(row + 1, col | pos, 
            (d1 | pos) << 1,       
            (d2 | pos) >> 1);        
    }
}
signed main() 
{
    memset(ans, 0, sizeof(ans));


    for (int i = 1; i <= 10; i++) {
        n = i;
        dfs(0, 0, 0, 0);
    }
    while (cin >> n && n != 0) {
        cout << ans[n] << endl;
    }
}