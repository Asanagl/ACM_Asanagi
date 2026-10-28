#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    int hour = 9, minute = 5;
    printf("%02d:%02d\n", hour, minute);                 // 09:05
    cout << setw(2) << setfill('0') << hour << ':'
         << setw(2) << setfill('0') << minute << '\n';   // 09:05

    int rank = 7;
    printf("%03d\n", rank);                              // 007
    cout << setw(3) << setfill('0') << rank << '\n';     // 007
    return 0;
}
