#include <bits/stdc++.h>
int max_val = -1e9;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int sum_a = 0, sum_b = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum_a += a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        sum_b += b[i];
    }
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
        {
        for (int j = 0; j < n; j++)
            {
            int current = sum_a - a[i] - (sum_b - b[j]);
            if (current > max_val) {
                max_val = current;
                x = i + 1; // 题目要求从 1 开始计数
                y = j + 1;
            }
        }
    }

    cout << x << " " << y << endl;

    return 0;
}
