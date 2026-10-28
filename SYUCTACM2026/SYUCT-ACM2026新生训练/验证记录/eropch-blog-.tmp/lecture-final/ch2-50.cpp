#include <iostream>
using namespace std;

int main()
{
    for (int rooster = 0; rooster <= 20; rooster++) // 上界：100 / 5
    {
        for (int hen = 0; hen <= 33; hen++)         // 上界：100 / 3
        {
            int chick = 100 - rooster - hen;
            if (chick >= 0
                && chick % 3 == 0
                && 5 * rooster + 3 * hen + chick / 3 == 100)
            {
                cout << rooster << ' '
                     << hen << ' '
                     << chick << '\n';
            }
        }
    }
    return 0;
}
