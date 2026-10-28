#include <bits/stdc++.h>

using namespace std;

// 范围/读入错误：把最长 100000 位的数字串当作整数读入 long long。
// 长度超过 19 位后读入溢出，结果错误。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n = 0;
    cin >> n;
    long long answer = 0;
    while (n > 0) {
        answer += n % 10;
        n /= 10;
    }
    cout << answer << '\n';
    return 0;
}
