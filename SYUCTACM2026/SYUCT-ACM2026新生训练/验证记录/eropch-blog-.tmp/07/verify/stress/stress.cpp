// Differential stress harness for problem 07 (palindrome).
// Fixed seed 12345; runs >= 100 rounds of small-data comparison between
// the main solution, the reference solution and an independent brute force.
#include <bits/stdc++.h>

using namespace std;

static string runCapture(const string& cmd) {
    FILE* p = _popen(cmd.c_str(), "rb");
    if (!p) {
        return "<POPEN_FAILED>";
    }
    string out;
    char buf[4096];
    size_t got;
    while ((got = fread(buf, 1, sizeof(buf), p)) > 0) {
        out.append(buf, got);
    }
    _pclose(p);
    string w;
    for (char c : out) {
        if (isspace(static_cast<unsigned char>(c))) {
            break;
        }
        w += c;
    }
    return w;
}

int main(int argc, char** argv) {
    if (argc != 5) {
        cerr << "usage: stress <rounds> <main.exe> <solution2.exe> <brute.exe>\n";
        return 2;
    }
    const long long rounds = atoll(argv[1]);
    const string mainExe = argv[2];
    const string refExe = argv[3];
    const string bruteExe = argv[4];

    mt19937_64 rng(12345ULL);

    for (long long round = 1; round <= rounds; ++round) {
        // 8 generation modes: pure random, palindromes, inner-pair mismatch,
        // outer mismatch, uniform, binary alphabet, alternating, min length.
        const int mode = static_cast<int>(rng() % 8);
        int len = 1;
        if (mode != 0) {
            len = 1 + static_cast<int>(rng() % (round <= 50 ? 8 : 40));
        }

        string s(static_cast<size_t>(len), 'a');
        const int alph = (mode == 5) ? 1 : (mode == 6 ? 2 : static_cast<int>(1 + rng() % 3));
        for (int i = 0; i < len; ++i) {
            s[i] = static_cast<char>('a' + static_cast<int>(rng() % static_cast<unsigned long long>(alph)));
        }

        if (mode == 1 || mode == 2) {
            for (int i = 0; i < len / 2; ++i) {
                s[len - 1 - i] = s[i];
            }
            if (mode == 2 && len >= 2) {
                const int p = len / 2 - 1;
                char c = s[p];
                while (c == s[p]) {
                    c = static_cast<char>('a' + static_cast<int>(rng() % 26));
                }
                s[p] = c;
            }
        } else if (mode == 3) {
            for (int i = 0; i < len / 2; ++i) {
                s[len - 1 - i] = s[i];
            }
            s[0] = static_cast<char>('a' + static_cast<int>(rng() % 26));
            if (len == 1) {
                s = "aa";
            }
        } else if (mode == 4) {
            const char c = static_cast<char>('a' + static_cast<int>(rng() % 2));
            s.assign(static_cast<size_t>(len), c);
        } else if (mode == 7) {
            const char first = static_cast<char>('a' + static_cast<int>(rng() % 26));
            char second = first;
            while (second == first) {
                second = static_cast<char>('a' + static_cast<int>(rng() % 26));
            }
            for (int i = 0; i < len; ++i) {
                s[i] = (i % 2 == 0) ? first : second;
            }
        }

        {
            ofstream f("s.in", ios::binary);
            f << s << "\n";
        }

        const string a = runCapture("\"" + mainExe + "\" < s.in");
        const string b = runCapture("\"" + refExe + "\" < s.in");
        const string c = runCapture("\"" + bruteExe + "\" < s.in");

        if (a.empty() || b.empty() || c.empty()) {
            cerr << "round " << round << ": empty output (crash?) len=" << s.size() << " input=" << s << "\n";
            ofstream bad("failing-case.txt", ios::binary);
            bad << s << "\n";
            return 1;
        }
        if (a != b || a != c) {
            cerr << "round " << round << " MISMATCH len=" << s.size() << " input=" << s
                 << " main=" << a << " ref=" << b << " brute=" << c << "\n";
            ofstream bad("failing-case.txt", ios::binary);
            bad << s << "\n";
            return 1;
        }
    }

    cout << "OK " << rounds << " rounds (seed=12345)\n";
    return 0;
}
