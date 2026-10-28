#include <iostream>
using namespace std;

#define MAXN 1000

int main()
{
    int n;
    long long targetSum;
    cin >> n >> targetSum;

    int a[MAXN];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int bestLength = n + 1;   // “还没找到”的标记
    long long currentSum = 0;
    int left = 0;

    for (int right = 0; right < n; right++)
    {
        currentSum += a[right];              // 右端纳入新元素
        while (currentSum >= targetSum)      // 条件满足就尝试收缩左端
        {
            if (right - left + 1 < bestLength)
            {
                bestLength = right - left + 1;
            }
            currentSum -= a[left];
            left++;
        }
    }

    if (bestLength == n + 1)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << bestLength << '\n';
    }
    return 0;
}
