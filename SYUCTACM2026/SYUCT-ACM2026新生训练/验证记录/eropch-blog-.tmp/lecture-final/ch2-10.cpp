#include <iostream>
using namespace std;

int main()
{
    char digitCharacter = '7';
    int digitValue = digitCharacter - '0';

    char lower = 'c';
    char upper = lower - 'a' + 'A';

    cout << digitValue + 5 << '\n';
    cout << upper << '\n';
    return 0;
}
