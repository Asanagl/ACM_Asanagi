#include <bits/stdc++.h>
using namespace std;

const int N = 500;
#define ll long long

vector<int> mul(const vector <int>& a, const vector<int>& b) {
    vector <int> c(N, 0);
    for (int i = 0; i < N; ++i) {
        if (a[i] == 0) continue;
        int carry = 0;
        for (int j = 0; j < N && i + j < N; ++j) {
            ll t = (ll)c[i + j] + (ll)a[i] * b[j] + carry;
            c[i + j] = t % 10;
            carry = t / 10;
        }
    }
    return c;
}

vector<int> pow2(ll exp) {
    vector <int> res(N, 0), base(N, 0);
    res[0] = 1;
    base[0] = 2;
    while (exp) {
        if (exp & 1) res = mul(res, base);
        base = mul(base, base);
        exp >>= 1;
    }
    return res;
}

void sub_one(vector<int>& a) {
    int i = 0;
    while (i < N && a[i] == 0) {
        a[i] = 9;
        i++;
    }
    if (i < N) a[i]--;
}

string to_str(const vector<int>& a) {
    string s;
    for (int i = N-1; i >= 0; --i) s += '0' + a[i];
    return s;
}

int main() {
    ll P;
    cin >> P;
    ll d = (ll)(P * log10(2) + 1e-10) + 1;
    cout << d << endl;
    vector<int> x = pow2(P);
    sub_one(x);
    string s = to_str(x);
    for (int i = 0; i < 10; ++i) {
        cout << s.substr(i * 50, 50) << endl;
    }
    return 0;
}