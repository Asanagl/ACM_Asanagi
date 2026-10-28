#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define PII pair<int,int>
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;

void Asanagi()
{
    int N, Q;
    cin >> N >> Q;

    // has_tile[i] 表示第 i 个方块当前是否有瓷砖 (1-indexed)
    vector<bool> has_tile(N + 1, false);
    // enter_time[i] 表示第 i 个方块最后一次变成无瓷砖状态的时间
    vector<int> enter_time(N + 1, 0);
    // color_before_set[i] 记录第 i 个方块上次离开无瓷砖状态时的颜色
    vector<char> color_before_set(N + 1, 'a');

    int lazy_time = 0;
    char lazy_color = 'a';

    for (int i = 1; i <= Q; i++) {
        int type;
        cin >> type;
        if (type == 2) {
            char c;
            cin >> c;
            lazy_time = i;
            lazy_color = c;
        } else {
            int x;
            cin >> x;
            if (!has_tile[x]) {
                // 当前无瓷砖，此操作是放上瓷砖
                // 结算它无瓷砖期间的颜色
                if (lazy_time > enter_time[x]) {
                    color_before_set[x] = lazy_color;
                }
                has_tile[x] = true;
            } else {
                // 当前有瓷砖，此操作是移除瓷砖
                has_tile[x] = false;
                enter_time[x] = i; // 记录进入无瓷砖状态的时间
            }
        }
    }

    // 输出最终状态
    for (int i = 1; i <= N; i++) {
        if (has_tile[i]) {
            cout << color_before_set[i];
        } else {
            if (lazy_time > enter_time[i]) {
                cout << lazy_color;
            } else {
                cout << color_before_set[i];
            }
        }
    }
    cout << endl;
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
