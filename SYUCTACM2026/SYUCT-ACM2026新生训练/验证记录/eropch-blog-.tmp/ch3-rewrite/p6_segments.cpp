#include <iostream>
using namespace std;

#define MAXN 1000

int main()
{
    int n;
    cin >> n;

    int a[MAXN];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int segmentCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0 && (i == 0 || a[i - 1] == 0))
        {
            segmentCount++;
        }
    }

    cout << segmentCount << '\n';
    return 0;
}
