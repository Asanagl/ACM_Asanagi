#include "testlib.h"
#include <string>
int main(int argc,char*argv[]){
    registerValidation(argc,argv);
    std::string s = inf.readLine();
    fprintf(stderr,"got [%s] len=%d\n", s.c_str(), (int)s.size());
    inf.readEof();
    return 0;
}
