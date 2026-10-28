#include <iostream>
#include <string>
using namespace std;

int main()
{
    string text, word;
    cin >> text >> word;

    size_t position = text.find(word);
    if (position == string::npos)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << position << '\n';
    }
    return 0;
}
