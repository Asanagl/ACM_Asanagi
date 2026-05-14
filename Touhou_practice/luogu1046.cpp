#include <bits/stdc++.h>
using namespace std;
int main()
{
    int apple_Tree [10] , Height ,Height_Max , sum = 0 ;
    for (int i = 0; i <= 9; i++)
    {
        cin >> apple_Tree[i] ;
    }
    cin >> Height ;
    Height_Max = Height + 30 ;
    for (int i = 0; i <= 9; i++)
    {
        if (apple_Tree[i] <= Height_Max)
            sum += 1 ;
    }
    cout << sum << endl ;
    return 0;
}