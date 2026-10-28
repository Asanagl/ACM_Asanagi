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
        if (i % 2 == 0)
        {
            continue; // 危险：i++ 在 continue 后面，永远执行不到
        }
        sum += i;
        i++;
    }

    cout << sum << '\n';
    return 0;
}
