#include <iostream>
using namespace std;

const int MAXN = 100005;
#define MOD 1000000007
#define A 1 + 2   // 反例：内容没有整体加括号

int main()
{
    cout << MAXN << ' ' << MOD << '\n';   // 输出 100005 1000000007
    cout << 2 * A << '\n';                // 输出 4，而不是 6！
    return 0;
}
