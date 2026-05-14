#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long

const string INC = "inc";
const string DEC = "dec";
const string NCINC = "ncinc";
const string NCDEC = "ncdec";

bool ncinc_cmp(const string& a, const string& b) {
    return lexicographical_compare(
        a.begin(), a.end(),
        b.begin(), b.end(),
        [](char c1, char c2) {
            return tolower(static_cast<unsigned char>(c1)) < 
                   tolower(static_cast<unsigned char>(c2));}
    );
}

bool ncdec_cmp(const string& a, const string& b) {
    return ncinc_cmp(b, a);
}

void solve() 
{
    string cmp_name;
    cin >> cmp_name;
    
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; ++i) {
        cin >> strs[i];
    }
    if (cmp_name == INC) {
        sort(strs.begin(), strs.end());
    } else if (cmp_name == DEC) {
        sort(strs.begin(), strs.end(), greater<string>());
    } else if (cmp_name == NCINC) {
        sort(strs.begin(), strs.end(), ncinc_cmp);
    } else if (cmp_name == NCDEC) {
        sort(strs.begin(), strs.end(), ncdec_cmp);
    }
    for (const string& s : strs) {
        cout << s << endl;
    }
}

signed main() {
    IOS;
    solve();  
    return 0;
}