#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    do
    {
        cout << "Please enter a positive integer: ";
        if (!(cin >> n))
        {
            return 0;
        }
    }
    while (n <= 0);

    cout << "accepted " << n << '\n';
    return 0;
}
