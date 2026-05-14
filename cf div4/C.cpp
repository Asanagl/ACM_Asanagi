#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



void solve()
{
    int n ;
    cin >> n ;
    vector<vector<long long>> index(2e8);
    vector<long long> res(n*n/2) ;
    vector<vector<int>> point(n,vector<int>(n)) ;
    for (int i  = 0; i < n; i++)
    {
        cin >> point[i][0] >>point[i][1] ;
    }
    int sum = 0;
    for (int i  = 0 ; i < n; i++)
    {
        for (int j  = i+1 ; j < n; j++)
        {
            res[sum]=abs(point[i][0]-point[j][0])+abs(point[i][1]-point[j][1]) ;
            index[i][j]=res[i+j];
            sum++;
        }

    }
    sort(res.begin(),res.end()) ;
    reverse(res.begin(),res.end()) ;


}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       solve();
    }

    return 0;
}
