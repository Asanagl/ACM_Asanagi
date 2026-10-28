#include <iostream>
using namespace std;

int main()
{
    int target;
    cin >> target;

    bool found = false;
    int answerA = 0;
    int answerB = 0;

    for (int a = 0; a <= 9 && !found; a++)
    {
        for (int b = 0; b <= 9; b++)
        {
            if (10 * a + b == target)
            {
                answerA = a;
                answerB = b;
                found = true;
                break;
            }
        }
    }

    if (found)
    {
        cout << answerA << ' ' << answerB << '\n';
    }
    else
    {
        cout << "not found\n";
    }
    return 0;
}
