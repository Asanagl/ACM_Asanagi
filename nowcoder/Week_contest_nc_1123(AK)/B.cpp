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

void Asanagi()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    int min_val = *min_element(a.begin(), a.end());
    int max_val = *max_element(a.begin(), a.end());
    
    cout << max_val - min_val << endl;
}

signed main() {
    IOS;
    int t;
    cin >> t;
    while (t--) {
        Asanagi();
    }
    return 0;
}