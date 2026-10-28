#include <iostream>
using namespace std;

int main()
{
    for (int row = 1; row <= 2; row++)
    {
        for (int column = 1; column <= 3; column++)
        {
            cout << '(' << row << ',' << column << ") ";
        }
        cout << '\n';
    }
    return 0;
}
