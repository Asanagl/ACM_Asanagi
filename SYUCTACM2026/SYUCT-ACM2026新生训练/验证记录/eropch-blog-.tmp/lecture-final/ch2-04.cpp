#include <iostream>
using namespace std;

int main()
{
    int x;
    cin >> x;

    bool inRange = (x >= 1 && x <= 100);
    bool outOfRange = (x < 1 || x > 100);
    bool notInRange = !inRange;

    cout << inRange << ' '
         << outOfRange << ' '
         << notInRange << '\n';
    return 0;
}
