#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> matrix(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<int> mainDiagonal;
    vector<int> secondaryDiagonal;

    for (int i = 0; i < N; ++i) {
        mainDiagonal.push_back(matrix[i][i]);
        secondaryDiagonal.push_back(matrix[i][N - 1 - i]);
    }

    int max_Main = *max_element(mainDiagonal.begin(), mainDiagonal.end());
    int min_Main = *min_element(mainDiagonal.begin(), mainDiagonal.end());
    int max_Secondary = *max_element(secondaryDiagonal.begin(), secondaryDiagonal.end());
    int min_Secondary = *min_element(secondaryDiagonal.begin(), secondaryDiagonal.end());

    cout << max_Main << " " << min_Secondary << endl;

    return 0;
}
