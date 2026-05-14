#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n ;
    ll ans = 0 ;
    vector<ll> v(100) ;
    while (cin >> n)
    {
        char ch ; 
        cin >> ch ;
        v.push_back(n) ;
    }
    sort(v.begin(),v.end()) ;
    for (int i  = 0 ; i < v.size() ; i++)
    {
        if(i==v.size()-1)
        cout << v[i] ;
        else
        cout << v[i] << "+" ;
    }
}