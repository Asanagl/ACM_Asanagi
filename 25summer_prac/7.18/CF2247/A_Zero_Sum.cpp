#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        int neg = 0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            if(a[i] == -1) neg++;
        }
        if(n % 2 == 1){
            cout << "NO\n";
            continue;
        }
        int need = n / 2;
        if((neg % 2) == (need % 2)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}