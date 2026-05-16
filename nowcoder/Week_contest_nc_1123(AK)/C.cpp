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

vector<int> valid_nums;

void preprocess() {
    for (int i = 1; i <= 100000; i++) {
        int square = i * i;
        int digit_sum = 0;
        int temp = square;
        while (temp > 0) {
            digit_sum += temp % 10;
            temp /= 10;
        }
        if (digit_sum == i) {
            valid_nums.push_back(i);
        }
    }
}

void Asanagi()
{
    int l, r;
    cin >> l >> r;
    int left_pos = lower_bound(valid_nums.begin(), valid_nums.end(), l) - valid_nums.begin();
    int right_pos = upper_bound(valid_nums.begin(), valid_nums.end(), r) - valid_nums.begin();
    cout << right_pos - left_pos << endl;
}

signed main()
{
    IOS;
    preprocess();
    int t;
    cin >> t;
    while (t--)
    {
        Asanagi();
    }
    return 0;
}