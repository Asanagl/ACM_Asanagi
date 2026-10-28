#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    if (argc != 3) {
        cerr << "Usage: generator <type> <seed>\n";
        return 1;
    }

    string type = argv[1];
    long long seed = atoll(argv[2]);
    rnd.setSeed(seed);

    vector<long long> values;
    if (type == "sample") {
        values = {9, 1, 7, 3, 5};
    } else if (type == "min") {
        values = {0};
    } else if (type == "negative") {
        values = {-5, -1, -9, -3, -7};
    } else if (type == "duplicate") {
        values = {4, 100, 4, -50, 7, 8, 99};
    } else if (type == "random") {
        mt19937_64 engine(static_cast<uint64_t>(seed));
        uniform_int_distribution<long long> value(-1000000000LL, 1000000000LL);
        values.resize(101);
        for (long long& item : values) {
            item = value(engine);
        }
        vector<long long> sorted = values;
        sort(sorted.begin(), sorted.end());
        if (values[values.size() / 2] == sorted[sorted.size() / 2]) {
            values[values.size() / 2] = sorted.front();
        }
    } else if (type == "large-sum" || type == "max") {
        values.assign(200001, 1000000000LL);
        fill(values.begin(), values.begin() + 100000, -1000000000LL);
        values[100000] = 0;
        if (type == "max") {
            mt19937_64 engine(static_cast<uint64_t>(seed));
            shuffle(values.begin(), values.end(), engine);
            auto middle = values.begin() + values.size() / 2;
            auto positive = find(values.begin(), values.end(), 1000000000LL);
            if (positive != values.end()) {
                iter_swap(middle, positive);
            }
        }
    } else {
        cerr << "Unknown case type: " << type << '\n';
        return 2;
    }

    cout << values.size() << '\n';
    for (size_t i = 0; i < values.size(); ++i) {
        if (i != 0) {
            cout << ' ';
        }
        cout << values[i];
    }
    cout << '\n';
    return 0;
}
