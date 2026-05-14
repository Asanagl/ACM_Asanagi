#include <bits/stdc++.h>
using namespace std;
int n, k, cnt, a[25];

bool is_prime(int x) 
{
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) if (x % i == 0) return false;
    return true;
}

void dfs(int start, int sum, int step) 
{
    if (step == k) 
	{
        if (is_prime(sum)) cnt++;
        return;
    }
    for (int i = start; i <= n; i++) dfs(i + 1, sum + a[i], step + 1);
	return ; 
}

int main() 
{
    cin >> n >> k; 
    for (int i = 1; i <= n; i++) cin >> a[i];
    dfs(1, 0, 0);
    cout << cnt << endl;
    return 0;
}
