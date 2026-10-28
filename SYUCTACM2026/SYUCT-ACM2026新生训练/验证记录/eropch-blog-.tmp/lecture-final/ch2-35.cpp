#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        int score;
        cin >> score;
        if (score >= 60)
        {
            count++;
        }
    }

    cout << count << '\n';
    return 0;
}
