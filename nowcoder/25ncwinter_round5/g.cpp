#include <iostream>
#include <string>
using namespace std;

int main() {
    string ops = "0112233445142015320125410214530214510214102302142025101203201451451522302514203214510021454101002532";
    int vx = 1, vy = 1;
    string result;
    for (char c : ops) {
        int op = c - '0';
        int new_vx, new_vy;
        switch (op) {
            case 0: new_vx = -vx; new_vy = vy; break;
            case 1: new_vx = vy; new_vy = vx; break;
            case 2: new_vx = vx; new_vy = -vy; break;
            case 3: new_vx = -vy; new_vy = -vx; break;
            case 4: new_vx = vy; new_vy = -vx; break;
            case 5: new_vx = -vy; new_vy = vx; break;
        }
        vx = new_vx; vy = new_vy;
        // 确定状态
        if (vx == 1 && vy == 1) result += '0';
        else if (vx == 1 && vy == -1) result += '1';
        else if (vx == -1 && vy == -1) result += '2';
        else if (vx == -1 && vy == 1) result += '3';
    }
    cout << result << endl;
    return 0;
}