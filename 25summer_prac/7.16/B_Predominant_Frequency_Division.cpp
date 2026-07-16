#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1e6 + 66;
int a[N], t, n, m, b;
string s;

int main()
{
	cin >> t;
	while(t --)
	{
		cin >> n;int now = 1, cnt = 0, lst = 1;
		for(int i = 1;i <= n;i ++) cin >> a[i];
		for(int i = 1;i <= n;i ++)
		{
			if(now > 3) continue;
			if(a[i] <= now) cnt ++;
			if(cnt >= i - lst + 1 - cnt && cnt > 0) 
			{
				if(a[i + 1] == 3 && cnt >= i - lst + 1 - cnt + 1 && now == 1) continue;
				lst = i + 1, now ++, cnt = 0;
			}
		}
		if(now >= 4) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
