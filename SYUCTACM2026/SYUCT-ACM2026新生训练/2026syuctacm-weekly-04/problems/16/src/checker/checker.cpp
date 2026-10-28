#include "testlib.h"

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    // 答案文件（由主解产生）中的两个整数
    const long long expectedMain = ans.readLong();
    const long long expectedAnti = ans.readLong();
    ans.seekEof();
    ans.readEof();

    // 选手输出：必须恰好两个整数，缺项 / 多项都判错
    const long long actualMain = ouf.readLong();
    const long long actualAnti = ouf.readLong();
    ouf.seekEof();
    ouf.readEof();

    if (actualMain != expectedMain) {
        quitf(_wa, "main diagonal sum: expected %lld, found %lld",
              expectedMain, actualMain);
    }
    if (actualAnti != expectedAnti) {
        quitf(_wa, "anti diagonal sum: expected %lld, found %lld",
              expectedAnti, actualAnti);
    }

    quitf(_ok, "accepted");
}
