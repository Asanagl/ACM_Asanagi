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

    long long n = 1;
    if (type == "sample") {
        n = 12;
    } else if (type == "one") {
        n = 1;
    } else if (type == "square") {
        n = 1000000LL * 1000000LL;
    } else if (type == "prime") {
        n = 1000000007LL;
    } else if (type == "highly-composite") {
        n = 963460800LL;
    } else if (type == "random") {
        n = rnd.next(1LL, 1000000000000LL);
    } else if (type == "max") {
        n = 1000000000000LL;
    } else {
        cerr << "Unknown case type: " << type << '\n';
        return 2;
    }

    cout << n << '\n';
    return 0;
}
