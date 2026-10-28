#include <iostream>
using namespace std;

int main()
{
    int score;
    cin >> score;

    if (score < 0 || score > 100)
    {
        cout << "invalid\n";
    }
    else if (score >= 90)
    {
        cout << "A\n";
    }
    else if (score >= 80)
    {
        cout << "B\n";
    }
    else if (score >= 60)
    {
        cout << "C\n";
    }
    else
    {
        cout << "D\n";
    }
    return 0;
}
