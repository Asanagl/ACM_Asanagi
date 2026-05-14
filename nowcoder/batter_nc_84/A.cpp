#include <bits/stdc++.h>
using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define int long long
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

int handType(vector<int> cards)
{
    map<int, int> count;
    for (int c : cards)
    {
        count[c]++;
    }
    bool hasFour = false;
    bool hasThree = false;
    bool hasTwo = false;
    for (auto &p : count)
    {
        if (p.second >= 4)
        {
            hasFour = true;
        }
        if (p.second == 3)
        {
            hasThree = true;
        }
        if (p.second == 2)
        {
            hasTwo = true;
        }
    }
    if (hasFour)
    {
        return 1;
    }
    else if (hasThree && hasTwo)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve()
{
    vector<int> a(4);
    vector<int> b(4);
    for (int i = 0; i < 4; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> b[i];
    }

    int win = 0, draw = 0, lose = 0;

    for (int x = 1; x <= 13; x++)
    {
        for (int y = 1; y <= 13; y++)
        {
            vector<int> a_hand = a;
            a_hand.push_back(x);
            int a_tybe = handType(a_hand);

            vector<int> b_hand = b;
            b_hand.push_back(y);
            int b_tybe = handType(b_hand);

            if (a_tybe < b_tybe)
            {
                win++;
            }
            else if (a_tybe > b_tybe)
            {
                lose++;
            }
            else
            {
                draw++;
            }
        }
    }
    int total = 13*13 ;
    int g1 = gcd(win, total);
    int g2 = gcd(draw, total);
    int g3 = gcd(lose, total);
    cout << win / g1 << "/" << total / g1 << " "
         << draw / g2 << "/" << total / g2 << " "
         << lose / g3 << "/" << total / g3 << endl;
}

signed main()
{
    IOS;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
