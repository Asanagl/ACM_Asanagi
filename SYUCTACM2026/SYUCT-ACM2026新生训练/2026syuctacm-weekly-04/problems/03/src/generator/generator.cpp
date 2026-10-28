#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    if (argc != 3) {
        cerr << "Usage: generator <type> <seed>\n";
        return 1;
    }

    const string type = argv[1];
    const long long seed = atoll(argv[2]);
    rnd.setSeed(seed);

    const string vowels = "aeiou";

    auto isVowelLower = [](char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };

    auto toUpper = [](char c) { return char(c - 'a' + 'A'); };

    auto anyLetter = [&]() {
        char c = char('a' + rnd.next(0, 25));
        if (rnd.next(0, 1)) c = toUpper(c);
        return c;
    };

    auto vowelLetter = [&]() {
        char c = vowels[rnd.next(0, 4)];
        if (rnd.next(0, 1)) c = toUpper(c);
        return c;
    };

    auto consonantLetter = [&]() {
        char c;
        do {
            c = char('a' + rnd.next(0, 25));
        } while (isVowelLower(c));
        if (rnd.next(0, 1)) c = toUpper(c);
        return c;
    };

    auto uniformRandom = [&](int len) {
        string s;
        s.reserve(len);
        for (int i = 0; i < len; ++i) s += anyLetter();
        return s;
    };

    auto vowelHeavyMixed = [&](int len) {
        string s;
        s.reserve(len);
        for (int i = 0; i < len; ++i) {
            int kind = rnd.next(0, 3);
            if (kind <= 1) s += vowelLetter();
            else s += consonantLetter();
        }
        return s;
    };

    string s;
    if (type == "sample") {
        s = "HeLloWorld";
    } else if (type == "sample2") {
        s = "AEIOUaeiou";
    } else if (type == "sample3") {
        s = "yes";
    } else if (type == "min") {
        s = "a";
    } else if (type == "min-consonant") {
        s = "Z";
    } else if (type == "single-y") {
        s = "y";
    } else if (type == "single-u") {
        s = "u";
    } else if (type == "small-mixed") {
        s = vowelHeavyMixed(rnd.next(2, 50));
    } else if (type == "all-lower-vowels") {
        for (int i = 0; i < 200; ++i) s += "aeiou";
    } else if (type == "all-upper-vowels") {
        for (int i = 0; i < 200; ++i) s += "AEIOU";
    } else if (type == "no-vowels") {
        for (int i = 0; i < 500; ++i) s += consonantLetter();
    } else if (type == "y-heavy") {
        for (int i = 0; i < 2000; ++i) {
            int kind = rnd.next(0, 99);
            if (kind < 40) s += (rnd.next(0, 1) ? 'y' : 'Y');
            else if (kind < 70) s += vowelLetter();
            else s += consonantLetter();
        }
    } else if (type == "upper-heavy") {
        for (int i = 0; i < 2000; ++i) {
            char c = char('a' + rnd.next(0, 25));
            if (rnd.next(0, 99) < 75) c = toUpper(c);
            s += c;
        }
    } else if (type == "u-heavy") {
        for (int i = 0; i < 2000; ++i) {
            int kind = rnd.next(0, 99);
            if (kind < 45) s += (rnd.next(0, 1) ? 'u' : 'U');
            else s += anyLetter();
        }
    } else if (type == "boundary-near-max") {
        s = uniformRandom(999999);
    } else if (type == "boundary-max") {
        s = uniformRandom(1000000);
    } else if (type == "max-same-lower") {
        s = string(1000000, 'a');
    } else if (type == "max-same-upper") {
        s = string(1000000, 'A');
    } else if (type == "random-small") {
        s = uniformRandom(rnd.next(2, 1000));
    } else if (type == "random-mid") {
        s = uniformRandom(rnd.next(1000, 100000));
    } else if (type == "random-large") {
        s = uniformRandom(rnd.next(100000, 1000000));
    } else if (type == "random-max") {
        s = uniformRandom(1000000);
    } else {
        cerr << "Unknown case type: " << type << '\n';
        return 2;
    }

    cout << s << '\n';
    return 0;
}
