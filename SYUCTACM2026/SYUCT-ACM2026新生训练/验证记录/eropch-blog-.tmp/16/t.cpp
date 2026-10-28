#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
template <typename F>
static void emit(int n, F fill) {
    vector<vector<long long>> a(n, vector<long long>(n, 0));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) a[i][j] = fill(i, j);
    cout << n << '\n';
}
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    cerr << "start\n";
    emit(3, [](int i, int j) -> long long { return i*10+j; });
    cerr << "done\n";
    return 0;
}
