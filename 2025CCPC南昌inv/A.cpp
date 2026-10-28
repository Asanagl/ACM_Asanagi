#include <bits/stdc++.h>
using namespace std;
#define int long long 

#define MaxSize 100
typedef struct{
    ElemType data[MaxSize];
    int length;
}SqList;

int ListInsert_Sq(SqList &L, int i, ElemType e)
{
    if(i < 1 || i > L.length + 1)
        return 0;
    if(L.length >= MaxSize)
        return 0;
    for(int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return 1;
}



void solve() {
    int n;
    int k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    auto check = [&](int x) -> bool {
        int sum = 0;
        for (int p = 1; p <= n; ++p) {
            sum += a[p - 1];
            if (sum >= x) {
                int m = n - p;
                if (x < m * (k - 1) + n) {
                    return false;
                }
            }
        }
        return true;
    };
    int low = 1, high = 1e18, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t ;
        while (t--) {
            solve();
        }
    
    return 0;
}
