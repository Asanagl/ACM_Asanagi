#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n ;
    cin >> n ;
    string str ;
    cin >> str ;
    ll ans = 0 ;
    for (int i = 1 ; i i <= n ; i++)
    {
        if (str[i-1] == str[i])
        {
            ans++ ;
        }
    }
    cout << ans ;
}