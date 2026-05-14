#include <bits/stdc++.h>
using namespace std ;
int main ()
{
    #define int long long 
    int n ;
    cin >> n ;
    int temp = n ;
    int ans = 1 ;
    while (temp--)
    ans*=2 ;
    ans-- ;
    for (int i = 0; i <= ans ; i++)
    {
        string str ;
        int cnt = i ;
        for (int j = 0 ; j < n ;j++) 
        {
            int temp = cnt % 2 ;
            if (temp == 0) str.push_back('N') ;
            else str.push_back('Y');
            cnt /= 2;
        }
        reverse(str.begin(),str.end()) ;
        cout << str << endl ;
        
    }
}