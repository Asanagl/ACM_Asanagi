#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
int counts[5] = {};
for (char c : s)
{
    if (c >= 'A' && c <= 'Z')
    {
        c = c - 'A' + 'a';
    }

    if (c == 'a') counts[0]++;
    else if (c == 'e') counts[1]++;
    else if (c == 'i') counts[2]++;
    else if (c == 'o') counts[3]++;
    else if (c == 'u') counts[4]++;
}

for (int i = 0; i < 5; i++)
{
    cout << counts[i] << (i == 4 ? '\n' : ' ');
}
    return 0;
}
