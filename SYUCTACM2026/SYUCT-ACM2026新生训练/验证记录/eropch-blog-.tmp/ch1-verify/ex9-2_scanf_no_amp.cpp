#include <cstdio>
int main()
{
    int a = 0;
    scanf("%d", a);   // 漏了 &：把 a 的值当成了地址
    printf("%d\n", a);
    return 0;
}
