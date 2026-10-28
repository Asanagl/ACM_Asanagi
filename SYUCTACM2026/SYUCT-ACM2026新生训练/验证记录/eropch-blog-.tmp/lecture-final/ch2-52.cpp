#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int count = 0;
    for (long long value = 1; value <= n; value *= 2)
    {
        count++;
    }

    cout << count << '\n';
    return 0;
}
