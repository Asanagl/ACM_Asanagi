#include "testlib.h"

#include <string>

// testlib 的 strict 模式在 Windows 上只接受 CRLF 行尾，而题面与生成器使用 LF。
// 这里按字节显式读取行尾，使 LF、CRLF 以及末行没有换行符三种输入都合法。
static void consumeEol(InStream &stream, const char *where) {
    if (stream.eof()) {
        return;
    }
    const int first = static_cast<unsigned char>(stream.readChar());
    if (first == '\r') {
        stream.ensuref(!stream.eof(), "%s: CR must be followed by LF", where);
        stream.ensuref(static_cast<unsigned char>(stream.readChar()) == '\n',
                       "%s: CR must be followed by LF", where);
        return;
    }
    stream.ensuref(first == '\n', "%s: expected LF or CRLF, found byte %d", where, first);
}

static void validateStringLine(InStream &stream) {
    int length = 0;
    for (;;) {
        if (stream.eof()) {
            break;
        }
        const int c = static_cast<unsigned char>(stream.readChar());
        if (c == '\n') {
            break;
        }
        if (c == '\r') {
            stream.ensuref(!stream.eof(), "s: CR must be followed by LF");
            stream.ensuref(static_cast<unsigned char>(stream.readChar()) == '\n',
                           "s: CR must be followed by LF");
            break;
        }
        stream.ensuref(c >= 'a' && c <= 'z',
                       "s: expected lowercase English letters only, found byte %d at position %d",
                       c, length + 1);
        ++length;
        stream.ensuref(length <= 100000, "s: must contain at most 100000 characters, found more");
    }
    stream.ensuref(length >= 1, "s: must contain at least one character");
}

static char readLetter(InStream &stream, const char *name) {
    stream.ensuref(!stream.eof(), "%s: unexpected end of file", name);
    const int c = static_cast<unsigned char>(stream.readChar());
    stream.ensuref(c >= 'a' && c <= 'z',
                   "%s: expected a lowercase English letter, found byte %d", name, c);
    return static_cast<char>(c);
}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    validateStringLine(inf);

    readLetter(inf, "x");
    inf.ensuref(!inf.eof(), "x: expected one space followed by y");
    inf.ensuref(static_cast<unsigned char>(inf.readChar()) == ' ',
                "x: expected exactly one space between x and y");
    readLetter(inf, "y");

    consumeEol(inf, "y");
    inf.readEof();
    return 0;
}
