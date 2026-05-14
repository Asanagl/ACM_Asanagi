#include <bits/stdc++.h>
using namespace std;
#define ll long long


bool check(ll limit, const vector<ll>& a, int M) {
    int cnt = 1;  
    ll sum = 0;   
    for (ll num : a) {
        if (sum + num > limit) {
            // 需要新开一段
            cnt++;
            sum = num;
            if (cnt > M) return false; 
        } else {
            sum += num;
        }
    }
    return cnt <= M;
}

int main() 
{
    int N, M;
    cin >> N >> M;
    
    vector<ll> A(N);
    ll l = 0, r = 0; 
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        l = max(l, A[i]);  
        r += A[i];        
    }
    

//binary search
    while (l < r) {
        ll mid = l + (r - l) / 2;
        
        if (check(mid, A, M)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    


    cout << l << endl;
}