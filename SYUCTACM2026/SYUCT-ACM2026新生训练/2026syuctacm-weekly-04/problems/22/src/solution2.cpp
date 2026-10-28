// 子矩阵求和 —— 独立参考解：基于盲审独立给出的二维前缀和方案。
// 与主解算法不同：主解逐格枚举询问矩形，本解建 (n+1)×(m+1) 前缀表，每次询问 O(1) 容斥。
#include <cstdio>
#include <vector>

int main() {
    int n = 0, m = 0, q = 0;
    if (std::scanf("%d %d %d", &n, &m, &q) != 3) {
        return 0;
    }

    // P[i][j] = 左上角 (1,1) 到 (i,j) 的闭矩形元素和，P[0][*] = P[*][0] = 0。
    std::vector<std::vector<long long>> P(n + 1, std::vector<long long>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            long long x = 0;
            if (std::scanf("%lld", &x) != 1) {
                return 0;
            }
            P[i][j] = x + P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1];
        }
    }

    for (int k = 0; k < q; ++k) {
        int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
        if (std::scanf("%d %d %d %d", &r1, &c1, &r2, &c2) != 4) {
            return 0;
        }
        long long ans = P[r2][c2] - P[r1 - 1][c2] - P[r2][c1 - 1] + P[r1 - 1][c1 - 1];
        std::printf("%lld\n", ans);
    }

    return 0;
}
