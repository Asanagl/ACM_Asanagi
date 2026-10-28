#include <iostream>
using namespace std;

int main()
{
    char operation;
    int a, b;
    cin >> a >> operation >> b;

    switch (operation)
    {
        case '+':
            cout << a + b << '\n';
            break;
        case '-':
            cout << a - b << '\n';
            break;
        case '*':
            cout << a * b << '\n';
            break;
        case '/':
            if (b == 0)
            {
                cout << "division by zero\n";
            }
            else
            {
                cout << a / b << '\n';
            }
            break;
        default:
            cout << "unknown operation\n";
            break;
    }
    return 0;
}
