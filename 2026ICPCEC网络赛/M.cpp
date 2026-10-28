#include <bits/stdc++.h>
using namespace std ;
int main ()
{
    int n , m ;
    cin >> n >> m ;
    unordered_map<string , int> mp ;
    for (int i =0 ; i < n ; i ++)
    {
        string s ;
        cin >> s ;
        mp[s]++ ;
    }
    for (int i = 0 ; i < m ; i++)
    {
         string s ;
         cin >> s ;
         if  (mp[s] == 1)
         {
            cout << "OK" << endl ;
            mp[s]++ ;
         } else if (mp[s] == 2)
         {
            cout << "REPEAT" << endl ;
         }
         else if (mp[s] == 0)
         {
            cout << "WRONG" << endl ;
         }
    }
}
