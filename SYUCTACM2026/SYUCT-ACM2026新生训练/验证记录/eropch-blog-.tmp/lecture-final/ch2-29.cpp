#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int row = 1; row <= n; row++)
    {
        for (int count = 1; count <= row; count++)
        {
            cout << '*';
        }
        cout << '\n';
    }
    return 0;
}
