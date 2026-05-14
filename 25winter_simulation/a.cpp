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
    int m ;
    cin >> m ;
    vector <vector<char>> vc (m , vector<char> (4)) ;
    for (int i = 0 ; i < m ; i++)
    {
        for (int j = 0 ; j < 4 ; j++)
        {
            cin >> vc[i][j] ;
        }
    }
    for (int i = m-1 ; i >= 0 ; i--)
    {
        for (int j = 0 ; j < 4 ; j++)
        if (vc[i][j] == '#')
        cout << j+1 << " ";
    }
    cout << endl ;

}

signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}