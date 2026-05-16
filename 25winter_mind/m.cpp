#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define ll long long
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

void Asanagi()
{
    int n, l, r;
    cin >> n >> l >> r;
    l--;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> brr(arr.begin(), arr.begin() + l);
    vector<int> temp1(arr.begin() + l, arr.end());
    sort(temp1.begin(), temp1.end());
    brr.insert(brr.end(), temp1.begin(), temp1.end());
    vector<int> temp2(arr.begin(), arr.begin() + r);
    sort(temp2.rbegin(), temp2.rend()); 
    vector<int> crr(temp2.begin(), temp2.end());
    crr.insert(crr.end(), arr.begin() + r, arr.end());
    ull sumb = 0, sumc = 0;
    for (int i = l; i < r; i++) {
        sumb += brr[i];
        sumc += crr[i];
    }
    
    cout << min(sumb, sumc) << endl;
}

signed main()
{
    IOS;
    int t;
    // t = 1 ;
    cin >> t;
    while (t--)
    {
            Asanagi();
        }
    return 0;
}