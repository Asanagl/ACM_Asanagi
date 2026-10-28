#include <iostream>
using namespace std;

int main()
{
    int n, target;
    cin >> n >> target;

    if (n < 1 || target < 1 || target > n)
    {
        cout << "invalid input\n";
        return 0;
    }

    int left = 1;
    int right = n;
    int guesses = 0;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;
        guesses++;

        if (middle == target)
        {
            cout << "found " << middle << '\n';
            cout << "guesses " << guesses << '\n';
            break;
        }
        else if (middle < target)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }
    return 0;
}
