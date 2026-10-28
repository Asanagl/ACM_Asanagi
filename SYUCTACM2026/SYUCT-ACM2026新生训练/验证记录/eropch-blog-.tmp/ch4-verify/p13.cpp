#include <iostream>
#include <string>
using namespace std;

int main()
{
    string text, word;
    cin >> text >> word;

    int position = (int)text.find(word);
    if (position < 0)
    {
        cout << "not found\n";
    }
    else
    {
        cout << "found at " << position << '\n';
    }
    return 0;
}
