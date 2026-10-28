#include <bits/stdc++.h>

using namespace std;

static bool isLeap(long long year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

static int daysInMonth(long long year, int month) {
    static const int days[] = {0, 31, 28, 31, 30, 31, 30,
                               31, 31, 30, 31, 30, 31};
    return days[month] + (month == 2 && isLeap(year));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long year, days;
    int month, day;
    cin >> year >> month >> day >> days;
    while (days-- > 0) {
        ++day;
        if (day > daysInMonth(year, month)) {
            day = 0;
            if (++month > 12) {
                month = 1;
                ++year;
            }
        }
    }
    cout << year << ' ' << month << ' ' << day << '\n';
    return 0;
}
