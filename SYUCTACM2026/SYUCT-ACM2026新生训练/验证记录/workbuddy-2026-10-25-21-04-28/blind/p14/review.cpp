// Problem: 每列的和 (column sums)
// Independent solution written from the public statement only.
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

namespace {

const int BUFSZ = 1 << 16;

inline bool readInt(long long &out) {
    static char buf[BUFSZ];
    static int pos = 0, len = 0;
    // refill helper
    auto refill = []() -> bool {
        len = (int)fread(buf, 1, BUFSZ, stdin);
        pos = 0;
        return len > 0;
    };
    // skip whitespace
    while (true) {
        while (pos < len && (buf[pos] == ' ' || buf[pos] == '\n' || buf[pos] == '\r' ||
                             buf[pos] == '\t' || buf[pos] == '\v' || buf[pos] == '\f'))
            ++pos;
        if (pos < len) break;
        if (!refill()) return false;
    }
    bool neg = false;
    if (buf[pos] == '-' || buf[pos] == '+') {
        neg = (buf[pos] == '-');
        ++pos;
        if (pos >= len && !refill()) return false;
    }
    long long val = 0;
    bool any = false;
    while (true) {
        while (pos < len && buf[pos] >= '0' && buf[pos] <= '9') {
            val = val * 10 + (buf[pos] - '0');
            ++pos;
            any = true;
        }
        if (pos < len) break;
        if (!refill()) break;
    }
    if (!any) return false;
    out = neg ? -val : val;
    return true;
}

} // namespace

int main() {
    long long n = 0, m = 0;
    if (!readInt(n) || !readInt(m)) return 0;

    std::vector<long long> col((size_t)m, 0LL);

    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < m; ++j) {
            long long x = 0;
            if (!readInt(x)) x = 0; // defensive; input is well-formed
            col[(size_t)j] += x;
        }
    }

    std::vector<char> out;
    out.reserve((size_t)m * 16 + 2);
    char tmp[32];
    for (long long j = 0; j < m; ++j) {
        if (j) out.push_back(' ');
        long long v = col[(size_t)j];
        bool neg = v < 0;
        unsigned long long u = neg ? (unsigned long long)(-(v + 1)) + 1ULL
                                   : (unsigned long long)v;
        int t = 0;
        if (u == 0) {
            tmp[t++] = '0';
        } else {
            while (u) {
                tmp[t++] = (char)('0' + (int)(u % 10ULL));
                u /= 10ULL;
            }
        }
        if (neg) out.push_back('-');
        while (t > 0) out.push_back(tmp[--t]);
    }
    out.push_back('\n');
    fwrite(out.data(), 1, out.size(), stdout);
    return 0;
}
