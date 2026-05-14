#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin >> n ;
    int x = 0 ;
    while (n--)
    {
        for(int i = 0 ; i < 3 ; i++)
        {
            char ch ;
            cin >> ch ;
            if (i==0) continue;
            if (i==1)
            {
                if (ch == '-') x-- ;
                else if(ch=='+') x++ ;
            }
        }
    }
    cout << x << endl ;
}