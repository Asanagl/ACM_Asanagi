#include <iostream>
using namespace std;

int main()
{
    int n, hand;
    cin >> n >> hand;

    int reach = hand + 30;
    int picked = 0;
    for (int i = 1; i <= n; i++)
    {
        int height;
        cin >> height;
        if (height <= reach)
        {
            picked++;
        }
    }

    cout << picked << '\n';
    return 0;
}
