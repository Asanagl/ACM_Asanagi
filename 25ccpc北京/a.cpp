#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;

void Asanagi()
{
    int n ;
    cin >> n ;
    string str ;
    cin >> str ;
    int right = 0 ;
    int left = str.size() - 1 ;
    const char r = str[right] , l = str[left] ;
    bool tri = true ;
    for (int i = 0 ; i < str.size() ; i++)
    {
        if (str[i]!=r) tri = false ;
    }
    if (tri)
    {
        cout << str << endl ;
        return ;
    }
    if (r != l) 
    {
        cout << "empty" << endl ;
        return ;
    }
    else 
    {
        if (r=='1') for (int i = 0 ; i < str.size()-1 ; i++)
        {
            if ((str[i]==str[i+1])&&str[i]=='0')
            {cout << "empty" << endl ;
            return ;}
        }
        if (r=='0') for (int i = 0 ; i < str.size()-1 ; i++)
        {
            if ((str[i]==str[i+1])&&str[i]=='1')
            {cout << "empty" << endl ;
            return ;}
        }
    }
    
        string temp ;
        string temp1 ;
        for (int i = 0 ; ; i++)
        {
            if (str[i]!=l)
            {
                break;
            }
            temp.push_back(str[i]);
        }
        for (int i = str.size()-1 ;; i--)
        {
            if (str[i]!=r)
            {
                break;
            }
            temp1.push_back(str[i]);
        }
        reverse (temp1.begin() , temp1.end()) ;
        cout << (temp <= temp1 ? temp : temp1) << endl ;
    
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




