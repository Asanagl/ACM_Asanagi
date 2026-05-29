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

void Asanagi()
{
    int n ;
    cin >> n ;
    vector <PII> v (4*n + 2) ;
    for (int i = 1 ; i <= 4 * n ; i ++ )
    {
        cin >> v[i].first ;
        char ch ;
        cin >> ch ;
        if (ch == 'B') v[i].second = 4 ;
        else if (ch == 'G') v[i].second = 3 ;
        else if (ch == 'Y') v[i].second = 2 ;
        else v[i].second = 1;
    }
    PII temp ;
    bool flag = true ; 
    bool tri = true ;
    for (int i = 1 ; i <= 4 * n  ; i++)
    {
        for (int j = 1 ; j <= 4 * n  - i ; j++)
        {
            flag = true ;
            
            
            if (v[j].second > v[j+1].second && (v[j].first == v[j+1].first) )
            {
                temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
				flag = true;
            }
            if (v[j].first > v[j+1].first && (v[j].second == v[j+1].second) )
            {
                temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
				flag = true;
            }
        
        }
        if(!flag) break;
    }
    for (int i = 0 ; i <= 3 ; i ++)
    {
        for (int j = 1 ; j < n ; j++)
        {
            int idx = j + i*n ;
            if (!(v[idx].first <= v[idx+1].first && v[idx].second == v[idx+1].second))
            {
                cout << "No" << endl ;
                return;
            }
        }
    }
    if (n==1) 
    {
        for (int i = 1 ; i < 4*n ; i++)
        {
            if (v[i].second > v[i+1].second)
            {
                cout << "No" << endl ;
                return ;
            }
        }
    }
    cout << "Yes" << endl ;
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
