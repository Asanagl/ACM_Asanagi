#include <cstdio>
#include <vector>

namespace io {

constexpr int BUFSZ = 1 << 16;

char inbuf[BUFSZ];
int inpos = 0, inlen = 0;

inline int gc() {
    if (inpos == inlen) {
        inlen = (int)std::fread(inbuf, 1, BUFSZ, stdin);
        inpos = 0;
        if (inlen <= 0) return -1;
    }
    return (unsigned char)inbuf[inpos++];
}

bool readInt(long long& out) {
    int c = gc();
    while (c != -1 && (c < '0' || c > '9') && c != '-') c = gc();
    if (c == -1) return false;
    bool neg = false;
    if (c == '-') {
        neg = true;
        c = gc();
    }
    long long v = 0;
    while (c >= '0' && c <= '9') {
        v = v * 10 + (c - '0');
        c = gc();
    }
    out = neg ? -v : v;
    return true;
}

char outbuf[BUFSZ];
int outpos = 0;

inline void flushOut() {
    if (outpos > 0) {
        std::fwrite(outbuf, 1, (size_t)outpos, stdout);
        outpos = 0;
    }
}

inline void putChar(char ch) {
    if (outpos == BUFSZ) flushOut();
    outbuf[outpos++] = ch;
}

void writeInt(long long v) {
    if (v == 0) {
        putChar('0');
        return;
    }
    if (v < 0) {
        putChar('-');
        v = -v;
    }
    char tmp[24];
    int t = 0;
    while (v > 0) {
        tmp[t++] = (char)('0' + (int)(v % 10));
        v /= 10;
    }
    while (t > 0) putChar(tmp[--t]);
}

}  // namespace io

int main() {
    long long nll = 0, mll = 0;
    if (!io::readInt(nll) || !io::readInt(mll)) return 0;

    const int n = (int)nll;
    const int m = (int)mll;

    std::vector<int> a(static_cast<size_t>(n) * static_cast<size_t>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            long long v = 0;
            io::readInt(v);
            a[static_cast<size_t>(i) * static_cast<size_t>(m) +
              static_cast<size_t>(j)] = (int)v;
        }
    }

    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            const int i = n - 1 - c;
            const int j = r;
            if (c > 0) io::putChar(' ');
            io::writeInt(a[static_cast<size_t>(i) * static_cast<size_t>(m) +
                          static_cast<size_t>(j)]);
        }
        io::putChar('\n');
    }

    io::flushOut();
    return 0;
}
