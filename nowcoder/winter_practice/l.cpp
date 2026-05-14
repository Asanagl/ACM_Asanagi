#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    bool flag = true ;
    char ch ;
    while (cin >> ch )
    {
        if (flag)
        {
            if (ch >= 'a' && ch <= 'z')
            {
                ch = toupper(ch) ;
            }
        }
        cout << ch ;flag = false ;
    }
}