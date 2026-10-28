#include "testlib.h"
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

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    if (argc != 3) {
        cerr << "Usage: generator <type> <seed>\n";
        return 1;
    }

    string type = argv[1];
    long long seed = atoll(argv[2]);
    rnd.setSeed(seed);

    long long year = 2024;
    int month = 2;
    int day = 28;
    long long k = 1;
    if (type == "sample") {
        year = 2024;
        month = 2;
        day = 28;
        k = 2;
    } else if (type == "zero-days") {
        year = 2023;
        month = 5;
        day = 17;
        k = 0;
    } else if (type == "month-end") {
        year = 2023;
        month = 2;
        day = 28;
        k = 2;
    } else if (type == "leap") {
        year = 2024;
        month = 2;
        day = 28;
        k = (seed & 1) ? 1 : 2;
    } else if (type == "century") {
        year = 2100;
        month = 2;
        day = 28;
        k = 1;
    } else if (type == "random") {
        year = rnd.next(1LL, 3999990000LL);
        month = rnd.next(1, 12);
        day = rnd.next(1, daysInMonth(year, month));
        k = rnd.next(0LL, 100000LL);
    } else if (type == "large-k") {
        year = 2020;
        month = 1;
        day = 1;
        k = 100000;
    } else if (type == "max") {
        year = 3999999000LL;
        month = 12;
        day = 31;
        k = 100000;
    } else {
        cerr << "Unknown case type: " << type << '\n';
        return 2;
    }

    cout << year << ' ' << month << ' ' << day << ' ' << k << '\n';
    return 0;
}
