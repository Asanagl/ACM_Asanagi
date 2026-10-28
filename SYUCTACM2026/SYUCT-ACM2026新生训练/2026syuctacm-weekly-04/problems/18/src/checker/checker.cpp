#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

namespace {

[[noreturn]] void badLine(int line, const string &detail) {
    quitf(_wa, "line %d: %s", line, detail.c_str());
}

// Parses a token that must be exactly an optional '-' followed by digits, with
// a value inside the range guaranteed by the statement.
long long parseValue(const string &token, int line, int column) {
    const size_t start = 0;
    size_t pos = start;
    bool negative = false;
    if (pos < token.size() && token[pos] == '-') {
        negative = true;
        ++pos;
    }
    if (pos >= token.size()) {
        badLine(line, "column " + to_string(column) + ": expected an integer, found \"" + token + "\"");
    }
    long long value = 0;
    const size_t digitsBegin = pos;
    while (pos < token.size()) {
        const char c = token[pos];
        if (c < '0' || c > '9') {
            badLine(line, "column " + to_string(column) + ": expected an integer, found \"" + token + "\"");
        }
        value = value * 10 + (c - '0');
        ++pos;
    }
    if (pos == digitsBegin) {
        badLine(line, "column " + to_string(column) + ": expected an integer, found \"" + token + "\"");
    }
    if (pos - digitsBegin > 11) {
        badLine(line, "column " + to_string(column) + ": integer is out of range");
    }
    if (negative) {
        value = -value;
    }
    if (value < -1000000000LL || value > 1000000000LL) {
        badLine(line, "column " + to_string(column) + ": integer " + token + " is out of range");
    }
    return value;
}

// Splits one line (already stripped of its line terminator) into tokens.
// The line must be exactly n tokens separated by exactly one space each.
vector<long long> parseLine(const string &line, int n, int lineNumber) {
    vector<long long> values;
    values.reserve(static_cast<size_t>(n));
    if (line.empty()) {
        badLine(lineNumber, "the line is empty, expected " + to_string(n) + " integers");
    }
    if (line.front() == ' ') {
        badLine(lineNumber, "leading space is not allowed");
    }
    if (line.back() == ' ') {
        badLine(lineNumber, "trailing space is not allowed");
    }
    if (line.find('\t') != string::npos) {
        badLine(lineNumber, "tab characters are not allowed");
    }
    size_t begin = 0;
    while (true) {
        const size_t space = line.find(' ', begin);
        const string token = (space == string::npos) ? line.substr(begin) : line.substr(begin, space - begin);
        if (token.empty()) {
            badLine(lineNumber, "two integers are separated by more than one space");
        }
        const int column = static_cast<int>(values.size()) + 1;
        values.push_back(parseValue(token, lineNumber, column));
        if (space == string::npos) {
            break;
        }
        begin = space + 1;
    }
    if (static_cast<int>(values.size()) != n) {
        badLine(lineNumber, "expected exactly " + to_string(n) + " integers, found " +
                                to_string(values.size()));
    }
    return values;
}

}  // namespace

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    // 本 checker 为了逐字节校验行结构，直接用 ifstream 读 argv[2]。
    // testlib 内部的 ouf 流因此完全没被消费，而 testlib 在 _ok / _wa 退出前会检查
    // ouf 是否还有剩余数据（dirt 检查），未消费会被误报成
    // "Extra information in the output file" 并给出 _dirt。这里先把 ouf 推到 EOF。
    while (!ouf.eof()) {
        ouf.readChar();
    }

    // ---- Input (re-read strictly; the data is validator approved) ----
    const int n = inf.readInt(1, 100, "n");
    inf.readSpace();
    const int m = inf.readInt(1, 100, "m");
    inf.readEoln();

    vector<long long> a(static_cast<size_t>(n) * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[static_cast<size_t>(i) * m + j] = inf.readLong(-1000000000LL, 1000000000LL, "a_ij");
            if (j + 1 < m) {
                inf.readSpace();
            } else {
                inf.readEoln();
            }
        }
    }
    inf.readEof();

    // ---- Reference answer: must itself be the transpose ----
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            const long long expected = a[static_cast<size_t>(i) * m + j];
            const long long given = ans.readLong(-1000000000LL, 1000000000LL, "b_ji");
            if (given != expected) {
                quitf(_fail, "official answer mismatch at row %d, column %d", j + 1, i + 1);
            }
        }
    }
    ans.seekEof();
    ans.readEof();

    // ---- Contestant output: raw bytes, strict line layout ----
    if (argc < 3) {
        quitf(_fail, "usage: checker <input> <output> <answer>");
    }
    ifstream outFile(argv[2], ios::binary);
    if (!outFile) {
        quitf(_fail, "cannot open contestant output file: %s", argv[2]);
    }
    const string data((istreambuf_iterator<char>(outFile)), istreambuf_iterator<char>());
    outFile.close();

    vector<string> lines;
    size_t begin = 0;
    while (begin < data.size()) {
        const size_t newline = data.find('\n', begin);
        if (newline == string::npos) {
            quitf(_wa, "line %d: missing newline; every line, including the last one, must end with a newline",
                  static_cast<int>(lines.size()) + 1);
        }
        size_t end = newline;
        if (end > begin && data[end - 1] == '\r') {
            --end;
        }
        lines.push_back(data.substr(begin, end - begin));
        begin = newline + 1;
    }
    if (begin != data.size()) {
        quitf(_wa, "unexpected trailing bytes");
    }
    if (static_cast<int>(lines.size()) != m) {
        quitf(_wa, "expected exactly %d lines, found %d", m, static_cast<int>(lines.size()));
    }

    for (int j = 0; j < m; ++j) {
        const vector<long long> row = parseLine(lines[static_cast<size_t>(j)], n, j + 1);
        for (int i = 0; i < n; ++i) {
            const long long expected = a[static_cast<size_t>(i) * m + j];
            if (row[static_cast<size_t>(i)] != expected) {
                quitf(_wa, "row %d, column %d: expected %lld, found %lld",
                      j + 1, i + 1, expected, row[static_cast<size_t>(i)]);
            }
        }
    }

    quitf(_ok, "accepted");
}
