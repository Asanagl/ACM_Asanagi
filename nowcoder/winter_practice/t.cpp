#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() { 
    string str ;
    cin >> str ;
    int n = str.size() ;
    int small = 0 , capital = 0;
    for (int i = 0 ; i < n ; i ++)
    {
        char ch = str[i] ;
        if(ch >= 'a' && ch <= 'z')
        {
            small++;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            capital++;
        }
    }
    if(small < capital)
    {
        transform(str.begin(),str.end(),str.begin(),::toupper);
    }
    else
    {
        transform(str.begin(),str.end(),str.begin(),::tolower);
    }
    cout << str << endl;
}