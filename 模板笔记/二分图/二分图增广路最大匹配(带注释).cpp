#include <bits/stdc++.h>
using namespace std;
const int N=500+5;          // 数组大小，留点余量防越界

int n,m,e;                  // n: 左部点数量, m: 右部点数量, e: 边数
int matched[N];             // matched[i]: 右部点 i 当前匹配的左部点编号，0表示未匹配
int vis[N];                 // vis[i]: 本轮 DFS 中右部点 i 是否被访问过（防止重复走）
int mp[N][N];               // 邻接矩阵，mp[u][v]=1 表示左部点u和右部点v有边

// found(x): 尝试为左部点 x 找到一个匹配
// 返回值: 1=成功匹配，0=失败
int found(int x)
{
    for (int i = 1; i <= m; i++) // 遍历所有右部点
    {
        if (!mp[x][i] || vis[i])
            continue; // 没边 或 本轮已访问过，跳过
        vis[i] = 1;   // 标记：本轮已访问右部点 i

        // 核心：尝试让右部点 i 的当前匹配对象"腾位置"
        // 情况1：右部点 i 还没匹配 -> 直接匹配
        // 情况2：右部点 i 已匹配给某个左部点 matched[i]，
        //       递归尝试让 matched[i] 去找别的右部点（增广路）
        if (!matched[i] || found(matched[i]))
        {
            matched[i] = x; // 右部点 i 的匹配更新为 x
            return 1;       // 匹配成功
        }
    }
    return 0; // 所有右部点都试过了，x 找不到匹配
}

// match(): 匈牙利算法主流程，计算最大匹配数
int match()
{
    int res = 0;                 // 匹配对数
    for (int i = 1; i <= n; i++) // 遍历每个左部点，逐个尝试匹配
    {
        memset(vis, 0, sizeof(vis)); // 每轮 DFS 前清空访问标记
        if (found(i))
            res++; // 如果点 i 能找到匹配，答案+1
    }
    return res;
}

int main()
{
    scanf("%d%d%d", &n, &m, &e);
    for (int i = 1, u, v; i <= e; i++)
    {
        scanf("%d%d", &u, &v);
        mp[u][v]++; // 建图：左部点u -> 右部点v
    }
    printf("%d\n", match());
    return 0;
}