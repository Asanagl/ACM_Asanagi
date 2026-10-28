#include <iostream>
#include <string>
using namespace std;

#define MAXN 100

int main()
{
    int n;
    cin >> n;

    if (n <= 0 || n > MAXN)
    {
        return 0;
    }

    string words[MAXN];
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << words[i] << ' ' << words[i].size() << '\n';
    }
    return 0;
}
