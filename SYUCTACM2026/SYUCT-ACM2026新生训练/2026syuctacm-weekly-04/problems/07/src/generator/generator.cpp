#include "testlib.h"

#include <bits/stdc++.h>

using namespace std;

const int MAXLEN = 100000;

string randomString(int len) {
    string s(len, 'a');
    for (int i = 0; i < len; ++i) {
        s[i] = static_cast<char>('a' + rnd.next(0, 25));
    }
    return s;
}

char differentFrom(char c) {
    char d = c;
    while (d == c) {
        d = static_cast<char>('a' + rnd.next(0, 25));
    }
    return d;
}

string makePalindrome(int len) {
    string s = randomString(len);
    for (int i = 0; i < len / 2; ++i) {
        s[len - 1 - i] = s[i];
    }
    return s;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    if (argc != 3) {
        cerr << "Usage: generator <type> <seed>\n";
        return 1;
    }

    const string type = argv[1];
    rnd.setSeed(atoll(argv[2]));

    string s;

    if (type == "sample-1") {
        s = "a";
    } else if (type == "sample-2") {
        s = "ababa";
    } else if (type == "sample-3") {
        s = "abba";
    } else if (type == "sample-4") {
        s = "abcab";
    } else if (type == "sample-5") {
        s = "abxbba";
    } else if (type == "min-a") {
        s = "a";
    } else if (type == "min-z") {
        s = "z";
    } else if (type == "len2-yes") {
        s = (rnd.next(0, 1) == 0) ? string("aa") : string("zz");
    } else if (type == "len2-no") {
        s = (rnd.next(0, 1) == 0) ? string("ab") : string("za");
    } else if (type == "odd-pal") {
        s = makePalindrome(rnd.next(3, 15) | 1);
    } else if (type == "odd-pal-center-z") {
        int len = rnd.next(3, 15) | 1;
        s = makePalindrome(len);
        s[len / 2] = 'z';
    } else if (type == "odd-inner-no") {
        int len = rnd.next(2, 7) * 2 + 1;
        s = makePalindrome(len);
        s[len / 2 - 1] = differentFrom(s[len / 2 - 1]);
    } else if (type == "odd-outer-no") {
        int len = rnd.next(3, 15) | 1;
        s = makePalindrome(len);
        s[0] = differentFrom(s[0]);
    } else if (type == "even-pal") {
        s = makePalindrome(rnd.next(2, 8) * 2);
    } else if (type == "even-inner-no") {
        int len = rnd.next(2, 8) * 2;
        s = makePalindrome(len);
        s[len / 2 - 1] = differentFrom(s[len / 2 - 1]);
    } else if (type == "even-outer-no") {
        int len = rnd.next(2, 8) * 2;
        s = makePalindrome(len);
        s[0] = differentFrom(s[0]);
    } else if (type == "same") {
        s.assign(rnd.next(2, 1000), static_cast<char>('a' + rnd.next(0, 25)));
    } else if (type == "same-max") {
        s.assign(MAXLEN, static_cast<char>('a' + rnd.next(0, 25)));
    } else if (type == "alt") {
        int len = rnd.next(2, 100);
        char first = static_cast<char>('a' + rnd.next(0, 25));
        char second = differentFrom(first);
        s.clear();
        for (int i = 0; i < len; ++i) {
            s += (i % 2 == 0 ? first : second);
        }
    } else if (type == "alt-max") {
        char first = static_cast<char>('a' + rnd.next(0, 25));
        char second = differentFrom(first);
        s.clear();
        for (int i = 0; i < MAXLEN; ++i) {
            s += (i % 2 == 0 ? first : second);
        }
    } else if (type == "max-odd-pal") {
        s = makePalindrome(MAXLEN - 1);
    } else if (type == "max-even-pal") {
        s = makePalindrome(MAXLEN);
    } else if (type == "max-even-inner-no") {
        s = makePalindrome(MAXLEN);
        s[MAXLEN / 2 - 1] = differentFrom(s[MAXLEN / 2 - 1]);
    } else if (type == "max-odd-inner-no") {
        s = makePalindrome(MAXLEN - 1);
        s[(MAXLEN - 1) / 2 - 1] = differentFrom(s[(MAXLEN - 1) / 2 - 1]);
    } else if (type == "max-outer-no") {
        s = makePalindrome(MAXLEN);
        s[0] = differentFrom(s[0]);
    } else if (type == "border-no") {
        int len = rnd.next(3, 20);
        s = makePalindrome(len);
        s[0] = differentFrom(s[0]);
    } else if (type == "mid-no") {
        int len = rnd.next(10, 1000);
        s = makePalindrome(len);
        int pos = rnd.next(1, len / 2 - 1);
        s[pos] = differentFrom(s[pos]);
    } else if (type == "rand-small") {
        s = randomString(rnd.next(2, 10));
    } else if (type == "rand-pal-odd") {
        s = makePalindrome(rnd.next(1, 49999) * 2 + 1);
    } else if (type == "rand-pal-even") {
        s = makePalindrome(rnd.next(2, 50000) * 2);
    } else if (type == "rand") {
        s = randomString(rnd.next(1, MAXLEN));
    } else if (type == "near-max-rand") {
        s = randomString(MAXLEN - 1);
    } else if (type == "near-max-pal") {
        s = makePalindrome(MAXLEN - 1);
    } else {
        cerr << "Unknown case type: " << type << '\n';
        return 2;
    }

    cout << s << '\n';
    return 0;
}
