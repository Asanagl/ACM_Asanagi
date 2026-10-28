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
    return 0;
}
