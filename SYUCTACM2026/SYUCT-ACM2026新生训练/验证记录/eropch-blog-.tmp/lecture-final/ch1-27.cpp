#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;                 // 读入等级数

    long long sum = 0;
    for (long long i = 1; i <= n; i++) {
        sum += i + i * i;     // i 是 long long，乘法与累加全程不溢出
    }

    cout << sum << '\n';      // 输出答案
    return 0;
}
