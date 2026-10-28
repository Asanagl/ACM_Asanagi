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
    int n;
    cin >> n;
    vector<int> A0, A1, A2, A3;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        if (a % 4 == 0) A0.push_back(i);
        else if (a % 4 == 1) A1.push_back(i);
        else if (a % 4 == 2) A2.push_back(i);
        else if (a % 4 == 3) A3.push_back(i);
    }

    int c1 = A1.size();
    int c2 = A2.size();
    int c3 = A3.size();

    if (c1 > 2 * c2 + c3 || c3 > 2 * c2 + c1) {
        cout << -1 << endl;
        return;
    }

    vector<int> ans;
    for (int x : A0) ans.push_back(x);

    while (c1 > 0 && c3 > 0) {
        ans.push_back(A3.back()); A3.pop_back(); c3--;
        ans.push_back(A1.back()); A1.pop_back(); c1--;
    }

    if (c1 == 0) {
        while (c2 > 0 && c3 >= 2) {
            ans.push_back(A3.back()); A3.pop_back(); c3--;
            ans.push_back(A3.back()); A3.pop_back(); c3--;
            ans.push_back(A2.back()); A2.pop_back(); c2--;
        }
        while (c2 >= 2) {
            ans.push_back(A2.back()); A2.pop_back(); c2--;
            ans.push_back(A2.back()); A2.pop_back(); c2--;
        }
    } 
    else if (c3 == 0) {
        while (c2 > 0 && c1 >= 2) {
            ans.push_back(A2.back()); A2.pop_back(); c2--;
            ans.push_back(A1.back()); A1.pop_back(); c1--;
            ans.push_back(A1.back()); A1.pop_back(); c1--;
        }
        while (c2 >= 2) {
            ans.push_back(A2.back()); A2.pop_back(); c2--;
            ans.push_back(A2.back()); A2.pop_back(); c2--;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
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
