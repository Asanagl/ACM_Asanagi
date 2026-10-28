#include <bits/stdc++.h>

using namespace std;

struct Date {
    long long year = 0;
    long long month = 0;
    long long day = 0;
};

bool leap_year(long long year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

int month_length(const Date &date) {
    static constexpr int lengths[] = {31, 28, 31, 30, 31, 30,
                                      31, 31, 30, 31, 30, 31};
    if (date.month == 2) {
        return lengths[1] + static_cast<int>(leap_year(date.year));
    }
    return lengths[static_cast<size_t>(date.month - 1)];
}

bool read_input(Date &date, long long &days) {
    if (!(cin >> date.year >> date.month >> date.day >> days)) {
        return false;
    }
    if (date.year < 1 || date.year > 4000000000LL || date.month < 1 ||
        date.month > 12 || days < 0 || days > 100000) {
        return false;
    }
    return date.day >= 1 && date.day <= month_length(date);
}

void move_forward(Date &date) {
    ++date.day;
    if (date.day <= month_length(date)) {
        return;
    }
    date.day = 1;
    ++date.month;
    if (date.month <= 12) {
        return;
    }
    date.month = 1;
    ++date.year;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    try {
        Date date;
        long long days = 0;
        if (!read_input(date, days)) {
            return 0;
        }
        for (long long step = 0; step < days; ++step) {
            move_forward(date);
        }
        if (date.year > 4000000000LL) {
            return 0;
        }
        cout << date.year << ' ' << date.month << ' ' << date.day << '\n';
    } catch (const exception &) {
        return 0;
    }
    return 0;
}
