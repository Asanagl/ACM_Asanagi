#include <iostream>
using namespace std;

int g = 10;   // 全局变量

int main()
{
    cout << g << '\n';
    int g = 20;
    cout << g << '\n';
    {
        int g = 30;
        cout << g << '\n';
    }
    cout << g << '\n';
    return 0;
}
