#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

string CHILD = "child";
string WOMAN = "woman";
string MAN = "man";
string RAT = "rat";

struct solar
{
    string name ;
    int idf ;
    int idx ;
};
void solve()
{
    int n  ;
    cin >> n ;
    vector<solar> v(n) ;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> v[i].name ;
        string TYPE ;
        cin >> TYPE ;
        if (TYPE == RAT) v[i].idf = 1 ;
        else if (TYPE == CHILD || TYPE == WOMAN) v[i].idf = 2 ;
        else if (TYPE == MAN) v[i].idf = 3 ;
        else v[i].idf = 4 ;
        v[i].idx = i+1 ;
    }
    sort (v.begin(), v.end(), [](const solar& x, const solar& y) {
        if (x.idf != y.idf) return x.idf < y.idf;
        return x.idx < y.idx;
    }); 
    for (int i = 0 ; i < n ; i++)
    {
        cout << v[i].name << endl ;
    }
}




signed main()
{
    IOS;
    int t =1;
    // cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}

