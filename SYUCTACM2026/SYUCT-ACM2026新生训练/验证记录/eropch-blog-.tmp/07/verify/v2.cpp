#include "testlib.h"
#include <string>
int main(int argc,char*argv[]){
    registerValidation(argc,argv);
    std::string s = inf.readWord("[a-z]+", "s");
    inf.ensuref(s.size() >= 1u && s.size() <= 100000u, "bad length %d", (int)s.size());
    inf.seekEof();
    inf.readEof();
    return 0;
}
