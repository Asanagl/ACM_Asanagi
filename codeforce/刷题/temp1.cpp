#include <bits/stdc++.h>
using namespace std;


using ll = long long  ;
#define int long long 
#define pb push_back
#define Asanagi Minato
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr)

const int INF = 1e12 ;

int N;
int vvi[105][105];
int col0[105][105];

void Asanagi() 
{
    cin >> N;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            cin >> vvi[y][x];
        }
    }
    ll ans = 0;
    
    while (true) {
        for (int x = 1; x <= N; x++) {
            col0[x][0] = 0;
            for (int y = 1; y <= N; y++) {
                col0[x][y] = col0[x][y-1] + (vvi[y][x] == 0);
            }
        }
        
        int scroeans = INT_MIN;
        int ansx1 = 1, ansy1 = 1, ansx2 = 1, ansy2 = 1;
        bool tri = false;
        for (int y1 = 1; y1 <= N; y1++) {
            int cntsum[105] = {0};
            for (int y2 = y1; y2 <= N; y2++) {
                for (int x = 1; x <= N; x++) {
                    cntsum[x] += vvi[y2][x];
                }
                
                int cursum = 0;
                int curX1 = 1;
                for (int x = 1; x <= N; x++) {
                    if (col0[x][y2] - col0[x][y1-1] > 0) {
                        cursum = 0;
                        curX1 = x + 1;
                        continue;
                    }
                    
                    if (cursum + cntsum[x] < cntsum[x]) {
                        cursum = cntsum[x];
                        curX1 = x;
                    } else {
                        cursum += cntsum[x];
                    }
                    
                    if (!tri || cursum > scroeans || 
                        (cursum == scroeans && (curX1 < ansx1 || 
                         (curX1 == ansx1 && y1 < ansy1) || 
                         (curX1 == ansx1 && y1 == ansy1 && x < ansx2) || 
                         (curX1 == ansx1 && y1 == ansy1 && x == ansx2 && y2 < ansy2)))) {
                        scroeans = cursum;
                        ansx1 = curX1;
                        ansy1 = y1;
                        ansx2 = x;
                        ansy2 = y2;
                        tri = true;
                    }
                }
            }
        }
        
        if (!tri || scroeans <= 0) break;
        
        ans += scroeans;
        cout << "(" << ansx1 << ", " << ansy1 << ") (" << ansx2 << ", " << ansy2 << ") " << scroeans << endl;
        
        for (int x = ansx1; x <= ansx2; x++) {
            int tmp[105], cnt = 0;
            for (int y = 1; y < ansy1; y++) if (vvi[y][x] != 0) tmp[cnt++] = vvi[y][x];
            for (int y = ansy2 + 1; y <= N; y++) if (vvi[y][x] != 0) tmp[cnt++] = vvi[y][x];
            for (int y = 1; y <= N - cnt; y++) vvi[y][x] = 0;
            for (int i = 0; i < cnt; i++) vvi[N - cnt + 1 + i][x] = tmp[i];
        }
    }
    
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Asanagi();
    return 0;
}