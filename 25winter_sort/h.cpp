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

struct student {
    int id;
    int score;
};
bool cmp(const student& a, const student& b) 
{
    if (a.score != b.score) {
        return a.score > b.score; 
    }
    return a.id < b.id; 
}



void Asanagi()
{    int n, m;
    cin >> n >> m;
    vector<student> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].id >> v[i].score;
    }
    sort(v.begin(), v.end(), cmp);
    int targer = m * 3 / 2;  
    int kira_line = v[targer - 1].score;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].score >= kira_line) {
            count++;
        } else {
            break;  
        }
    }
    cout << kira_line << " " << count << endl;
    for (int i = 0; i < count; i++) {
        cout << v[i].id << " " << v[i].score << endl;
    }
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

