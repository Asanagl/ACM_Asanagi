#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
    ll price , money , num ;
    cin >> price >> money >> num ;
    ll total = price *((1LL + num)* num)/2LL ;
    if (total <= money)
    {
        cout << 0 << endl ;
    }
    else
    {
        cout << total - money << endl ;
    }
}