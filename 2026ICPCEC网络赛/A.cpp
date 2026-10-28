#include <bits/stdc++.h>
using namespace std ;

int main ()
{
    #define int long long
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        stack<int> st;
        unordered_map<int,int> mp;
        vector<char> ans;
        while(n--){
            char op;
            int x;
            cin >> op >> x;
            if(op=='+'){
                while(mp[x]==1){
                    int num=st.top();
                    mp[num]--;
                    st.pop();
                    ans.push_back('-');
                }
                st.push(x);
                mp[x]=1;
                ans.push_back('+');
            }
            else if(op=='T'){
                if(mp[x]==0){
                    st.push(x); 
                    mp[x]=1;
                    ans.push_back('+');
                }
                ans.push_back('?');
            }
            else if(op=='F'){
                while(mp[x]==1){
                    int num=st.top();
                    mp[num]--;
                    st.pop();
                    ans.push_back('-');
                }
                ans.push_back('?');
            }
        }
        while(!st.empty()){
                st.pop();
                ans.push_back('-');
            }
            for(auto i:ans){
                cout << i ;
            }
            cout << endl;
    }
}
