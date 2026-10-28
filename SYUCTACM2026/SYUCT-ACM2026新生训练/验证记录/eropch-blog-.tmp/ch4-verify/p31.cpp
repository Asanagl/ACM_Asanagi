#include <iostream>
using namespace std;
int main()
{
    int n = 3, m = 3;
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int x = 1, y = 1;
    long long neighborSum = 0;
// 与本节四个 if 完全等价
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
for (int direction = 0; direction < 4; direction++)
{
    int nx = x + dx[direction];
    int ny = y + dy[direction];
    if (nx >= 0 && nx < n && ny >= 0 && ny < m)
    {
        neighborSum += a[nx][ny];
    }
}
    cout << neighborSum << '\n';
    return 0;
}
