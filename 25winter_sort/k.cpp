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

struct patient
{
    string ID ;
    int age ;
    int id ;
};
bool cmp(   const patient &a, const patient &b) {
    bool a_older = a.age >= 60;
    bool b_older = b.age >= 60;
    if (a_older && b_older  ) 
    {
        if (a.age != b.age) {
            return a.age > b.age;
        }
        return a.id < b.id;
    }
    if (!a_older && !b_older) {
        return a.id < b.id;
    }
    return a_older && !b_older;
}

void Asanagi()
{   
    int n ;
    cin >> n ;
    vector <patient> v(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> v[i].ID >> v[i].age ;
        v[i].id = i + 1 ;
    }
    sort (v.begin(), v.end(), cmp) ;
    for (const auto &it : v) cout << it.ID << endl;
    return ;
}




signed main()
{
    IOS;
    int t =1;
    // cin >> t;
    while (t--)
    {
            Asanagi();
        }
    return 0;
}

