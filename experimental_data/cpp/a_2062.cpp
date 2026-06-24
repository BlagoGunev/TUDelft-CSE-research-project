#include <bits/stdc++.h>
#define GO cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
typedef long long ll;
using namespace std;


int main()
{
    GO
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        int ans = 0;
        for(char& c : s) ans += c - '0';
        cout << ans << '\n';        
    }
    return 0;
}