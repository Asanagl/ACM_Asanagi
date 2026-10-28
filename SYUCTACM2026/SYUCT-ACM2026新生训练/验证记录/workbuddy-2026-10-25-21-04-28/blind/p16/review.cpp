#include <cstdio>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    long long mainSum = 0, antiSum = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            long long x;
            if (scanf("%lld", &x) != 1) return 0;
            if (i == j) mainSum += x;
            if (i + j == n - 1) antiSum += x;
        }
    }

    printf("%lld\n%lld\n", mainSum, antiSum);
    return 0;
}
