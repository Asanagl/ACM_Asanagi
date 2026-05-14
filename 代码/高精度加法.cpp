#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define ll long long
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

// 添加比较函数：判断a是否大于等于b
bool compare(string a, string b) {
    if (a.size() != b.size())
        return a.size() > b.size();
    return a >= b;
}

string sub(string a, string b) // 高精度减法，返回a - b
{
    // 比较a和b的大小
    bool isNegative = false;
    if (!compare(a, b)) {
        // 如果a < b，交换a和b，并标记结果为负
        swap(a, b);
        isNegative = true;
    }
    
    const int L = 1e5;
    
    string ans;
    int na[L] = {0}, nb[L] = {0};
    int la = a.size(), lb = b.size();
    for (int i = 0; i < la; i++)
        na[la - 1 - i] = a[i] - '0';
    for (int i = 0; i < lb; i++)
        nb[lb - 1 - i] = b[i] - '0';
    
    // 执行减法并处理借位
    int lmax = la;
    int borrow = 0;
    for (int i = 0; i < lmax; i++) {
        na[i] -= borrow + nb[i];
        borrow = 0;
        if (na[i] < 0) {
            na[i] += 10;
            borrow = 1;
        }
    }
    
    // 找到最后一个非零位
    while (lmax > 1 && na[lmax - 1] == 0)
        lmax--;
    
    for (int i = lmax - 1; i >= 0; i--)
        ans += na[i] + '0';
    
    // 去除前导零
    int i = 0;
    while (i < ans.size() - 1 && ans[i] == '0') {
        i++;
    }
    ans = ans.substr(i);
    
    // 如果结果为负，添加负号（排除结果为0的情况）
    if (isNegative && ans != "0")
        ans = "-" + ans;
    
    return ans;
}

void solve()
{
    string a, b;
    cin >> a >> b;
    cout << sub(a, b) << endl; // 修改调用函数为sub
}

signed main()
{
    IOS;
    int t;
    t = 1 ;
    // cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}