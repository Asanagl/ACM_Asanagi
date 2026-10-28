#include <climits>
#include <iostream>
using namespace std;

int main()
{
    int x = INT_MAX;
    long long safe = 1LL * x + 1;
    cout << safe << '\n';
    return 0;
}
