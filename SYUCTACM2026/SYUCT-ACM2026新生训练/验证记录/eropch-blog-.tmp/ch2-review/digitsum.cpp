#include <iostream>
using namespace std;
int main()
{
    long long n = 1234;
    int digitSum = 0;
    while (n > 0)
    {
        digitSum += n % 10;
        n /= 10;
    }
    cout << digitSum << '\n';
    return 0;
}
