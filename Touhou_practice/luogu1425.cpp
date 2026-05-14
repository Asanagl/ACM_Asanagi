#include  <bits/stdc++.h>
using namespace std ;

int main()
{
    int hour_begin,minute_begin  , hour_end , minute_end , hour_result , minute_result ;
    cin >> hour_begin >> minute_begin >> hour_end >> minute_end ;
    hour_result =  hour_end - hour_begin  ;
    minute_result =  minute_end - minute_begin  ;
    if (minute_result < 0 )
    {
        hour_result -= 1;
        minute_result += 60 ;
    }
    cout << hour_result << " " << minute_result << endl ;
    return 0;

}