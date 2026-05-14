#include <bits/stdc++.h>
using namespace std;
int main() {
    string pinyin[] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    
    string num;
    cin >> num; 
    for (int i = 0; i < num.length(); i++) {
        char c = num[i];
        if (c == '-') {
            cout << "fu";
        } else {
            cout << pinyin[ c - '0'];
        }
        if (i != num.length() - 1) {
            cout << " ";
        }
    }
    return 0;
}