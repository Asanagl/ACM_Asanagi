#include <iostream>
#include <string>
using namespace std;

#define MAXN 100

int main()
{
    int n;
    cin >> n;
    cin.ignore(); // 丢掉 n 后面那一行的换行符

    string lines[MAXN];
    for (int i = 0; i < n; i++)
    {
        getline(cin, lines[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << ": [" << lines[i] << "]\n";
    }
    return 0;
}
