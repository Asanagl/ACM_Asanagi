#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define pb push_back

// 定义节点结构体，用于拓扑排序中的每个顶点
struct node
{
   int du = 0;              // 入度 (in-degree)：指向该节点的边的数量，拓扑排序的核心依据
   vector<int> son_idx;     // 子节点列表：存储从该节点出发的有向边所指向的所有后继节点
};

int main()
{
   int n;
   cin >> n; // 读入节点总数 n

   // 建立大小为 n+1 的节点数组，下标从 1 开始使用（符合题目常见的节点编号习惯）
   // pt[i] 表示编号为 i 的节点的入度和出边信息
   vector<node> pt(n + 1);

   // 读入每个节点的出边信息
   // 题目格式：每行第一个数 m 表示后续有 m 个子节点，以 0 结束该行输入
   for (int i = 1; i <= n; i++)
   {
       int m = 1;
       cin >> m; // 读入第一个子节点编号（若输入为0则该行直接结束）

       // 持续读入直到遇到 0（该行结束标志）
       while (m != 0)
       {
           pt[m].du++;          // 节点 m 的入度 +1（因为存在边 i -> m）
           pt[i].son_idx.pb(m); // 将 m 加入节点 i 的子节点列表，建立有向边 i -> m
           cin >> m;            // 读入下一个子节点编号
       }
   }

   // 初始化队列：将所有入度为 0 的节点入队
   // 入度为 0 表示没有前驱节点，可以作为拓扑序列的起点
   queue<int> qe;
   for (int i = 1; i <= n; i++)
   {
       if (pt[i].du == 0)
           qe.push(i);
   }

   // ans 用于存储最终的拓扑排序结果
   vector<int> ans;

   // BFS 过程：每次从队列中取出一个入度为 0 的节点加入答案
   // 然后将其所有后继节点的入度减 1，若减后入度变为 0 则入队
   while (!qe.empty())
   {
       int idx;
       idx = qe.front(); // 取出队首节点（当前入度为 0，可作为下一个输出）
       qe.pop();

       ans.pb(idx); // 将该节点加入拓扑序列

       // 遍历当前节点的所有后继节点，进行"删边"操作（逻辑上删除 idx -> it 这条边）
       for (auto &it : pt[idx].son_idx)
       {
           pt[it].du--; // 后继节点 it 的入度 -1（因为前驱节点 idx 已被处理）

           // 若入度减为 0，说明 it 的所有前驱都已被处理，可以入队等待输出
           if (pt[it].du == 0)
               qe.push(it);
       }
   }

   // 输出拓扑排序结果：节点按拓扑序排列，保证所有边从前往后指向
   for (auto &it : ans)
       cout << it << " ";
}
