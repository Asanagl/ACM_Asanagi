#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;

        int bestIndex = 0;      // 目前最优蚂蚁编号（从 1 开始）
        long long bestTime = 0; // 目前最短用时
        for (int i = 1; i <= n; i++)
        {
            int pos, speed;
            cin >> pos >> speed;

            int distance = pos - x;
            if (distance < 0)
            {
                distance = -distance;
            }
            long long time = (distance + speed - 1) / speed; // 向上取整

            if (bestIndex == 0 || time < bestTime)
            {
                bestIndex = i;
                bestTime = time;
            }
        }
        cout << bestIndex << '\n';
    }
    return 0;
}
