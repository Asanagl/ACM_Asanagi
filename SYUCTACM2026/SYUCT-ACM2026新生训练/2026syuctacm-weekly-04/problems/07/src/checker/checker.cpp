#include "testlib.h"

#include <string>

namespace {

bool isAnswerWord(const std::string& token) {
    return token == "YES" || token == "NO";
}

}  // namespace

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    const std::string expected = ans.readWord();
    if (!isAnswerWord(expected)) {
        quitf(_fail, "jury answer is not YES/NO: \"%s\"", expected.c_str());
    }
    if (!ans.seekEof()) {
        quitf(_fail, "extra content after jury answer");
    }

    if (ouf.seekEof()) {
        quitf(_wa, "missing answer, expected exactly one word YES or NO");
    }

    const std::string actual = ouf.readWord();
    if (!isAnswerWord(actual)) {
        quitf(_wa, "answer must be exactly the uppercase word YES or NO, found \"%s\"",
              actual.c_str());
    }
    if (!ouf.seekEof()) {
        quitf(_wa, "unexpected extra content after \"%s\"", actual.c_str());
    }

    if (actual != expected) {
        quitf(_wa, "expected %s, found %s", expected.c_str(), actual.c_str());
    }

    quitf(_ok, "%s", actual.c_str());
}
