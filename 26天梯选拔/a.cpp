#include <bits/stdc++.h>
using namespace std ;
int main ()
{
    int n  , k ;
    cin >> n >> k ;
    unordered_map<int, int> ump ;
    deque<int> qe ;
    vector <int> v (n) ;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> v[i];
        qe.push_front(v[i]);
    }
    int a1 , a2 ;
    a1 = qe.back() ;
    qe.pop_back() ;
    a2 = qe.back() ;
    qe.pop_back() ;
    for (int i = 0 ; i < k-1 ;i++)
    {
        if (a1 > a2) 
        {
            ump[a1]++;
            qe.push_front(a2) ;
            a2 = qe.back();qe.pop_back() ;
            if (ump[a1]==2)
            {
                ump[a1]=0 ;
                qe.push_front(a1);
                a1 = qe.back () ; qe.pop_back() ;
            }
        } 
        else 
        {
            ump[a2]++;
            qe.push_front(a1) ;
            a1 = qe.back(); qe.pop_back() ;
            if (ump[a2]==2)
            {
                ump[a2]=0 ;
                qe.push_front(a2);
                a2 = qe.back(); qe.pop_back() ;
            }
        }
    }
    cout << min(a1,a2) <<" "<< max(a1,a2) ;
}