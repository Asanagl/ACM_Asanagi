#include <iostream>
using namespace std;
void print128(__int128 x)
{
    if (x == 0) { cout << 0; return; }
    if (x < 0) { cout << '-'; x = -x; }
    string s;
    while (x > 0) { s += char('0' + x % 10); x /= 10; }
    for (int i = (int)s.size() - 1; i >= 0; i--) cout << s[i];
}
int main()
{
    __int128 f = 1;
    for (int i = 1; i <= 34; i++)
    {
        f *= i;
        cout << i << "! = ";
        print128(f);
        cout << (f > 0 ? "  (fits)" : "  (OVERFLOW/UB)") << '\n';
    }
    return 0;
}
