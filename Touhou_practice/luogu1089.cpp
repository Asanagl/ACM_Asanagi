#include <bits/stdc++.h>
using namespace std;

int main()
{
    int budget[12], remain_money =0 ,Pocket_money = 0 , save_money = 0,death_month = 0;
    for (int i = 0; i < 12; ++i)
    {
        cin >> budget[i];
    }

    for (int i = 0; i < 12; ++i) {
        Pocket_money += 300;

        if ( Pocket_money < budget[i] )
        {
            death_month = i + 1;
            break;
        }
        remain_money = Pocket_money - budget[i];
        int hundred = remain_money / 100;
        save_money += hundred * 100;
        Pocket_money = remain_money % 100;

    }

    if (death_month != 0)
    {
        cout << -death_month << endl;
    }

    else
    {
        int total_money = Pocket_money + save_money * 120 / 100;
        cout << total_money << endl;
    }
    return 0;
}
