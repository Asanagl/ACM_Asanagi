#include <iostream>
using namespace std;

int main()
{
    int balance = 0; // 手头现金
    int saved = 0;   // 存在妈妈那里的整百总额

    for (int month = 1; month <= 12; month++)
    {
        int budget;
        cin >> budget;

        balance += 300; // 月初妈妈给 300

        if (balance < budget) // 存的取不出，不够用
        {
            cout << -month << '\n';
            return 0;
        }

        balance -= budget;               // 花掉本月预算
        int deposit = balance / 100 * 100; // 把整百部分存起来
        saved += deposit;
        balance -= deposit;
    }

    cout << balance + saved + saved / 5 << '\n'; // 20% 利息 = 存款 / 5
    return 0;
}
