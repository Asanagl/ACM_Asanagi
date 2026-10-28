#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    double pi = 3.1415926;
    double x = 2.5;

    cout << pi << '\n';
    cout << fixed << setprecision(2) << pi << '\n';
    cout << fixed << setprecision(2) << x << '\n';
    printf("%.2f\n", pi);
    return 0;
}
