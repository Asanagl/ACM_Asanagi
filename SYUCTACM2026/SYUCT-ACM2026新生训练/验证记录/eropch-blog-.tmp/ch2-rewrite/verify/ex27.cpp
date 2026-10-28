#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long sum = 0;
    int i = 1;
    while (i <= n)
    {
        if (i % 2 != 0)
        {
            sum += i;
        }
        i++; // 无论是否累加，更新都执行
    }

    cout << sum << '\n';
    return 0;
}
