#include "testlib.h"

#include <bits/stdc++.h>

using namespace std;

static const char *kAlphabet = "abcdefghijklmnopqrstuvwxyz0123456789";
static const char *kDigits = "0123456789";

static char pick(const char *alphabet) {
    return alphabet[rnd.next(static_cast<int>(strlen(alphabet)))];
}

static string randomString(int len, const char *alphabet) {
    string s;
    s.reserve(len);
    for (int i = 0; i < len; ++i) {
        s.push_back(pick(alphabet));
    }
    return s;
}

static string sameChar(int len, const char *alphabet) {
    return string(len, pick(alphabet));
}

static string palindrome(int len) {
    string half = randomString((len + 1) / 2, kAlphabet);
    string s = half;
    for (int i = len / 2 - 1; i >= 0; --i) {
        s.push_back(half[i]);
    }
    return s;
}

static string alternating(int len) {
    char a = pick(kAlphabet);
    char b = pick(kAlphabet);
    while (b == a) {
        b = pick(kAlphabet);
    }
    string s;
    s.reserve(len);
    for (int i = 0; i < len; ++i) {
        s.push_back(i % 2 == 0 ? a : b);
    }
    return s;
}

static string cyclicRun(int len, bool ascending) {
    string s;
    s.reserve(len);
    for (int i = 0; i < len; ++i) {
        int offset = ascending ? i % 26 : 25 - i % 26;
        s.push_back(static_cast<char>('a' + offset));
    }
    return s;
}

static string nonPalindrome(int len) {
    string s = randomString(len, kAlphabet);
    if (s.front() == s.back()) {
        s.back() = s.front() == 'a' ? 'b' : 'a';
    }
    return s;
}

static string distinctMiddlePair(int len) {
    string s = nonPalindrome(len);
    if (s[len / 2 - 1] == s[len / 2]) {
        s[len / 2] = s[len / 2 - 1] == 'a' ? 'b' : 'a';
        if (s.front() == s.back()) {
            s.back() = s.front() == 'a' ? 'z' : 'a';
        }
    }
    return s;
}

static string mixedRuns(int total) {
    string s;
    s.reserve(total);
    int runLength = 1;
    int offset = 0;
    while (static_cast<int>(s.size()) < total) {
        int take = min(runLength, total - static_cast<int>(s.size()));
        s.append(take, kAlphabet[offset % 36]);
        ++offset;
        ++runLength;
    }
    return s;
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    if (argc != 3) {
        cerr << "Usage: generator <type> <seed>\n";
        return 1;
    }

    const string type = argv[1];
    rnd.setSeed(atoll(argv[2]));

    const int N_MAX = 1000000;

    string s;
    if (type == "sample") {
        s = "abca12";
    } else if (type == "sample-2") {
        s = "syuctacm2026";
    } else if (type == "min-digit") {
        s = string(1, pick(kDigits));
    } else if (type == "min-letter") {
        s = string(1, static_cast<char>('a' + rnd.next(26)));
    } else if (type == "len2-distinct") {
        char a = pick(kAlphabet);
        char b = pick(kAlphabet);
        while (b == a) {
            b = pick(kAlphabet);
        }
        s = string(1, a) + b;
    } else if (type == "len2-same") {
        s = sameChar(2, kAlphabet);
    } else if (type == "len3") {
        s = randomString(3, kAlphabet);
        while (s[0] == s[2]) {
            s = randomString(3, kAlphabet);
        }
    } else if (type == "digits-leading") {
        s = "1000";
    } else if (type == "digits-zeros") {
        s = "000000";
    } else if (type == "digits-long") {
        int len = rnd.next(150, 300);
        s = pick(kDigits) + randomString(len - 1, kDigits);
        s[0] = '0';
    } else if (type == "pal-odd") {
        s = palindrome(rnd.next(3, 9) | 1);
    } else if (type == "pal-even") {
        s = palindrome(rnd.next(2, 9) & ~1);
    } else if (type == "pal-odd-large") {
        s = palindrome(100001);
    } else if (type == "same-small") {
        s = sameChar(12, kAlphabet);
    } else if (type == "same-large") {
        s = sameChar(N_MAX, kAlphabet);
    } else if (type == "alternating-small") {
        s = alternating(1000);
    } else if (type == "alternating-large") {
        s = alternating(N_MAX);
    } else if (type == "ascending") {
        s = cyclicRun(1000, true);
    } else if (type == "descending") {
        s = cyclicRun(1000, false);
    } else if (type == "nonpal-odd") {
        s = nonPalindrome(1001);
    } else if (type == "nonpal-even") {
        s = nonPalindrome(1000);
    } else if (type == "four-distinct") {
        s = "abcd";
    } else if (type == "kill-even-mid") {
        s = distinctMiddlePair(rnd.next(1, 500) * 2);
    } else if (type == "random-small") {
        s = nonPalindrome(rnd.next(2, 100));
    } else if (type == "random-binary") {
        char a = pick(kAlphabet);
        char b = pick(kAlphabet);
        while (b == a) {
            b = pick(kAlphabet);
        }
        int len = rnd.next(3, 60);
        s.reserve(len);
        for (int i = 0; i < len; ++i) {
            s.push_back(i % 2 == 0 ? a : b);
        }
        if (s.front() == s.back()) {
            s.back() = s.front() == 'a' ? 'b' : 'a';
        }
    } else if (type == "random-digits") {
        s = randomString(rnd.next(2, 80), kDigits);
        if (s.front() == s.back()) {
            s.back() = s.front() == '0' ? '1' : '0';
        }
    } else if (type == "random-alnum") {
        s = nonPalindrome(rnd.next(2, 200));
    } else if (type == "mixed-runs") {
        s = mixedRuns(5000);
    } else if (type == "random-large") {
        s = nonPalindrome(rnd.next(300000, 700000));
    } else if (type == "near-max") {
        s = nonPalindrome(N_MAX - rnd.next(0, 1));
    } else if (type == "max-random") {
        s = nonPalindrome(N_MAX);
    } else if (type == "max-same") {
        s = sameChar(N_MAX, kAlphabet);
    } else if (type == "max-alternating") {
        s = alternating(N_MAX);
    } else if (type == "max-ascending") {
        s = cyclicRun(N_MAX, true);
    } else if (type == "max-pal") {
        s = palindrome(N_MAX);
    } else if (type == "max-digits") {
        s = randomString(N_MAX, kDigits);
    } else if (type == "max-nonpal") {
        s = nonPalindrome(N_MAX);
    } else {
        cerr << "Unknown case type: " << type << '\n';
        return 2;
    }

    cout << s << '\n';
    return 0;
}
