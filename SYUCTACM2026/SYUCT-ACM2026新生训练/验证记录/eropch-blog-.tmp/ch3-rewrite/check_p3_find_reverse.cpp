#include <iostream>
#include <utility>
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

    int target;
    cin >> target;

    int position = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == target)
        {
            position = i;
            break;
        }
    }

    for (int left = 0, right = n - 1; left < right; left++, right--)
    {
        swap(a[left], a[right]);
    }

    cout << "first index = " << position << '\n';
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << (i + 1 == n ? '\n' : ' ');
    }
    return 0;
}
