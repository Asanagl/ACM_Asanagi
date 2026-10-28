#include <bits/stdc++.h>
using namespace std ;
int main ()
{
    int t ;
    cin >> t ;
    while (t--)
    {
        unordered_map<string , int> ump ;
        ump["WrongProblemA"] = 100 ;ump["WrongProblemB"] = 100 ;ump["WrongProblemC"] = 100 ;
        ump["WrongProblemD"] = 100 ;ump["WrongProblemE"] = 100 ;ump["WrongProblemF"] = 100 ;
        ump["WrongProblemG"] = 100 ;ump["WrongProblemH"] = 100 ;ump["WrongProblemI"] = 100 ;
        ump["WrongProblemJ"] = 100 ;ump["WrongProblemK"] = 100 ;ump["WrongProblemL"] = 100 ;
        ump["SameProblemA"] = 30 ;ump["SameProblemB"] = 30 ;ump["SameProblemC"] = 30 ;
        ump["SameProblemD"] = 30 ;ump["SameProblemE"] = 30 ;ump["SameProblemF"] = 30 ;
        ump["SameProblemG"] = 30 ;ump["SameProblemH"] = 30 ;ump["SameProblemI"] = 30 ;
        ump["SameProblemJ"] = 30 ;ump["SameProblemK"] = 30 ;ump["SameProblemL"] = 30 ;
        ump["BadProblemA"] = 1 ;ump["BadProblemB"] = 1 ;ump["BadProblemC"] = 1 ;
        ump["BadProblemD"] = 1 ;ump["BadProblemE"] = 1 ;ump["BadProblemF"] = 1 ;
        ump["BadProblemG"] = 1 ;ump["BadProblemH"] = 1 ;ump["BadProblemI"] = 1 ;
        ump["BadProblemJ"] = 1 ;ump["BadProblemK"] = 1 ;ump["BadProblemL"] = 1 ;
        ump["UnreasonableLimitForProblemA"] = 5 ;ump["UnreasonableLimitForProblemB"] = 5 ;ump["UnreasonableLimitForProblemC"] = 5 ;
        ump["UnreasonableLimitForProblemD"] = 5 ;ump["UnreasonableLimitForProblemE"] = 5 ;ump["UnreasonableLimitForProblemF"] = 5 ;
        ump["UnreasonableLimitForProblemG"] = 5 ;ump["UnreasonableLimitForProblemH"] = 5 ;ump["UnreasonableLimitForProblemI"] = 5 ;
        ump["UnreasonableLimitForProblemJ"] = 5 ;ump["UnreasonableLimitForProblemK"] = 5 ;ump["UnreasonableLimitForProblemL"] = 5 ;
        ump["WeakTestsForProblemA"] = 3 ;ump["WeakTestsForProblemB"] = 3 ;ump["WeakTestsForProblemC"] = 3 ;
        ump["WeakTestsForProblemD"] = 3 ;ump["WeakTestsForProblemE"] = 3 ;ump["WeakTestsForProblemF"] = 3 ;
        ump["WeakTestsForProblemG"] = 3 ;ump["WeakTestsForProblemH"] = 3 ;ump["WeakTestsForProblemI"] = 3 ;
        ump["WeakTestsForProblemJ"] = 3 ;ump["WeakTestsForProblemK"] = 3 ;ump["WeakTestsForProblemL"] = 3 ;
        ump["UnreasonableProblemArrangement"] = 10 ;
        int n , p ;
        cin >> n >> p ;
        int ans = 0 ;
        while (n--)
        {
            string s ;
            cin >> s ;
            ans += ump[s] ;
        }
        if (ans > p ) cout << "Joker" << endl ;
        else cout << "Judger" << endl ;
    }
}


/*
WrongProblemX	100
SameProblemX	30
BadProblemX     1
UnreasonableLimitForProblemX	5
WeakTestsForProblemX 3

UnreasonableProblemArrangement	10	
*/
// A B C D E F G H I J K L
