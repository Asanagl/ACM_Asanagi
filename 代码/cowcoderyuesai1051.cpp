#include <bits/stdc++.h>

using namespace std;


bool cmp(int a, int b)	//cmp函数，确定sort函数排序的规则
{
    return a > b;
}



int gcd(int num[], int n)   //求多个数的最大公约数的算法
{
    sort(num, num + n, cmp);
    while (num[0] != num[n - 1])
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (num[i] % num[i + 1] == 0)
                num[i] = num[i + 1];
            else
                num[i] = num[i] % num[i + 1];
        }
        sort(num, num + n, cmp);
    }
    return num[0];
}



int main ()
{
    int T;
    cin >> T ;
    int tip= 0 ;

    while (T--)
    {
        int L_side , R_side ;
        cin >> L_side >> R_side ;
        int num ;
        int biaoji [num];
        cin >> num ;
        for (int j = L_side ; j <= R_side ; j++)
        {
            biaoji[tip]=j;
            for (int i = L_side ; i <= R_side ; i++)
        {

            for (int j = 0; j < num ; j++)
            {

            }


            tip++;
        }
        }
    }
}