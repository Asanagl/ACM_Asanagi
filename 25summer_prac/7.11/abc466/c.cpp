#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int ans = 0;
    int r = 0; 
    
    for (int i = 1; i <= N; ++i) {
        if (r < i) r = i;              
        while (r + 1 <= N) {
            cout << "? " << i << " " << r + 1 << endl; 
            string yon ;
            cin >> yon;
            if (yon == "Yes") {      
                ++r;
            } else {
                break;
            }
        }
        ans += r - i;                
    }
    cout << "! " << ans << endl;
    return 0;
}