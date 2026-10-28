#include <iostream>
using namespace std;

int main()
{
    cout << static_cast<int>(3.9) << ' ' << (int)3.9 << '\n';
    cout << static_cast<double>(7) / 2 << '\n';
    cout << flush;
    return 0;
}
