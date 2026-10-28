#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    int hour = 9, minute = 5;
    printf("%02d:%02d\n", hour, minute);
    cout << setw(2) << setfill('0') << hour << ':'
         << setw(2) << setfill('0') << minute << '\n';

    int rank = 7;
    printf("%03d\n", rank);
    cout << setw(3) << setfill('0') << rank << '\n';
    cout << flush;
    return 0;
}
