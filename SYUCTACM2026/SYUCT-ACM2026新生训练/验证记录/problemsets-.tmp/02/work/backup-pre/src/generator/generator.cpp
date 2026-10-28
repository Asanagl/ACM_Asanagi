#include "testlib.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace {

char randomNonSpace() {
    return static_cast<char>(rnd.next(33, 126));
}

string randomPrintable(int n, int spacePercent) {
    string s;
    s.reserve(n);
    for (int i = 0; i < n; ++i) {
        s.push_back(rnd.next(1, 100) <= spacePercent ? ' ' : randomNonSpace());
    }
    return s;
}

string randomFromAlphabet(int n, const string& alphabet, int spacePercent) {
    string s;
    s.reserve(n);
    for (int i = 0; i < n; ++i) {
        if (rnd.next(1, 100) <= spacePercent) {
            s.push_back(' ');
        } else {
            s.push_back(alphabet[static_cast<size_t>(rnd.next(0, static_cast<int>(alphabet.size()) - 1))]);
        }
    }
    return s;
}

string repeatToLength(const string& pattern, int n) {
    string s;
    s.reserve(n);
    for (int i = 0; i < n; ++i) {
        s.push_back(pattern[static_cast<size_t>(i % static_cast<int>(pattern.size()))]);
    }
    return s;
}

string word(int n) {
    string s;
    s.reserve(n);
    for (int i = 0; i < n; ++i) {
        s.push_back(static_cast<char>(rnd.next('a', 'z')));
    }
    return s;
}

