#include <bits/stdc++.h>
using namespace std;

int opl(vector<int>& pages, int size) {
    vector<int> frame;
    int Q = 0;

    for (int i = 0; i < pages.size(); ++i) {
        auto it = find(frame.begin(), frame.end(), pages[i]);
        if (it == frame.end()) {
            Q++;
            if (frame.size() == size) {
                int farthest = -1, val_ind;
                for (int j = 0; j < frame.size(); j++) {
                    int k;
                    for (k = i + 1; k < pages.size(); k++) {d
                        if (frame[j] == pages[k]) break;
                    }
                    if (k > farthest) {
                        farthest = k;
                        val_ind = j;
                    }
                }
                frame.erase(frame.begin() + val_ind);
            }
            frame.push_back(pages[i]);
        }
    }
    return Q;
}

int main() {
    int N, M, Q;
    while (cin >> N >> M >> Q) {
        vector<int> pages(Q);
        for (int i = 0; i < Q; ++i) {
            cin >> pages[i];
        }
        int faults = opl(pages, N);
        cout << faults << endl;
    }
    return 0;
}
