#include <cstdio>
#include <cctype>

namespace io {
    static const int BUFSZ = 1 << 16;
    char buf[BUFSZ];
    int len = 0, pos = 0;

    inline int gc() {
        if (pos == len) {
            len = (int)std::fread(buf, 1, BUFSZ, stdin);
            pos = 0;
            if (len <= 0) return -1;
        }
        return (unsigned char)buf[pos++];
    }

    inline bool readInt(long long &out) {
        int c = gc();
        while (c != -1 && !(c == '-' || (c >= '0' && c <= '9'))) c = gc();
        if (c == -1) return false;
        bool neg = false;
        if (c == '-') { neg = true; c = gc(); }
        long long v = 0;
        while (c >= '0' && c <= '9') {
            v = v * 10 + (c - '0');
            c = gc();
        }
        out = neg ? -v : v;
        return true;
    }
}

static char outbuf[1 << 16];
static int outlen = 0;

static inline void flushOut() {
    if (outlen > 0) { std::fwrite(outbuf, 1, outlen, stdout); outlen = 0; }
}

static inline void putChar(char c) {
    if (outlen == (1 << 16)) flushOut();
    outbuf[outlen++] = c;
}

static inline void writeInt(long long v) {
    if (v == 0) { putChar('0'); putChar('\n'); return; }
    if (v < 0) { putChar('-'); v = -v; }
    char tmp[24];
    int t = 0;
    while (v > 0) { tmp[t++] = (char)('0' + (int)(v % 10)); v /= 10; }
    while (t > 0) putChar(tmp[--t]);
    putChar('\n');
}

int main() {
    long long n = 0, m = 0;
    if (!io::readInt(n) || !io::readInt(m)) return 0;
    if (n <= 0 || m <= 0) return 0;

    for (long long i = 0; i < n; ++i) {
        long long sum = 0;
        for (long long j = 0; j < m; ++j) {
            long long x = 0;
            if (!io::readInt(x)) { x = 0; }
            sum += x;
        }
        writeInt(sum);
    }
    flushOut();
    return 0;
}
