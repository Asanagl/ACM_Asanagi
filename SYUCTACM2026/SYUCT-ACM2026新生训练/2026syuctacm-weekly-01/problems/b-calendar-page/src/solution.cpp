#include <bits/stdc++.h>

using namespace std;

bool is_leap(long long year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

int days_in_month(long long year, long long month) {
    static constexpr int days[] = {31, 28, 31, 30, 31, 30,
                                   31, 31, 30, 31, 30, 31};
    if (month == 2) {
        return days[1] + static_cast<int>(is_leap(year));
    }
    return days[static_cast<size_t>(month - 1)];
}

bool read_date(long long &year, long long &month, long long &day, long long &k) {
    if (!(cin >> year >> month >> day >> k)) {
        return false;
    }
    if (year < 1 || year > 4000000000LL || month < 1 || month > 12 ||
        k < 0 || k > 100000) {
        return false;
    }
    return day >= 1 && day <= days_in_month(year, month);
}

void advance_one_day(long long &year, long long &month, long long &day) {
    ++day;
    if (day <= days_in_month(year, month)) {
        return;
    }
    day = 1;
    ++month;
    if (month <= 12) {
        return;
    }
    month = 1;
    ++year;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    try {
        long long year = 0;
        long long month = 0;
        long long day = 0;
        long long k = 0;
        if (!read_date(year, month, day, k)) {
            return 0;
        }
        for (long long step = 0; step < k; ++step) {
            advance_one_day(year, month, day);
        }
        if (year > 4000000000LL) {
            return 0;
        }
        cout << year << ' ' << month << ' ' << day << '\n';
    } catch (const exception &) {
        return 0;
    }
    return 0;
}
