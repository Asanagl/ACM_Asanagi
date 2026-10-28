#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    int digitSum = 0;
    while (n > 0)
    {
        digitSum += n % 10; // 取出末位，加进总和
        n /= 10;            // 删除末位
    }

    cout << digitSum << '\n';
    return 0;
}
