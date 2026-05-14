#include <bits/stdc++.h>
using namespace std ;
int main ()
{
	unordered_map <char , int> ump ;
	set <char> st ;
	char ch ;
	while(!cin >> ch)
	{
		st.insert(ch) ;
		ump[ch]++ ;
	}
	for (auto &it : st)
	{
		cout << it << ':' << ump[it] << endl  ;
	}
}
