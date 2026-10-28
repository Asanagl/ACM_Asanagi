#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    double a = 0.1 + 0.2;
    double b = 0.3;
    const double EPS = 1e-9;

    if (fabs(a - b) < EPS)
    {
        cout << "equal\n";
    }
    else
    {
        cout << "not equal\n";
    }
    return 0;
}
