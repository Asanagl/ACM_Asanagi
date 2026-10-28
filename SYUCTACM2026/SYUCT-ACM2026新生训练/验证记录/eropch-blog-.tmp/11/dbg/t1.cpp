#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    cerr << "registered argc=" << argc << "\n";
    cerr << "argv1=" << (argc>1?argv[1]:"?") << " argv2=" << (argc>2?argv[2]:"?") << "\n";
    rnd.setSeed(atoll(argv[2]));
    cerr << "seed ok\n";
    cout << rnd.next(1,10) << "\n";
    return 0;
}
