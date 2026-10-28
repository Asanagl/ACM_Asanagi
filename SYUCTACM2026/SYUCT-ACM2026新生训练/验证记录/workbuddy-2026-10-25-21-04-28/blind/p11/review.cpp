// 矩阵原样输出
// 读入 n, m，随后按行读入 n*m 个整数并按行原样输出（行间空格、行尾换行，不输出 n m）。
// 独立设计，仅用标准库。
#include <cstdio>
#include <cstdlib>

namespace io {
    const int BUFSZ = 1 << 16;
    char ibuf[BUFSZ];
    int ipos = 0, ilen = 0;

    inline int rc() {
        if (ipos == ilen) {
            ilen = (int)fread(ibuf, 1, BUFSZ, stdin);
            ipos = 0;
            if (ilen <= 0) return -1;
        }
        return (unsigned char)ibuf[ipos++];
    }

    // 读一个整数；成功返回 true
    inline bool readInt(int &out) {
        int c = rc();
        while (c != -1 && (c == ' ' || c == '\n' || c == '\r' || c == '\t')) c = rc();
        if (c == -1) return false;
        bool neg = false;
        if (c == '-') { neg = true; c = rc(); }
        else if (c == '+') { c = rc(); }
        long long v = 0;
        while (c >= '0' && c <= '9') {
            v = v * 10 + (c - '0');
            c = rc();
        }
        // c 此时为分隔符或 EOF，已从缓冲中消费，无需回退
        out = (int)(neg ? -v : v);
        return true;
    }

    char obuf[BUFSZ];
    int opos = 0;

    inline void flushOut() {
        if (opos) { fwrite(obuf, 1, opos, stdout); opos = 0; }
    }

    inline void wc(char ch) {
        if (opos == BUFSZ) flushOut();
        obuf[opos++] = ch;
    }

    inline void writeInt(int x) {
        if (x == 0) { wc('0'); return; }
        char tmp[12];
        int len = 0;
        unsigned int v;
        bool neg = x < 0;
        // 用 unsigned 处理 -2147483648 之类的极端值
        v = neg ? (unsigned int)(-(long long)x) : (unsigned int)x;
        while (v) { tmp[len++] = (char)('0' + (int)(v % 10u)); v /= 10u; }
        if (neg) wc('-');
        while (len) wc(tmp[--len]);
    }
} // namespace io

int main() {
    int n = 0, m = 0;
    if (!io::readInt(n) || !io::readInt(m)) {           // 非法输入保护（题目保证不会发生）
        return 0;
    }

    // 逐行读取并逐行输出，只需保存当前行，空间 O(m)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x = 0;
            if (!io::readInt(x)) {                      // 数据不足时按 0 补（题目保证不会发生）
                x = 0;
            }
            if (j) io::wc(' ');
            io::writeInt(x);
        }
        io::wc('\n');
    }

    io::flushOut();
    return 0;
}
