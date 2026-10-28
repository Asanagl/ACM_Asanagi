#include <bits/stdc++.h>

using namespace std;

bool load_values(vector<long long> &values) {
    long long n = 0;
    if (!(cin >> n) || n < 1 || n > 200001 || n % 2 == 0) {
        return false;
    }
    values.assign(static_cast<size_t>(n), 0);
    for (long long &value : values) {
        if (!(cin >> value) || value < -1000000000LL || value > 1000000000LL) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    try {
        vector<long long> values;
        if (!load_values(values)) {
            return 0;
        }
        const auto middle = values.begin() + static_cast<ptrdiff_t>(values.size() / 2);
        nth_element(values.begin(), middle, values.end());
        const long long median = *middle;

        long long total = 0;
        for (const long long value : values) {
            const long long distance = value >= median ? value - median : median - value;
            if (distance > numeric_limits<long long>::max() - total) {
                return 0;
            }
            total += distance;
        }
        cout << median << ' ' << total << '\n';
    } catch (const exception &) {
        return 0;
    }
    return 0;
}
