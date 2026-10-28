#include <iostream>
using namespace std;

int main()
{
    for (int number = 100; number <= 999; number++)
    {
        int rest = number;      // 拷贝一份用于拆位，number 本身保持不变
        int digitSumOfCubes = 0;
        while (rest > 0)
        {
            int digit = rest % 10;
            digitSumOfCubes += digit * digit * digit;
            rest /= 10;
        }

        if (digitSumOfCubes == number)
        {
            cout << number << '\n';
        }
    }
    return 0;
}
