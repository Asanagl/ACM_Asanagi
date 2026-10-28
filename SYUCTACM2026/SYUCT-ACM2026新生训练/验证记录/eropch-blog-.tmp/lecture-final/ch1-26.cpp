#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i + i * i;   // i*i 与累加都可能超出 int 的范围
    }
    cout << sum << '\n';
    return 0;
}
