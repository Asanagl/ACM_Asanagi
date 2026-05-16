#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define int long long
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
const int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int ind[101];
int mask[101];

bool insert(int x, int base[])
{
    for (int i = 24; i >= 0; --i)
    {
        if ((x >> i) & 1) {
            if (base[i]) {
                x ^= base[i];
            } else {
                base[i] = x;
                return true;
            }
        }
    }
    return false;
}
void init() {
    for (int i = 0; i < 25; ++i) {
        ind[primes[i]] = i;
    }
    for (int x = 1; x <= 100; ++x) {
        int mask_hrk = 0;
        int temp = x;
        for (int p : primes) {
            if (p > temp) break;
            int cnt = 0;
            while (temp % p == 0) {
                temp /= p;
                ++cnt;
            }
            if (cnt & 1) {
                mask_hrk |= (1 << ind[p]);
            }
        }
        mask[x] = mask_hrk;
    }
}

void Asanagi()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> m(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        m[i] = mask[a[i]];
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        --l;
        --r; // 构建索引为0-indexed
        int len = r - l + 1;
        if (len > 25)
        {
            cout << "Yes" << endl;
            continue;
        }
        bool has_zero = false;
        for (int i = l; i <= r; ++i)
        {
            if (m[i] == 0)
            {
                has_zero = true;
                break;
            }
        }
        if (has_zero)
        {
            cout << "Yes" << endl;
            continue;
        }
        int base[25] = {0};
        bool Izayoi_Sakuya = false;
        for (int i = l; i <= r; ++i)
        {
            if (!insert(m[i], base))
            {
                Izayoi_Sakuya = true;
                break;
            }
        }
        cout << (Izayoi_Sakuya ? "Yes"  : "No") << endl;
    }
}
signed main()
{
    IOS;
    int t = 1;
    // cin >> t;
    init();
    while (t--)
    {
        Asanagi();
    }
    return 0;
}
