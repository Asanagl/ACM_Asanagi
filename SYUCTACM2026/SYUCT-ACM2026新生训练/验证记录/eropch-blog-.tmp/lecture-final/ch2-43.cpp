#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int sum = 0;
    int maximum = -1; // 分数范围 0~10，初值取范围外即可
    int minimum = 11;

    for (int i = 1; i <= n; i++)
    {
        int score;
        scanf("%d", &score);
        sum += score;
        if (score > maximum)
        {
            maximum = score;
        }
        if (score < minimum)
        {
            minimum = score;
        }
    }

    double average = (sum - maximum - minimum) / double(n - 2);
    printf("%.2f\n", average);
    return 0;
}
