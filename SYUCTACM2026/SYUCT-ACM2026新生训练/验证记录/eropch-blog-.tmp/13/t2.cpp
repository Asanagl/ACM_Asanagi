#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    fprintf(stderr, "ok argc=%d\n", argc);
    cout << rnd.next(1,100) << "\n";
    return 0;
}
