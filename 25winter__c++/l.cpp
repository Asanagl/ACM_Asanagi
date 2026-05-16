    #include <bits/stdc++.h>
    using namespace std;

    #define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
    #define endl '\n'
    #define int long long
    #define ld long double
    const int INF = 1e9;
    const int LINF = 1e18;
    const ld PI = acos(-1.0);
    const ld EPS = 1e-9;

    void Asanagi()
    {
        int n ;
        cin >> n ;
        vector <int> a(n ) ;
        for (auto &it : a ) cin >> it ;
        for(int i = 0; i < n; i++)
        {
            int b;
            cin >> b;
            string str;
            cin >> str;
            for(int j = 0; j < b; j++)
            {
                if(str[j] == 'U')   a[i]--;
                else if(str[j] == 'D')  a[i]++;
                if(a[i] < 0)    a[i]+=10;
                if(a[i] > 9)    a[i]-=10;
            }
        }
        for (auto it : a) cout << it << " ";
        cout << endl;
    }

    signed main()
    {
        IOS;
        int t ;
        cin >> t;
        while (t--)
        {
                Asanagi();
            }
        return 0;
    }