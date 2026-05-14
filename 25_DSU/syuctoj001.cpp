#include <bits/stdc++.h>
using namespace std ;
int main()
{
    int category = 0 ;
    for (int five_yuan = 0 ; five_yuan < 20 ; five_yuan++ )
    {
        for (int one_yuan = 0 ; one_yuan < 100 - five_yuan ; one_yuan++ )
        {
            int five_cents = 100 - five_yuan - one_yuan ;
            if (five_cents > 1 && five_cents * 0.5 + five_yuan * 5 + one_yuan == 100 )
            {
                category += 1 ;
            }
        }
    }
    cout << category  ;
}