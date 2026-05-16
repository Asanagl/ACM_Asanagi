    #include <bits/stdc++.h>
    using namespace std;

    #define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
    #define endl '\n'
    #define int long long
    #define ld long double
    #define int long long
    const int INF = 1e9;
    const int LINF = 1e18;
    const ld PI = acos(-1.0);
    const ld EPS = 1e-9;

    void Asanagi()
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> c(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> c[i][j];
            }
        }
        int ans = 0;
        for (int j = 0; j < m; j++)
        {
            int A = 0, B = 0, C = 0;
            for (int i = 0; i < n; i++)
            {
                if (c[i][j] == 0)
                    A++;
                else if (c[i][j] == 1)
                    B++;
                else
                    C++;
            }
            int target = n / 2;
            int x_min = A;
            int x_max = n - B;
            int best_x;
            if (target < x_min)
            {
                best_x = x_min;
            }
            else if (target > x_max)
            {
                best_x = x_max;
            }
            else
            {
                best_x = target;
            }

            int x = best_x;
            int y = n - x;
            ans += x * (y + 1) + y * (x + 1);
        }

        cout << ans << endl;
    }

    signed main()
    {
        IOS;
        int t = 1;
        // cin >> t;
        while (t--)
        {
            Asanagi();
        }
        return 0;
    }
