#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int>& x, const pair<int, int>& y)
{
    return x.second > y.second;
}

void solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> messages(n);
    long long totalA = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> messages[i].first >> messages[i].second;
        totalA += messages[i].first;
    }

    sort(messages.begin(), messages.end(), compare);

    long long loss = 0;
    for (int i = 0; i < n; i++)
    {
        loss += static_cast<long long>(messages[i].second) * i;
    }
    for (int i = 0; i < n; i++)
    {
        int
    }

    cout << totalA - loss << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}
