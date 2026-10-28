#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);

    int number = 1;
    for (int row = 1; row <= n; row++)
    {
        for (int count = 1; count <= n - row + 1; count++)
        {
            printf("%02d", number);
            number++;
        }
        printf("\n");
    }
    return 0;
}
