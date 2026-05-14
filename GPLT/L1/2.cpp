#include <bits/stdc++.h>
using namespace std ;
int main ()
{
	int n ;
	cin >> n ;
	char ch ;
	cin >> ch ;
	vector <int> v (1000);
	v[1] = 1 ;
	v[2] = 7 ;
	int a = 7 ;
	for (int i = 3 ; a>=1000 ; i++)
	{
		a+=(i+2)*2 ;
		v[i] = a ;
	}
}
