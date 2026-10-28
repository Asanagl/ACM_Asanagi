#include "testlib.h"

#include <string>
#include <vector>

// 本题答案唯一，但 checker 不靠"逐字符比对答案"判定，而是直接验证合法性：
// 输出恰好 n 行、每行恰好 m 个字符且只含 'A'/'B'，相邻格异色，(1,1) 为 'A'。
// 由题面证明的唯一性，满足这些条件的棋盘必然等于标准答案，因此该 checker
// 与"比较唯一答案"等价，同时能在报错时给出更具体的信息。
// 对 jury 答案也做同样验证，防止 .ans 本身被写坏。

namespace {

std::string trimRight(const std::string& s) {
    std::size_t end = s.size();
    while (end > 0 && (s[end - 1] == ' ' || s[end - 1] == '\t' || s[end - 1] == '\r')) {
        --end;
    }
    return s.substr(0, end);
}

// ok 返回 true 表示这份输出完全合法；否则把原因写进 reason。
bool readAndValidate(InStream& stream, int n, int m, const char* who, std::string& reason) {
    std::vector<std::string> grid;
    grid.reserve(static_cast<std::size_t>(n));

    for (int i = 0; i < n; ++i) {
        std::string line;
        if (stream.eof()) {
            reason = std::string(who) + ": output ended early, expected " + std::to_string(n) + " lines";
            return false;
        }
        line = trimRight(stream.readLine());
        if (static_cast<int>(line.size()) != m) {
            reason = std::string(who) + ": line " + std::to_string(i + 1) + " has length " +
                     std::to_string(line.size()) + ", expected " + std::to_string(m);
            return false;
        }
        for (int j = 0; j < m; ++j) {
            if (line[j] != 'A' && line[j] != 'B') {
                reason = std::string(who) + ": line " + std::to_string(i + 1) + " column " +
                         std::to_string(j + 1) + " is '" + std::string(1, line[j]) + "', expected A or B";
                return false;
            }
        }
        grid.push_back(line);
    }

    if (!stream.seekEof()) {
        reason = std::string(who) + ": extra output after line " + std::to_string(n);
        return false;
    }

    if (grid[0][0] != 'A') {
        reason = std::string(who) + ": cell (1, 1) is '" + std::string(1, grid[0][0]) + "', expected 'A'";
        return false;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j > 0 && grid[i][j] == grid[i][j - 1]) {
                reason = std::string(who) + ": cells (" + std::to_string(i + 1) + ", " + std::to_string(j) +
                         ") and (" + std::to_string(i + 1) + ", " + std::to_string(j + 1) +
                         ") share the same colour";
                return false;
            }
            if (i > 0 && grid[i][j] == grid[i - 1][j]) {
                reason = std::string(who) + ": cells (" + std::to_string(i) + ", " + std::to_string(j + 1) +
                         ") and (" + std::to_string(i + 1) + ", " + std::to_string(j + 1) +
                         ") share the same colour";
                return false;
            }
        }
    }

    return true;
}

}  // namespace

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    const int n = inf.readInt(1, 1000, "n");
    const int m = inf.readInt(1, 1000, "m");
    inf.seekEof();
    inf.readEof();

    std::string reason;

    if (!readAndValidate(ans, n, m, "jury answer", reason)) {
        quitf(_fail, "invalid jury answer: %s", reason.c_str());
    }

    if (!readAndValidate(ouf, n, m, "participant output", reason)) {
        quitf(_wa, "%s", reason.c_str());
    }

    quitf(_ok, "accepted: %d x %d checkerboard", n, m);
}
