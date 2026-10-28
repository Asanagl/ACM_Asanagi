#include <iostream>
using namespace std;

int main()
{
    char c = 'A';
    cout << c << '\n';            // A
    cout << c + 1 << '\n';        // 66
    cout << char(c + 1) << '\n';  // B
    cout << 'C' - 'A' << '\n';    // 2
    cout << flush;
    return 0;
}
