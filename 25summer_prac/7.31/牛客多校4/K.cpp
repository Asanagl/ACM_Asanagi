#include <bits/stdc++.h>
using namespace std; 
void solve ()
{
    int n , k ;
    cin >> n >> k ;
    vector <int> v (n) ; 
    for (int i = 0 ; i < n ; i++)
    {
        cin >> v[i] ;
    }
    vector <int> v1 (n) ;
    vector <int> v2 (n) ;
    vector <int> v3 (n) ;
    vector <int> v4 (n) ; 
    vector <int> v5 (n) ;
    
    for (int i = 0 ; i < n ; i++)
    {
        set <int> st ;
        st.insert(v[i]) ;
        st.insert(v[(i-1 + n) % n]) ;
        st.insert(v[(i+1) % n ]) ;
        int mex = 0 ;
        for (auto &it : st)
        {
            if (it == mex) mex++ ;
        }
        v1[i] = mex ;
    }
    for (int i = 0 ; i < n ; i++)
    {
        set <int> st ;
        st.insert(v1[i]) ;
        st.insert(v1[(i-1 + n) % n]) ;
        st.insert(v1[(i+1) % n ]) ;
        int mex = 0 ;
        for (auto &it : st)
        {
            if (it == mex) mex++ ;
        }
        v2[i] = mex ;
    }for (int i = 0 ; i < n ; i++)
    {
        set <int> st ;
        st.insert(v2[i]) ;
        st.insert(v2[(i-1 + n) % n]) ;
        st.insert(v2[(i+1) % n ]) ;
        int mex = 0 ;
        for (auto &it : st)
        {
            if (it == mex) mex++ ;
        }
        v3[i] = mex ;
    }
    for (int i = 0 ; i < n ; i++)
    {
        set <int> st ;
        st.insert(v3[i]) ;
        st.insert(v3[(i-1 + n) % n]) ;
        st.insert(v3[(i+1) % n ]) ;
        int mex = 0 ;
        for (auto &it : st)
        {
            if (it == mex) mex++ ;
        }
        v4[i] = mex ;
    }
    for (int i = 0 ; i < n ; i++)
    {
        set <int> st ;
        st.insert(v4[i]) ;
        st.insert(v4[(i-1 + n) % n]) ;
        st.insert(v4[(i+1) % n ]) ;
        int mex = 0 ;
        for (auto &it : st)
        {
            if (it == mex) mex++ ;
        }
        v5[i] = mex ;
    }
    if (k == 1) for (auto &it : v1) cout << it << " " ;
    else if (k == 2) for (auto &it : v2) cout << it << " " ;
    else if (k == 3) for (auto &it : v3) cout << it << " " ;
    else if (k == 4) for (auto &it : v4) cout << it << " " ;
    else if (k == 5) for (auto &it : v5) cout << it << " " ;
    else if (k % 2 == 0) for (auto &it : v4) cout << it << " " ;
    else for (auto &it : v5) cout << it << " " ;
}
int main ()
{
    int t = 1;
    // cin >> t ;
    while (t--)
    solve() ;
}