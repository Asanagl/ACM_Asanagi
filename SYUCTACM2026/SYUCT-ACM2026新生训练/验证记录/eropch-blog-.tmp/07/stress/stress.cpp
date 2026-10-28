#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
    if (argc != 4) {
        cerr << "usage: stress <rounds> <main> <brute>\n";
        return 2;
    }
    long long rounds = atoll(argv[1]);
    const string mainExe = argv[2];
    const string bruteExe = argv[3];

    mt19937_64 rng(12345);

    for (long long t = 1; t <= rounds; ++t) {
        int mode = (int)(rng() % 8);
        int len = 1;
        if (mode != 0) {
            len = 1 + (int)(rng() % (t <= rounds / 2 ? 8 : 40));
        }

        string s(len, 'a');
        int alph = (mode == 5) ? 1 : (int)(1 + rng() % 3);
        for (int i = 0; i < len; ++i) {
            s[i] = (char)('a' + (int)(rng() % (unsigned long long)alph));
        }
        if (mode == 1) {
            for (int i = 0; i < len / 2; ++i) s[len - 1 - i] = s[i];
        }
        if (mode == 2 && len >= 2) {
            for (int i = 0; i < len / 2; ++i) s[len - 1 - i] = s[i];
            int p = len / 2 - 1;
            char c = s[p];
            while (c == s[p]) c = (char)('a' + (int)(rng() % 26));
            s[p] = c;
        }
        if (mode == 3) {
            char c = (char)('a' + (int)(rng() % 2));
            s.assign(len, c);
        }

        {
            ofstream in("case.in", ios::binary);
            in << s << "\n";
        }

        string cmd = mainExe + " < case.in > main.out";
        if (system(cmd.c_str()) != 0) {
            cerr << "main crashed at round " << t << "\n";
            return 2;
        }
        cmd = bruteExe + " < case.in > brute.out";
        if (system(cmd.c_str()) != 0) {
            cerr << "brute crashed at round " << t << "\n";
            return 2;
        }

        string x, y;
        {
            ifstream a("main.out");
            ifstream b("brute.out");
            a >> x;
            b >> y;
        }
        if (x != y) {
            cerr << "MISMATCH round " << t << " len=" << s.size() << " input=" << s
                 << " main=" << x << " brute=" << y << "\n";
            ofstream bad("failing-case.txt", ios::binary);
            bad << s << "\n";
            return 1;
        }
    }

    cout << "OK " << rounds << " rounds\n";
    return 0;
}
