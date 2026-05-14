#include <bits/stdc++.h>
using namespace std ;
void Asanagi()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    if (n % 2 == 1 && str[0] == 'b')
    {
        cout << "NO" << endl ;
        return ;
    }
    int i = 0;
    if (n % 2 == 1)
    {
        i++;
        for (; i < str.size(); i += 2)
        {
            if ((str[i] == '?' || str[i] == 'a') && (str[i + 1] == '?' || str[i + 1] == 'b') || ((str[i] == '?' || str[i] == 'b') && (str[i + 1] == '?' || str[i + 1] == 'a')))
                continue;
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
    }
    else
    {
        for (; i < str.size(); i += 2)
        {
            if ((str[i] == '?' || str[i] == 'a') && (str[i + 1] == '?' || str[i + 1] == 'b') || ((str[i] == '?' || str[i] == 'b') && (str[i + 1] == '?' || str[i + 1] == 'a')))
                continue;
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
    }
}
int main ()
{
    int t ;
    cin >> t ;
    while (t--)
    {
        Asanagi () ;
    }
}