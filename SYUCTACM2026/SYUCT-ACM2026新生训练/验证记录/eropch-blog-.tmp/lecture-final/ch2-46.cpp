#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    double pi = 3.14159;
    cout << fixed << setprecision(2) << pi << '\n'; // 3.14

    int x = 7;
    cout << setw(2) << setfill('0') << x << '\n';   // 07
    return 0;
}
