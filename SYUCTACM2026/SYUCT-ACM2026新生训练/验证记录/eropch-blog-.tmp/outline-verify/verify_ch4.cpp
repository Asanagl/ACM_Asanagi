#include <bits/stdc++.h>
using namespace std;

int main() {
    // ---- 1) cin >> 与 getline 混用：残留换行陷阱与 ignore 修正 ----
    int n;
    cin >> n;                     // 读走 2，行末换行残留在缓冲区
    string trap_line, real_line;
    getline(cin, trap_line);      // 陷阱：立刻读走残留的换行，得到空串
    getline(cin, real_line);      // 这一行才是真正的 "hello world"
    cout << "after cin >>: [" << trap_line << "]\n";
    cout << "next line:    [" << real_line << "]\n";

    int m;
    cin >> m;                     // 读走 3
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 修正：吃掉残留换行
    string fixed_line;
    getline(cin, fixed_line);     // 正确读到 "good morning"
    cout << "with ignore:  [" << fixed_line << "]\n";

    // ---- 2) 字符网格：按行读入 + 四方向邻格统计 ----
    int rows, cols;
    cin >> rows >> cols;
    vector<string> grid(rows);
    for (int i = 0; i < rows; i++) cin >> grid[i];

    int at_count = 0, adjacent_pairs = 0;
    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] != '@') continue;
            at_count++;
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                if (grid[nr][nc] == '@' && (nr > r || (nr == r && nc > c)))
                    adjacent_pairs++; // 每对只统计一次
            }
        }
    }
    cout << "at cells=" << at_count << "\n";
    cout << "adjacent pairs=" << adjacent_pairs << "\n";

    // ---- 3) 二维数组系统复习：行列统计 / 转置 / 顺时针旋转 / 子矩阵枚举 ----
    int mr, mc;
    cin >> mr >> mc;
    vector<vector<int>> a(mr, vector<int>(mc));
    for (int i = 0; i < mr; i++)
        for (int j = 0; j < mc; j++) cin >> a[i][j];

    for (int i = 0; i < mr; i++) {
        int sum = 0;
        for (int j = 0; j < mc; j++) sum += a[i][j];
        cout << "row sum " << i << "=" << sum << "\n";
    }
    for (int j = 0; j < mc; j++) {
        int sum = 0;
        for (int i = 0; i < mr; i++) sum += a[i][j];
        cout << "col sum " << j << "=" << sum << "\n";
    }

    // 转置：mc 行 mr 列
    for (int j = 0; j < mc; j++) {
        for (int i = 0; i < mr; i++) cout << a[i][j] << " \n"[i == mr - 1];
    }

    // 顺时针旋转：mc 行 mr 列，(i, j) -> (j, mr - 1 - i)
    for (int j = 0; j < mc; j++) {
        for (int i = mr - 1; i >= 0; i--) cout << a[i][j] << " \n"[i == 0];
    }

    // 子矩阵枚举：统计元素和恰好为 target 的子矩阵个数
    int target;
    cin >> target;
    int count = 0;
    for (int r1 = 0; r1 < mr; r1++)
        for (int c1 = 0; c1 < mc; c1++)
            for (int r2 = r1; r2 < mr; r2++)
                for (int c2 = c1; c2 < mc; c2++) {
                    int sum = 0;
                    for (int i = r1; i <= r2; i++)
                        for (int j = c1; j <= c2; j++) sum += a[i][j];
                    if (sum == target) count++;
                }
    cout << "submatrices sum=" << target << ": " << count << "\n";

    cout.flush(); // 本机 MinGW(mcfgthread) 退出时不自动刷新 cout，显式刷新
    return 0;
}
