#include "testlib.h"
#include <string>
int main(int argc,char*argv[]){
    registerValidation(argc,argv);
    inf.strict = false;
    std::string s = inf.readLine();
    inf.ensuref(!s.empty(), "empty");
    inf.ensuref(s.size() <= 100000u, "too long %d", (int)s.size());
    for (size_t i=0;i<s.size();++i) inf.ensuref(s[i]>='a'&&s[i]<='z', "bad char at %d", (int)i);
    inf.readEof();
    return 0;
}
