#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<long long> seen;
    vector<long long> current_check;

    for (int i = 0; i < n; ++i) {
        current_check.clear();
        vector<long long> new_hashes;

        for (int j = 0; j < m; ++j) {
            long long hash_val;
            cin >> hash_val;
            current_check.push_back(hash_val);
        }

        for (long long h : current_check) {
            if (seen.find(h) == seen.end()) {
                new_hashes.push_back(h);
                seen.insert(h);
            }
        }

        sort(new_hashes.begin(), new_hashes.end());
        for (int idx = 0; idx < new_hashes.size(); ++idx) {
            if (idx > 0) cout << " ";
            cout << new_hashes[idx];
        }
        cout << endl;
    }

    return 0;
}