#include <bits/stdc++.h>
using namespace std;

string strct(string num1, string num2) {
    int n1 = num1.length();
    int n2 = num2.length();
    string result;
    int carry = 0;
    for (int i = n1 - 1, j = n2 - 1; i >= 0 || j >= 0; i--, j--) {
        int d1 = (i >= 0) ? (num1[i] - '0') : 0;
        int d2 = (j >= 0) ? (num2[j] - '0') : 0;
        int sub = d1 - d2 - carry;
        if (sub < 0) {
            sub += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result.push_back(sub + '0');
    }
    reverse(result.begin(), result.end());
    size_t pos = result.find_first_not_of('0');
    if (pos != string::npos) {
        return result.substr(pos);
    }
    return "0";
}

string left(const string &s, int len, char pad = '0') {
    if (s.length() >= len) return s;
    return string(len - s.length(), pad) + s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    string A, B;
    cin >> A >> B;
    
    int L = lcm(n, m);
    
    string A_ex;
    for (int i = 0; i < L / n; i++) {
        A_ex += A;
    }
    
    string B_ex;
    for (int i = 0; i < L / m; i++) {
        B_ex += B;
    }
    
    string C = strct(A_ex, B_ex);
    string C_padded = left(C, L, '0');
    
    cout << L << "\n";
    cout << C_padded << "\n";
    
    return 0;
}