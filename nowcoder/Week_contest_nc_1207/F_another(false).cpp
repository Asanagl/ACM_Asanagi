#include <iostream>
#include <vector>
#include <random>
using namespace std;

const int MAX = 101;
vector<int> spf(MAX);
vector<unsigned long long> rand_hash(MAX);

void build_spf()
{
    for (int i = 1; i < MAX; i++)
        spf[i] = i;
    for (int i = 2; i * i < MAX; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < MAX; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

int main()
{
    build_spf();
    mt19937_64 gen(12345);
    for (int i = 2; i < MAX; i++)
    {
        if (spf[i] == i)
            rand_hash[i] = gen();
    }

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<unsigned long long> h(n);
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        unsigned long long val = 0;
        while (x > 1)
        {
            int p = spf[x], cnt = 0;
            while (spf[x] == p)
            {
                cnt++;
                x /= p;
            }
            if (cnt % 2)
                val ^= rand_hash[p];
        }
        h[i] = val;
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        unsigned long long xor_val = 0;
        for (int i = l; i <= r; i++)
            xor_val ^= h[i];
        cout << (xor_val == 0 ? "Yes" : "No") << '\n';
    }
    return 0;
}