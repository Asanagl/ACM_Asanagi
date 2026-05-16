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

bool find_b (vector <vector <char>> &vvc , int n , int m)
{
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < m ; j++)
        {
            if (vvc[i][j] == 'B')
            {
                return true ;
            }
        }
    }
    return false ;
}
void Asanagi()
{
    int n , m , r ,c  ;
    cin >> n >> m >> r >> c ;
    vector <vector <char>> vvc (n,vector <char> (m)) ;
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < m ; j++)
        {
            cin >> vvc[i][j] ;
        }
    }
    if (vvc[r-1][c-1] == 'B')
    {
        cout << 0 << endl ;
        return ;
    }
    if (!find_b(vvc,n,m)))
    {
        cout << -1 << endl ;
        return ;
    }
    else
    {
        for (int i = 0 ; i < n ; i++)
        {
            if (vvc[i][c-1] == 'B')
            {
                cout << 1 << endl ;
                return ;
            }
        }
        for (int j = 0 ; j < m ; j++)
        {
            if (vvc[r-1][j] == 'B')
            {
                cout << 1 << endl ;
                return ;
            }
        }
        cout << 2 << endl ;
        return ;
    }
}

signed main()
{
    IOS;
    int t ;
    cin >> t;
    while (t--)
    {
            Asanagi();
        }
    return 0;
}