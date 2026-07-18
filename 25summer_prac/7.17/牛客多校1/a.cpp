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
    vector<char> yuan = {'a' , 'e' , 'i' , 'o' , 'u'} ;
    string str ;
    cin >> str ;
    if (str.size() != 8 )
    {
        cout << "Well-Being" << endl  ;
        return ;
    } 
    int n = str.size() ;
    for (int i = 0 ; i < n ;i++)
    {
        if ((i + 1) % 2 == 1)
        {
            if (count(yuan.begin() , yuan.end() , str[i]))
            {
                cout << "Well-Being" << endl  ;
                return ;
            } 
        }else 
        {
            if (!count(yuan.begin() , yuan.end() , str[i]))
            {
                cout << "Well-Being" << endl  ;
                return ;
            } 
        }
    }
    cout << "Suspected Virus" << endl ;
    // if (std::count(vec.begin(), vec.end(), target)) {
    //     std::cout << "元素存在" << std::endl;
    // else {
    //     std::cout << "元素不存在" << std::endl;
    // }   
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
