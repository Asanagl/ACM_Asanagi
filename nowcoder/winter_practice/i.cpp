#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    string str , str_1 ;
    cin >> str >> str_1 ;
    
    transform(str.begin(),str.end(),str.begin(),::toupper);
    transform(str_1.begin(),str_1.end(),str_1.begin(),::toupper);
    if (str == str_1) cout << "0" << endl;
    else if (str > str_1) cout << "1" << endl;
    else cout << "-1" << endl;
}
