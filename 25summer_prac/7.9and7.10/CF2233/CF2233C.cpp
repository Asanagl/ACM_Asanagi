#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define PII pair<int,int>
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;

void Asanagi()
{
    int n , k ;
    cin >> n >> k ;
    string str ;
    cin >> str ;
    int len = str.size() ;
    // k = 0 
    if (k == 0) 
    {
        for (int i = 1 ; i <= len ; i++) cout << 0 ;
        cout << endl ;
        return ;
    }
    int val_ans = INF ;
    string ans(n, '0');
    for (int i = 0 ; i < n ; i ++)
    {
        int curk = k ;
        string s = str ;
        string cur_ans(n, '0');
        for (int j = 0 ; j < i ; j++)
        {
            if (s[j] == '('  && curk > 0)
            {
                s[j] = ')' , curk-- ;
                cur_ans[j] = '1' ;
            }
        }
        for (int j = n-1 ; j > i ; j--)
        {
            if (s[j] == ')'  && curk > 0)
            {
                s[j] = '(' , curk-- ;
                cur_ans[j] = '1' ;
            }
        }
        int val_cur = 0 ;
        int bal = 0;
        for (int j = 0; j < n; j++){
            if (bal > 0 && s[j] == ')'){
                val_cur += 2;
                bal--;
            }
            else if (s[j] == '('){
                bal++;
            }
        }
        if (val_ans > val_cur){
			val_ans = val_cur;
			ans = cur_ans;
		}
    }
    cout << ans << endl ;

}

signed main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
    {
        Asanagi();
    }
    return 0;
}
