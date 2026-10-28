#include <iostream>
using namespace std;

int main()
{
    int year;
    cin >> year;

    bool leap = (year % 400 == 0)
             || (year % 4 == 0 && year % 100 != 0);

    if (leap)
    {
        cout << "leap year\n";
    }
    else
    {
        cout << "common year\n";
    }
    return 0;
}
