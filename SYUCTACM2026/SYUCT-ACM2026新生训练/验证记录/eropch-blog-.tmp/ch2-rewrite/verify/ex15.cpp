#include <iostream>
using namespace std;

int main()
{
    int age;
    bool hasTicket;
    cin >> age >> hasTicket;

    if (age >= 18)
    {
        if (hasTicket)
        {
            cout << "enter\n";
        }
        else
        {
            cout << "buy a ticket\n";
        }
    }
    else
    {
        cout << "too young\n";
    }
    return 0;
}
