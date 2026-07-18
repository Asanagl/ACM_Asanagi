#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N), B(N - 1);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    for (int i = 0; i < N - 1; ++i)
        cin >> B[i];
    vector<ll> C(N - 1);
    for (int i = 0; i < N - 1; ++i)
    {
        C[i] = (B[i] - A[i] - A[i + 1]) % M;
        if (C[i] < 0)
            C[i] += M;
    }
    vector<ll> S(N);
    S[0] = 0;
    for (int i = 1; i < N; ++i)
    {
        S[i] = C[i - 1] - S[i - 1];
    }
    vector<ll> odd_s, even_s;
    ll F0 = 0;
    for (int i = 0; i < N; ++i)
    {
        ll s = S[i] % M;
        if (s < 0)
            s += M;
        F0 += s;
        if (i % 2 == 0)
            odd_s.push_back(s);
        else
            even_s.push_back(s);
    }
    sort(odd_s.begin(), odd_s.end());
    sort(even_s.begin(), even_s.end());
    ll diff0 = (N + 1) / 2 - N / 2;
    ll ans = F0;
    for (int i = 0; i < N; i += 2)
    {
        ll c = (-S[i]) % M;
        if (c < 0)
            c += M;
        if (c == 0)
            continue;
        ll need = M - c;
        auto it = lower_bound(odd_s.begin(), odd_s.end(), need);
        ll Ocnt = odd_s.end() - it;

        auto it2 = lower_bound(even_s.begin(), even_s.end(), c);
        ll hachimi = it2 - even_s.begin();
        ll F = F0 + c * diff0 - M * Ocnt + M * hachimi;
        ans = min(ans, F);
    }
    cout << ans << endl;
}