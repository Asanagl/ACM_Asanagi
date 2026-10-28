#include "testlib.h"

static bool isLeap(long long year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

static int daysInMonth(long long year, long long month) {
    static const int days[] = {0, 31, 28, 31, 30, 31, 30,
                               31, 31, 30, 31, 30, 31};
    if (month == 2) {
        return days[month] + (isLeap(year) ? 1 : 0);
    }
    return days[month];
}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    long long year = inf.readLong(1LL, 4000000000LL, "y");
    inf.skipBlanks();
    long long month = inf.readLong(1LL, 12LL, "m");
    inf.skipBlanks();
    long long day = inf.readLong(1LL, daysInMonth(year, month), "d");
    inf.skipBlanks();
    long long days = inf.readLong(0LL, 100000LL, "k");
    inf.seekEof();

    while (days-- > 0) {
        ++day;
        if (day > daysInMonth(year, month)) {
            day = 1;
            ++month;
            if (month > 12) {
                month = 1;
                ++year;
            }
        }
    }

    ensuref(year <= 4000000000LL,
            "the date after advancing k days exceeds the year limit");
    inf.readEof();
    return 0;
}
