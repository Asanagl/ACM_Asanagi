#include <bits/stdc++.h>
using namespace std;


#define ld long double
bool check(ld t, ld n, ld x1, ld v1, ld x2, ld v2) 
{
    ld l1 = max(0.0L, x1 - v1 * t);
    ld r1 = min(n, x1 + v1 * t);
    ld l2 = max(0.0L, x2 - v2 * t);
    ld r2 = min(n, x2 + v2 * t);
    ld left = min(l1, l2);
    ld right = max(r1, r2);
    return left <= 0 && right >= n;
}

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        ld n;
        cin >> n;
        ld x1, v1, x2, v2;
        cin >> x1 >> v1 >> x2 >> v2;
        ld left = 0.0, right = 2 * n;
        for (int i = 0; i < 100; i++) 
        { 
            ld mid = (left + right) / 2.0;
            if (check(mid, n, x1, v1, x2, v2)) right = mid;
                else left = mid;
        }
        cout << fixed << setprecision(10) << left << endl;
    }
}