string makeStressCase() {
    const int shape = rnd.next(0, 9);
    const int n = rnd.next(0, 80);
    if (shape == 0) {
        return "";
    }
    if (shape == 1) {
        return string(n, ' ');
    }
    if (shape == 2) {
        return randomPrintable(n, 0);
    }
    if (shape == 3) {
        return randomPrintable(n, 50);
    }
    if (shape == 4) {
        string s;
        s.reserve(n);
        for (int i = 0; i < n; ++i) {
            s.push_back(i % 2 == 0 ? ' ' : randomNonSpace());
        }
        return s;
    }
    if (shape == 5) {
        string s;
        bool spaceBlock = false;
        while (static_cast<int>(s.size()) < n) {
            const int len = min(rnd.next(1, 6), n - static_cast<int>(s.size()));
            s.append(static_cast<size_t>(len), spaceBlock ? ' ' : randomNonSpace());
            spaceBlock = !spaceBlock;
        }
        return s;
    }
    if (shape == 6) {
        string s = randomPrintable(n, 40);
        if (!s.empty()) {
            s.front() = ' ';
            s.back() = ' ';
        }
        return s;
    }
    if (shape == 7) {
        return randomPrintable(n, 90);
    }
    if (shape == 8) {
        return repeatToLength("a  b ", n);
    }
    return randomPrintable(n, 20);
}

}  // namespace

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    if (argc != 3) {
        cerr << "Usage: generator <type> <seed>\n";
        return 1;
    }

    const string type = argv[1];
    const long long seed = atoll(argv[2]);
    rnd.setSeed(seed);

    string s;
    if (type == "sample") {
        if (seed == 1) {
            s = "a  b   c";
        } else if (seed == 2) {
            s = "";
        } else if (seed == 3) {
            s = "  a   b  ";
        } else {
            cerr << "Unknown sample seed: " << seed << '\n';
            return 2;
        }
    } else if (type == "empty") {
        s = "";
    } else if (type == "single-space") {
        s = " ";
    } else if (type == "single-letter") {
        s = word(rnd.next(1, 1));
    } else if (type == "single-punctuation") {
        s = string(1, static_cast<char>(rnd.next(33, 47)));
    } else if (type == "all-space-small") {
        s = string(static_cast<size_t>(rnd.next(2, 64)), ' ');
    } else if (type == "all-space-mid") {
        s = string(static_cast<size_t>(rnd.next(3000, 5000)), ' ');
    } else if (type == "all-space-near-max") {
        s = string(static_cast<size_t>(rnd.next(99990, 99999)), ' ');
    } else if (type == "all-space-max") {
        s = string(100000, ' ');
    } else if (type == "no-space-small") {
        s = randomPrintable(rnd.next(1, 200), 0);
    } else if (type == "no-space-max") {
        string alphabet;
        for (int c = 33; c <= 126; ++c) {
            alphabet.push_back(static_cast<char>(c));
        }
        s = repeatToLength(alphabet, 100000);
    } else if (type == "leading") {
        s = string(static_cast<size_t>(rnd.next(1, 40)), ' ');
        s += word(rnd.next(1, 24));
    } else if (type == "trailing") {
        s = word(rnd.next(1, 24));
        s += string(static_cast<size_t>(rnd.next(1, 40)), ' ');
    } else if (type == "both") {
        s = string(static_cast<size_t>(rnd.next(1, 30)), ' ');
        s += word(rnd.next(1, 20));
        s += string(static_cast<size_t>(rnd.next(1, 30)), ' ');
    } else if (type == "consecutive") {
        s = word(rnd.next(1, 12));
        s += string(static_cast<size_t>(rnd.next(2, 60)), ' ');
        s += word(rnd.next(1, 12));
        s += string(static_cast<size_t>(rnd.next(2, 60)), ' ');
        s += word(rnd.next(1, 12));
    } else if (type == "runs") {
        for (int run = 1; run <= 12; ++run) {
            if (run > 1) {
                s.push_back('x');
            }
            s.append(static_cast<size_t>(run), ' ');
        }
    } else if (type == "alternating") {
        const int n = rnd.next(3, 3000);
        s.reserve(static_cast<size_t>(n));
        for (int i = 0; i < n; ++i) {
            s.push_back(i % 2 == 0 ? ' ' : static_cast<char>(rnd.next('a', 'z')));
        }
    } else if (type == "repeated") {
        static const char* patterns[] = {"ab  cd   ", "  x ", "a b  c   d    ", "   "};
        const string pattern = patterns[rnd.next(0, 3)];
        s = repeatToLength(pattern, rnd.next(1000, 10000));
    } else if (type == "boundary-chars") {
        for (int c = 33; c <= 126; ++c) {
            s.push_back(static_cast<char>(c));
            if (c % 7 == 0) {
                s.push_back(' ');
            }
        }
    } else if (type == "punctuation") {
        string alphabet;
        for (int c = 33; c <= 126; ++c) {
            const bool digit = c >= '0' && c <= '9';
            const bool upper = c >= 'A' && c <= 'Z';
            const bool lower = c >= 'a' && c <= 'z';
            if (!digit && !upper && !lower) {
                alphabet.push_back(static_cast<char>(c));
            }
        }
        s = randomFromAlphabet(rnd.next(500, 2000), alphabet, 25);
    } else if (type == "digits") {
        s = randomFromAlphabet(rnd.next(500, 2000), "0123456789", 25);
    } else if (type == "words") {
        s = "one  two   three four    five six  seven eight nine ten";
    } else if (type == "directed-cin") {
        s = "    alpha beta  gamma   ";
    } else if (type == "directed-last") {
        s = word(rnd.next(1, 12)) + " ";
    } else if (type == "directed-trim") {
        s = string(static_cast<size_t>(rnd.next(2, 6)), ' ');
        s += word(rnd.next(1, 12));
        s += string(static_cast<size_t>(rnd.next(2, 6)), ' ');
    } else if (type == "directed-buffer") {
        s = string(1000, 'a');
        s += string(600, ' ');
    } else if (type == "random-small") {
        s = randomPrintable(rnd.next(0, 48), 35);
    } else if (type == "random") {
        s = randomPrintable(rnd.next(100, 6000), 25);
    } else if (type == "dense") {
        s = randomPrintable(rnd.next(1000, 8000), 80);
    } else if (type == "mid") {
        s = randomPrintable(rnd.next(20000, 40000), 30);
    } else if (type == "near-max") {
        s = randomPrintable(rnd.next(99000, 99999), 20);
    } else if (type == "max") {
        s = randomPrintable(100000, 25);
    } else if (type == "max-dense") {
        s = randomPrintable(100000, 80);
    } else if (type == "max-pattern") {
        s = repeatToLength("a  b   c    ", 100000);
    } else if (type == "stress") {
        s = makeStressCase();
    } else {
        cerr << "Unknown case type: " << type << '\n';
        return 2;
    }

    cout << s << '\n';
    return 0;
}
