#include <climits>
#include <iostream>
using namespace std;

int main()
{
    int x = INT_MAX;              // int 能表示的最大值 2147483647
    long long safe = 1LL * x + 1; // 先转成 long long 再加
    cout << safe << '\n';
    return 0;
}
