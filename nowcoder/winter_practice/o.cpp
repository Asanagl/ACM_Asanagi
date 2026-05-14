#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string danger_1 , danger_2 ;
    danger_1 = "1111111" , danger_2 = "0000000" ;
    string str ;
    cin >> str ;
    if (str.find(danger_1) != string::npos || str.find(danger_2) != string::npos)
    {
        cout << "YES" << endl ;
    }
    else
    {
        cout << "NO" << endl ;
    }
}