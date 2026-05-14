#include <iostream>
using namespace std;
#define int long long
void solve()
{
    int n, m;
    cin >> n >> m;
    if (n == 1 || m == 1) {
        cout << 1 << endl;
    } else if (n == 2) {
        cout << (m + 1) / 2 << endl;
    } else if (m == 2) {
        cout << (n + 1) / 2 << endl;
    } else if (n == 3 && m == 3) {
        cout << 8 << endl;
    } else {
        cout << n * m << endl;
    }
}

signed main() 
{
    int t = 1;
//     cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}