#include <bits/stdc++.h>
using namespace std ;
int main ()
{
    int fanwei_Shi = 0 , fanwei_Zhong = 0 ,sum = 0 ;
    cin >> fanwei_Shi >> fanwei_Zhong ;
    while (fanwei_Shi <= fanwei_Zhong)
    {
        string shu = to_string(fanwei_Shi) ;
        for (int i =0 ; i<=5 ; i++ )
        {
            if (shu[i] == '2')
                sum += 1 ;
        }
        fanwei_Shi +=1;

    }
    cout << sum << endl ;
}