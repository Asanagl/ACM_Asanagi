#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<long long> seen;
    vector<long long> crt_check;

    for (int i = 0; i < n; ++i) {
        crt_check.clear();
        vector<long long> newhash;

        for (int j = 0; j < m; ++j) {
            long long hash_val;
            cin >> hash_val;
            crt_check.push_back(hash_val);
        }

        for (long long h : crt_check) {
            if (seen.find(h) == seen.end()) {
                newhash.push_back(h);
                seen.insert(h);
            }
        }

        sort(newhash.begin(), newhash.end());
        for (int idx = 0; idx < newhash.size(); ++idx) {
            if (idx > 0) cout << " ";
            cout << newhash[idx];
        }
        cout << endl;
    }

    return 0;
}