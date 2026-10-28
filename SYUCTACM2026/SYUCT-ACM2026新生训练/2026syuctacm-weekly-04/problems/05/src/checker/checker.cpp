#include "testlib.h"

#include <string>

static std::string readAnswerLine(InStream &stream, const char *who) {
    const std::string line = stream.readLine();
    if (line.empty()) {
        quitf(_wa, "%s is empty", who);
    }
    if (line.size() > 100000) {
        quitf(_wa, "%s is too long: %d characters", who, static_cast<int>(line.size()));
    }
    for (size_t i = 0; i < line.size(); ++i) {
        if (line[i] < 'a' || line[i] > 'z') {
            quitf(_wa, "%s contains an invalid character at position %d",
                  who, static_cast<int>(i + 1));
        }
    }
    return line;
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    const std::string expected = readAnswerLine(ans, "jury answer");
    ans.readEof();

    const std::string actual = readAnswerLine(ouf, "participant output");
    if (!ouf.eof()) {
        quitf(_wa, "extra output after the answer line");
    }

    if (expected != actual) {
        quitf(_wa, "expected %s (length %d), found %s (length %d)",
              compress(expected).c_str(), static_cast<int>(expected.size()),
              compress(actual).c_str(), static_cast<int>(actual.size()));
    }

    quitf(_ok, "accepted");
}
