#include<iostream>
#include <vector>
using namespace std ;

const int ins = -999 ;

void solve()
{
    int n , x ;
    cin >> n >> x ;
    vector<int> tep_day(n);
    int yep = 0 , nope = 0 ;
    for (int i = 0 ; i < n ; i++)
    cin >> tep_day[i] ;
    vector <int> tep_day_copy = tep_day ;
    for(int i = 0 ; i < n-1 ; i++)
    {
        if(tep_day[0]==ins) break ;
        if(tep_day[i+1]==ins) tep_day[i+1]=(tep_day[i]-x+1>50) ? -50 : (tep_day[i]-x+1) ;
        if(tep_day[i]-tep_day[i+1]>=x) nope++ ;
    }
    if(tep_day_copy[0]==ins) tep_day_copy[0]=50;
    for(int i = 0 ; i < n-1; i++)
    {
        if(tep_day_copy[i+1]==ins)
            tep_day_copy[i+1]=(tep_day_copy[i]-x<-50) ? -50 : (tep_day_copy[i]-x) ;
        if(tep_day_copy[i]-tep_day_copy[i-1]>=x) yep++;

    }
    for(auto &i : tep_day_copy) cout << tep_day_copy[i] << endl ;
    cout << yep << " " << nope ;
}


int main()
{
    solve();
}