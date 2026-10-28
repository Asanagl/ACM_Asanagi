#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

bool isLetter(int c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

string randomFromPool(int n, const string& pool) {
    string s;
    s.reserve(n);
    for (int i = 0; i < n; ++i) {
        s += pool[rnd.next(0, static_cast<int>(pool.size()) - 1)];
    }
    return s;
}

string printablePool() {
    string pool;
    for (int c = 32; c <= 126; ++c) {
        pool += static_cast<char>(c);
    }
    return pool;
}

string nonletterPool() {
    string pool;
    for (int c = 32; c <= 126; ++c) {
        if (!isLetter(c)) {
            pool += static_cast<char>(c);
        }
    }
    return pool;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    if (argc != 3) {
        cerr << "Usage: generator <type> <seed>\n";
        return 1;
    }

    const string type = argv[1];
    const long long seed = atoll(argv[2]);
    rnd.setSeed(seed);

    const string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const string printable = printablePool();
    string s;

    if (type == "sample") {
        s = "SyuctOJ 04: AbZ-z!";
    } else if (type == "sample-spaces") {
        s = "  Hello World  ";
    } else if (type == "min-upper") {
        s = "A";
    } else if (type == "min-lower") {
        s = "a";
    } else if (type == "min-digit") {
        s = "0";
    } else if (type == "min-space") {
        s = " ";
    } else if (type == "min-punct") {
        s = "~";
    } else if (type == "upper-alphabet") {
        s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    } else if (type == "lower-alphabet") {
        s = "abcdefghijklmnopqrstuvwxyz";
    } else if (type == "nonletters-all") {
        s = nonletterPool();
    } else if (type == "spaces-only") {
        s = string(1000, ' ');
    } else if (type == "repeated-upper") {
        s = string(1000, 'Q');
    } else if (type == "repeated-lower") {
        s = string(999, 'q');
    } else if (type == "repeated-punctuation") {
        s = string(1000, '~');
    } else if (type == "alternating-lower-first") {
        for (int i = 0; i < 1000; ++i) {
            s += i % 2 == 0 ? 'a' : 'A';
        }
    } else if (type == "alternating-upper-first") {
        for (int i = 0; i < 1000; ++i) {
            s += i % 2 == 0 ? 'A' : 'a';
        }
    } else if (type == "ascii-all") {
        s = printable;
    } else if (type == "ascii-all-reversed") {
        s = printable;
        reverse(s.begin(), s.end());
    } else if (type == "leading-trailing-spaces") {
        s = "   Ab zZ   ";
    } else if (type == "repeated-spaces") {
        s = "A  b   C    z";
    } else if (type == "letter-boundaries") {
        s = "AZaz";
    } else if (type == "kill-position") {
        s = "aA0z";
    } else if (type == "kill-xor") {
        s = "09 !~";
    } else if (type == "kill-token") {
        s = "a B";
    } else if (type == "kill-last") {
        s = "!a";
    } else if (type == "kill-range") {
        s = "[\\]^_`aZ";
    } else if (type == "kill-oneway") {
        s = "aAzZ09 !";
    } else if (type == "random-small") {
        s = randomFromPool(rnd.next(1, 32), printable);
    } else if (type == "random-medium") {
        s = randomFromPool(rnd.next(33, 200), printable);
    } else if (type == "random-letters") {
        s = randomFromPool(rnd.next(1, 1000), letters);
    } else if (type == "random-with-spaces") {
        string pool = letters + "0123456789!@#$%^&*()-_=+[]{};:,.<>/?" + string(12, ' ');
        s = randomFromPool(rnd.next(1, 1000), pool);
    } else if (type == "near-max-random") {
        s = randomFromPool(999, printable);
    } else if (type == "near-max-pattern") {
        const string pattern = "aA 0!";
        for (int i = 0; i < 999; ++i) {
            s += pattern[i % pattern.size()];
        }
    } else if (type == "max-random") {
        s = randomFromPool(1000, printable);
    } else if (type == "max-letters") {
        s = randomFromPool(1000, letters);
    } else if (type == "max-nonletters") {
        s = randomFromPool(1000, nonletterPool());
    } else if (type == "max-mixed") {
        const string pool = letters + "0123456789!@#$%^&*()-_=+[]{};:,.<>/?" + string(24, ' ');
        s = randomFromPool(1000, pool);
    } else if (type == "max-cycle") {
        const int offset = rnd.next(0, 94);
        for (int i = 0; i < 1000; ++i) {
            s += static_cast<char>(32 + (offset + i) % 95);
        }
    } else if (type == "max-sparse-letters") {
        s = string(1000, ' ');
        for (int i = 0; i < 1000; i += 97) {
            s[i] = letters[(i / 97) % letters.size()];
        }
        s[999] = 'z';
    } else if (type == "max-upper") {
        s = randomFromPool(1000, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    } else if (type == "max-lower") {
        s = randomFromPool(1000, "abcdefghijklmnopqrstuvwxyz");
    } else {
        cerr << "Unknown case type: " << type << '\n';
        return 2;
    }

    cout << s << '\n';
    return 0;
}
