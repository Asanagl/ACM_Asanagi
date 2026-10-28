#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int a[5] = {1, 2};
    int b[5] = {};
    int c[] = {3, 1, 4};

    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << (i + 1 == 5 ? '\n' : ' ');
    }
    for (int i = 0; i < 5; i++)
    {
        cout << b[i] << (i + 1 == 5 ? '\n' : ' ');
    }
    cout << sizeof(c) / sizeof(c[0]) << '\n';

    int d[8] = {9, 9, 9, 9, 9, 9, 9, 9};
    fill(d, d + 3, 0);
    for (int i = 0; i < 8; i++)
    {
        cout << d[i] << (i + 1 == 8 ? '\n' : ' ');
    }

    for (int value : c)
    {
        cout << value << ' ';
    }
    cout << '\n';
    return 0;
}
