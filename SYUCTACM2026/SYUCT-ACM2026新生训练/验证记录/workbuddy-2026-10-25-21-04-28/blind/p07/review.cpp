// 独立实现：判断给定小写字母串是否为回文串
// 输入：一行字符串 s (1 <= |s| <= 100000)
// 输出：YES / NO
#include <cstdio>
#include <cstring>

int main() {
    static char s[100005];
    if (scanf("%100000s", s) != 1) {
        // 理论上不会发生（保证非空且只有一行），保守按非回文处理
        return 0;
    }
    int n = (int)strlen(s);
    int l = 0, r = n - 1;
    while (l < r) {
        if (s[l] != s[r]) {
            printf("NO\n");
            return 0;
        }
        ++l;
        --r;
    }
    printf("YES\n");
    return 0;
}
