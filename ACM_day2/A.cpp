#include <iostream>
using namespace std;

int main()
{
    int n ;
    cin >> n;
    int x = n;
    int sum_1 ;
    int sum = 0; //记录每一位的和
    do
    {
        if (x % 2 == 0)
            while (x) // 同等于while(x!=0)
        {
            int c = x % 10; //c就是取出当前这位数字，最开始从个位开始
            sum += c * c; //每次循环把最后面的一位加进去
            x /= 10;
        }
        x = sum;
    }
    while (sum/10) ;

}