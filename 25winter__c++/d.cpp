#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define int long long
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

void Asanagi()
{
    string s ;
    cin >> s ;
    int num = stoi(s);
    string str = to_string(num);
    for (int i = str.size() - 1; i >= 0; i--)
    {
        if (str[i] == '0')
        {
            str.pop_back();
        }
        else
        {
            break;
        }
    }
    string str_1 =str ;
    reverse(str_1.begin(), str_1.end());
    if (str == str_1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

signed main()
{
    IOS;
    int t = 1;
    // cin >> t;
    while (t--)
    {
            Asanagi();
        }
    return 0;
}