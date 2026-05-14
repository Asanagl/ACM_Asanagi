#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> pos_a, pos_b;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                pos_a.push_back(i);
            } else {
                pos_b.push_back(i);
            }
        }

        long long ans_a = 0;
        int k_a = pos_a.size();
        if (k_a > 0) {
            vector<long long> p_a;
            for (int i = 0; i < k_a; i++) {
                p_a.push_back(pos_a[i] - i);
            }
            sort(p_a.begin(), p_a.end());
            long long mid = p_a[k_a / 2];
            for (long long x : p_a) {
                ans_a += abs(x - mid);
            }
        }

        long long ans_b = 0;
        int k_b = pos_b.size();
        if (k_b > 0) {
            vector<long long> p_b;
            for (int i = 0; i < k_b; i++) {
                p_b.push_back(pos_b[i] - i);
            }
            sort(p_b.begin(), p_b.end());
            long long mid = p_b[k_b / 2];
            for (long long x : p_b) {
                ans_b += abs(x - mid);
            }
        }

        cout << min(ans_a, ans_b) << endl;
    }
    return 0;
}