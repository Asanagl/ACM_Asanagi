#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    int M;
    cin >> N >> M;
    vector<int> R(M), C(M);
    for (int i = 0; i < M; ++i) {
        cin >> R[i] >> C[i];
    }
    unordered_map<int, int> finr, finc;
    for (int i = 0; i < M; i++) {
        finr[R[i]] = i;
        finc[C[i]] = i;
    }
    int ans = 0;
    for (int i = 0; i < M; i++) {
        if (finr[R[i]] == i && finc[C[i]] == i) {
            ans++;
        }
    }

    cout << ans << endl;
}