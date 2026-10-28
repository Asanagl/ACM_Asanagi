#include <bits/stdc++.h>

using namespace std;

bool read_values(vector<long long> &values) {
    long long n = 0;
    if (!(cin >> n) || n < 1 || n > 200001 || n % 2 == 0) {
        return false;
    }
    values.resize(static_cast<size_t>(n));
    for (long long &value : values) {
        if (!(cin >> value) || value < -1000000000LL || value > 1000000000LL) {
            return false;
        }
    }
    return true;
}

long long distance_sum(const vector<long long> &values, long long median) {
    long long answer = 0;
    for (const long long value : values) {
        const long long distance = value >= median ? value - median : median - value;
        if (distance > numeric_limits<long long>::max() - answer) {
            return -1;
        }
        answer += distance;
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    try {
        vector<long long> values;
        if (!read_values(values)) {
            return 0;
        }
        sort(values.begin(), values.end());
        const long long median = values[(values.size() - 1) / 2];
        const long long answer = distance_sum(values, median);
        if (answer < 0) {
            return 0;
        }
        cout << median << ' ' << answer << '\n';
    } catch (const exception &) {
        return 0;
    }
    return 0;
}
