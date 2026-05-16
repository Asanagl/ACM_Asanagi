#include <bits/stdc++.h>
using namespace std ;
void Asanagi ()
{
    int n ;
    cin >> n ;
    string str ;
    cin >> str ;
    if (n <= 2)
    {
        if (n == 1 )
        cout << "YES" ;
        else if (n == 2 && str == "11")
        cout << "YES" << endl ;
        else cout << "NO" << endl ;
        return ;
    }
    for(int i = 1; i < n-1 ; i++)
    {
        if (str[i]=='1')
        {
            if (str[i-1]!='1'&&str[i+1]!='1') 
            {
                cout << "NO" << endl ; 
                return ;
            }
        }
    }
    cout << "YES" << endl ; 
}

int main ()
{
    int t ;
    cin >>t ;
    while (t--)
    {
        Asanagi();
    }
}