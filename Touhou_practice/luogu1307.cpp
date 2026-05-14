#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long N , sum=0 ;
    cin >> N;
    if(N>=0)
    {
        string str = to_string(N);
        for (long long i = 10 ; i<=1000000000; i*=10)
        {
            if (N%i==0) sum+=1;
        }
        for (int j =str.size() - sum-1 ; j>=0; j--)
        {
            cout << str[j] ;
        }

    }
    else
    {
        N *= -1 ;
        string str = to_string(N) ;
        for (long long i = 10 ; i<=1000000000; i*=10)
        {
            if (N%i==0) sum+=1;
        }
        cout << "-" ;
        for (int j =str.size() - sum-1 ; j>=0; j--)
        {
            cout << str[j] ;
        }
    }
    if (N==0) cout << "0" <<endl ;
}