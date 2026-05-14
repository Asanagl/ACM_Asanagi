#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int solve_for_target(const string& s, char start_char) {
    int n = s.size();
    // 构建目标字符串t，但不显式构建，直接比较
    int cnt = 0;
    int last_pos = -1; // 记录当前组最后一个位置在need数组中的索引？实际上我们需要记录上一个need位置
    char last_char;
    for (int i = 0; i < n; ++i) {
        char target_char = (i % 2 == 0) ? start_char : (start_char == '0' ? '1' : '0');
        if (s[i] != target_char) {
            if (last_pos == -1) {
                // 第一个need位置
                last_pos = i;
                last_char = s[i];
            } else {
                if (s[i] != last_char) {
                    // 可以合并到当前组
                    last_char = s[i]; // 更新最后一个字符
                } else {
                    // 不能合并，结束当前组
                    cnt++;
                    last_pos = i;
                    last_char = s[i];
                }
            }
        }
    }
    if (last_pos != -1) cnt++; // 最后一组
    return cnt;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    // 检查是否已经是交替
    bool is_alt = true;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i+1]) {
            is_alt = false;
            break;
        }
    }
    if (is_alt) {
        cout << 0 << endl;
        return 0;
    }
    int ans1 = solve_for_target(s, '0');
    int ans2 = solve_for_target(s, '1');
    cout << min(ans1, ans2) << endl;
    return 0;
}