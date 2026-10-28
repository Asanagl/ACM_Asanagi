#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (auto &it : v) {
        cin >> it;
    }
    long long sum_win = 0;
    for (int i = 0; i < k; i++) {
        sum_win += v[i];
    }
    long long sum = sum_win;
    int s = 0; 
    for (int i = 1; i < n; i++) {
        sum_win -= v[i - 1];
        int j = (i + k - 1) % n;
        sum_win += v[j];
        if (sum_win > sum) {
            sum = sum_win;
            s = i;
        }
    }
    cout << sum << " " << s + 1 << endl;
    return 0;
}