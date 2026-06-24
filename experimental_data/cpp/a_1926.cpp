#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    for(; t; t--)
    {
        string s;
        cin >> s;
        
        int cnt = 0;
        for(int i = 0; i < s.size(); i++)
            cnt += (s[i] == 'A') - (s[i] == 'B');
        
        cout << (cnt > 0 ? "A" : "B") << '\n';
    }
    
    return 0;
}