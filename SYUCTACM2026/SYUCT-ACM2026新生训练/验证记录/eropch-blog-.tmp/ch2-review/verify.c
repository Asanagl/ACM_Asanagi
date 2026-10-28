#include <stdio.h>

int main(void)
{
    // 2.5.2 修正方法一：只有奇数才累加，更新放到 if 外
    {
        int n = 5, sum = 0, i = 1;
        while (i <= n)
        {
            if (i % 2 != 0) sum += i;
            i++;
        }
        printf("fix1 n=5 -> %d (expect 9)\n", sum);
    }
    // 2.9.1 数位和
    {
        long long n = 1234;
        int digitSum = 0;
        while (n > 0) { digitSum += n % 10; n /= 10; }
        printf("digitsum 1234 -> %d (expect 10)\n", digitSum);
    }
    // 2.13.1 找约数
    {
        int n = 12;
        printf("divisors of 12: ");
        for (int d = 1; d <= n; d++)
            if (n % d == 0) printf("%d ", d);
        printf("(expect 1 2 3 4 6 12)\n");
    }
    // __int128 阶乘上限：33! 可表示，34! 溢出
    {
        __int128 f = 1;
        for (int i = 1; i <= 34; i++)
        {
            f *= i;
            char buf[64]; int p = 63; buf[63] = 0;
            __int128 x = f;
            int neg = 0;
            if (x < 0) { neg = 1; x = -x; }
            if (x == 0) buf[--p] = '0';
            while (x > 0) { buf[--p] = (char)('0' + x % 10); x /= 10; }
            if (neg) buf[--p] = '-';
            printf("%d! = %s\n", i, &buf[p]);
        }
    }
    return 0;
}
