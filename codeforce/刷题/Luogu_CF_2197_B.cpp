#include <bits/stdc++.h>
using namespace std ;
void Asanagi ()
{
    int n ;
    cin >> n ;
    vector <int> a (n+1) ;
    vector <int> b ;
    for (int i = 1 ; i <= n ; i++)
    cin >> a[i] ;
    for (int i = 1 ; i <= n ; i++)
    {
        int it  ;
        cin >> it ;
        if (i == 1) 
        b.push_back(it) ;
        else if (it != b.back())
        b.push_back(it) ;
    }
    int j = 0;
	for(int i = 1;i <= n && j < b.size();i ++){
		if(a[i] == b[j]){
			j ++;
		}
	}
	if(j == b.size()){
		cout << "YES" << endl ;
	}
	else{
		cout << "NO" << endl;
	}
    
}
int main ()
{
    int t ;
    cin >> t ;
    while (t--) 
    Asanagi ();
}