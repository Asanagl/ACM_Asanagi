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


struct date
{
    string name ;
    int year ;
    int mouth ;
    int day ;
    int id ;
};
void Asanagi()
{
    int n ;
    cin >> n ;
    vector <date> v(n);
    for (int i = 0; i < n; i++) v[i].id = i + 1;
    for (auto &it : v) cin >> it.name >> it.year >> it .mouth >> it.day ;
    sort(v.begin(), v.end(), [](date a, date b) {
        if (a.year != b.year) return a.year < b.year;
        if (a.mouth != b.mouth) return a.mouth < b.mouth;
        if (a.day != b.day) return a.day < b.day;
        return a.id > b.id;
    });
    for (auto it : v) cout << it.name << endl ;
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

