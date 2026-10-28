#include <bits/stdc++.h>

using namespace std;

static int daysInMonthWrong(long long, int) {
    return 30;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long year, days;
    int month, day;
    cin >> year >> month >> day >> days;
    while (days-- > 0) {
        ++day;
        if (day > daysInMonthWrong(year, month)) {
            day = 1;
            if (++month > 12) {
                month = 1;
                ++year;
            }
        }
    }
    cout << year << ' ' << month << ' ' << day << '\n';
    return 0;
}
