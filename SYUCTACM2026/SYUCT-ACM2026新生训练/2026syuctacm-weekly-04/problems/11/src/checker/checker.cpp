#include "testlib.h"

#include <cctype>
#include <string>
#include <vector>

namespace {

class OutputParser {
public:
    OutputParser(InStream& stream, int rows, int columns, bool jury)
        : stream_(stream), rows_(rows), columns_(columns), jury_(jury) {}

    void parseAndCompare(const std::vector<std::vector<int>>& matrix) {
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < columns_; ++j) {
                const std::string expected = std::to_string(matrix[i][j]);
                const std::string found = readIntegerToken(i, j);
                if (found != expected) {
                    fail("row " + std::to_string(i + 1) + ", column " + std::to_string(j + 1) +
                         ": expected " + expected + ", found " + found);
                }
                if (j + 1 < columns_) {
                    readSingleSpace(i, j);
                }
            }
            readLineBreak(i);
        }
        if (!stream_.eof()) {
            fail("extra output after row " + std::to_string(rows_));
        }
    }

private:
    [[noreturn]] void fail(const std::string& message) const {
        quitf(jury_ ? _fail : _wa, "%s", message.c_str());
    }

    bool atEnd() {
        return stream_.eof();
    }

    std::string readIntegerToken(int row, int column) {
        if (atEnd()) {
            fail("row " + std::to_string(row + 1) + ", column " + std::to_string(column + 1) +
                 ": expected an integer, but output ended");
        }
        std::string token;
        char current = stream_.curChar();
        if (current == '-') {
            token.push_back(stream_.readChar());
        }
        const std::size_t digitsBefore = token.size();
        while (!atEnd() && std::isdigit(static_cast<unsigned char>(stream_.curChar()))) {
            token.push_back(stream_.readChar());
        }
        if (token.size() == digitsBefore) {
            fail("row " + std::to_string(row + 1) + ", column " + std::to_string(column + 1) +
                 ": expected an integer");
        }
        return token;
    }

    void readSingleSpace(int row, int column) {
        if (atEnd() || stream_.curChar() != ' ') {
            fail("row " + std::to_string(row + 1) + ": expected exactly one space after column " +
                 std::to_string(column + 1));
        }
        stream_.readChar();
        if (!atEnd() && stream_.curChar() == ' ') {
            fail("row " + std::to_string(row + 1) + ": expected exactly one space after column " +
                 std::to_string(column + 1) + ", found several");
        }
    }

    void readLineBreak(int row) {
        if (!atEnd() && stream_.curChar() == '\r') {
            stream_.readChar();
        }
        if (atEnd() || stream_.curChar() != '\n') {
            fail("row " + std::to_string(row + 1) +
                 ": expected exactly one line break after the last column");
        }
        stream_.readChar();
    }

    InStream& stream_;
    int rows_;
    int columns_;
    bool jury_;
};

}  // namespace

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    const int n = inf.readInt(1, 100, "n");
    inf.readSpace();
    const int m = inf.readInt(1, 100, "m");
    inf.readEoln();

    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = inf.readInt(-1000, 1000, "a[i][j]");
            if (j + 1 < m) {
                inf.readSpace();
            }
        }
        inf.readEoln();
    }
    inf.readEof();

    OutputParser(ans, n, m, true).parseAndCompare(matrix);
    OutputParser(ouf, n, m, false).parseAndCompare(matrix);

    quitf(_ok, "accepted: %d x %d matrix reproduced exactly", n, m);
}
